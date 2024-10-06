#include <bits/stdc++.h>

using namespace std;

string encryptCaesar(string text,int shift){
    string result;
    for(auto &i : text){
        if(i>='A' && i<='Z')
        result += (i-'A'+shift)%26+'A';
        else if(i>='a' && i<='z')
        result += (i-'a'+shift)%26+'a';
        else
        result += i;
    }
    return result;
}
string encryptTrans(string transMsg,int width){
    int msgLen=transMsg.size();
    int col=msgLen/width,rem=msgLen%width,x=0,y=0;
    string result=transMsg;
    for(int i=0;i<msgLen;i++){
        if(i%width==0)
            x=y,y++;
        else if(i%width<=rem)
            x += 1;
        result[x]=transMsg[i];
        x += col;
    }
    return result;
}

string decryptTrans(string encTrans,int width){
    int msgLen=encTrans.size();
    int col=msgLen/width,rem=msgLen%width,x=0,y=0;
    string result=encTrans;
    for(int i=0;i<msgLen;i++){
        if(i%width==0)
            x=y,y++;
        else if (i%width<=rem)
            x += 1;
        result[i]=encTrans[x];
        x += col;
    }
    return result;
}
string decryptCaesar(string encText,int shift){
    string result;
    for(auto &i:encText){
        if(i>='A' && i<='Z')
        result += (i-'A'-shift+26)%26+'A';
        else if(i>='a' && i<='z')
        result += (i-'a'-shift+26)%26+'a';
        else
        result += i;
    }
    return result;
}


int main(){
    int shift=3,width=5;
    string text,encCaesar,decCaesar,encTrans,decTrans;

    //text="Computer Science";
    getline(cin,text);
    encCaesar=encryptCaesar(text,shift);
    encTrans=encryptTrans(encCaesar,width);
    decTrans=decryptTrans(encTrans,width);
    decCaesar=decryptCaesar(decTrans,shift);


    cout<<"Text: "<<text<<endl;
    cout<<"Encrypted Caesar: "<<encCaesar<<endl;
    cout<<"Transposition: "<<encTrans<<endl;
    cout<<"Decrypted Transposition: "<<decTrans<<endl;
    cout<<"Original text: "<<decCaesar<<endl;


    return 0;
}
