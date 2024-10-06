#include<bits/stdc++.h>
using namespace std;

map<string,string> blocks;
void create_dictionary(int block_sz){
    ifstream input("./subPoly.txt",ios::in);
    string key,val,text;

    while(getline(input,text)){
        key = text.substr(0,block_sz);
        val = text.substr(block_sz+1,block_sz);
        blocks[key] = val;
    }
    input.close();
}

string encryptPoly(string text,int block_sz){
    string block,ciphertxt;
    int i;

    for(i=0;i<text.size();i += block_sz){
        block = text.substr(i,block_sz);
        ciphertxt += (!blocks[block].empty())? blocks[block]:block;
    }
    return ciphertxt;
}
string decryptPoly(string ciphertxt,int block_sz){
    string block,text;
    int i,j;

    for(i=0;i<ciphertxt.size();i += block_sz){
        block ="";
        for(j=0;j<block_sz&&i+j<ciphertxt.size();j++)
            block += ciphertxt[i+j];
        auto itr=blocks.find(block);
        text += (itr != blocks.end())? itr->first:block;
    }
    return text;
}

int main(){
    string text,tmp,encPoly,decPoly;
    int block_sz=3;
    
    ifstream in("./inPoly.txt",ios::in);
    create_dictionary(block_sz);

    while(getline(in,tmp)){
        text += tmp;
    }

    encPoly=encryptPoly(text,block_sz);
    decPoly=decryptPoly(text,block_sz);

    cout<<"Plaintext: "<<text<<endl;
    cout<<"Cipher: "<<encPoly<<endl;
    cout<<"Decrypted: "<<decPoly<<endl;

    in.close();
    return 0;
}