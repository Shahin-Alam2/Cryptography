#include<bits/stdc++.h>

using namespace std;

map <string,string> blocks;

void create_dictionary(int block_sz){
    ifstream input("./subPoly.txt",ios::in);
    char ch;
    string key,val,text;
    bool flag=true;

    while(getline(input,text)){
        key=text.substr(0,block_sz);
        val=text.substr(block_sz+1,block_sz);
        blocks[key]=val;
    }
    input.close();
}

string encryptPoly(string text,int block_sz){
    int i,j;
    string block,ciphertxt;
    cout<<text<<endl;

    for(i=0;i<text.size();i += block_sz){
        block = text.substr(i,block_sz);
        ciphertxt += (!blocks[block].empty())? blocks[block] : block;
    }

    return ciphertxt;
}
string decryptPoly(string ciphertxt,int block_sz){
    int i,j;
    string text,block;

    for(i=0;i<ciphertxt.size();i += block_sz){
        block = "";
        for(j=0;j<block_sz && i+j < ciphertxt.size();j++)
            block += ciphertxt[i+j];
        auto itr = blocks.find(block);
        text += (itr != blocks.end())? itr->first : block;
    }

    return text;
}

int main(){
    int block_sz=3;
    string text,encText,decText,tmp;
    char ch;
    ifstream in("./inPoly.txt",ios::in);

    create_dictionary(block_sz);
    while(getline(in,tmp)){
        text += tmp;
    }

    encText=encryptPoly(text,block_sz);
    decText=decryptPoly(text,block_sz);

    cout<<"Input Text: "<<text<<endl;
    cout<<"Block size: "<<block_sz<<endl;
    cout<<"Encrypted msg: "<<encText<<endl;
    cout<<"Decrypted msg: "<<decText<<endl;

    in.close();

    return 0;
}