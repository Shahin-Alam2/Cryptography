#include<bits/stdc++.h>
using namespace std;

string encryptTran(string text,int width){
    int i,msgLen=text.size();
    int col=msgLen/width, rem=msgLen%width,x=0,y=0;
    string result=text;

    for(i=0;i<msgLen;i++){
        if(i%width==0)
            x=y,y++;
        else if(i%width<=rem)
            x += 1;
        result[x] = text[i];
        x += col;
    }
    return result;
}
string decryptTran(string text,int width){
    int i,msgLen=text.size();
    int col=msgLen/width, rem=msgLen%width,x=0,y=0;
    string result=text;

    for(i=0;i<msgLen;i++){
        if(i%width==0)
            x=y,y++;
        else if(i%width <= rem)
            x += 1;
        result[i]=text[x];
        x += col;
    }
    return result;
}

int main(){
    string text,encTran,decTran;
    int width=5;

    ifstream in("./inTran.txt",ios::in);
    getline(in,text);

    encTran=encryptTran(text,width);
    decTran=decryptTran(encTran,width);

    cout<<"Plaintext: "<<text<<endl;
    cout<<"Encrypted: "<<encTran<<endl;
    cout<<"Decrypted: "<<decTran<<endl;


    return 0;
}