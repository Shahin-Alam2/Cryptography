#include<bits/stdc++.h>

using namespace std;

string encryptCaesar(string text,int shift){
    string result;

    for(auto &i:text){
        if(i>='A' && i<='Z')
            result += (i-'A'+shift)%26+'A';
        else if(i>='a' && i<='z')
            result += (i-'a'+shift)%26+'a';
        else
            result += i;
    }
    return result; 
}
string decryptCaesar(string encCaesar,int shift){
    string result;
    for(auto &i:encCaesar){
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
    int shift=3;
    string text,encCaesar,decCaesar;
    text="Computer Science";
    encCaesar=encryptCaesar(text,shift);
    decCaesar=decryptCaesar(encCaesar,shift);

    cout<<"Plaintext: "<<text<<endl;
    cout<<"Encrypted Cipher: "<<encCaesar<<endl;
    cout<<"Decrypted text: "<<decCaesar<<endl;

    return 0;
}