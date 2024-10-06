#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/*string generateKey(int length) {
    string key;
    for (int i = 0; i < length; i++) {
        key += (rand() % 26) + 'a';
    }
    return key;
}*/

string encryptOTP(const string& text, const string& key) {
    string encryptedText;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            encryptedText += ((text[i] - 'A') + (key[i] - 'a') + 1) % 26 + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            encryptedText += ((text[i] - 'a') + (key[i] - 'a') + 1) % 26 + 'a';
        } else {
            encryptedText += text[i];
        }
    }
    return encryptedText;
}

string decryptOTP(const string& cipherText, const string& key) {
    string decryptedText;
    for (int i = 0; i < cipherText.length(); i++) {
        if (cipherText[i] >= 'A' && cipherText[i] <= 'Z') {
            decryptedText += ((cipherText[i] - 'A') - (key[i] - 'a') + 26 - 1) % 26 + 'A';
        }
        else if (cipherText[i] >= 'a' && cipherText[i] <= 'z') {
            decryptedText += ((cipherText[i] - 'a') - (key[i] - 'a') + 26 - 1) % 26 + 'a';
        } else {
            decryptedText += cipherText[i];
        }
    }
    return decryptedText;
}

int main() {

    string plainText;
    ifstream in("./in5.txt", ios::in);
    getline(in, plainText);

    //string key = generateKey(plainText.length());
    string key = "abcdefghijklmnopqrstuvwxyz";

    string encryptedText = encryptOTP(plainText, key);

    string decryptedText = decryptOTP(encryptedText, key);

    cout << "Input Text: " << plainText << endl;
    cout << "Generated Key: " << key << endl;
    cout << "Ciphertext: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
