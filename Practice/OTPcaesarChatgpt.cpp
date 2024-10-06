#include <bits/stdc++.h> 
using namespace std;

string encryptOTP(string msg) {
    ifstream input("./sendrPad.txt");
    string keyword, cipherText;
    int i, j = 0;  // j to track the keyword index (skipping spaces)

    getline(input, keyword);
    input.close();

    if (keyword.size() < msg.size()) {
        cout << "!! pad msg length < original msg length !! please update one time pad." << endl;
        exit(0);
    }

    for (i = 0; i < msg.size(); i++) {
        if (islower(msg[i])) {
            cipherText += (((msg[i] - 'a') + (keyword[j] - 'a') + 1) % 26) + 'a';  // OTP encryption with shift by 1
            j++;  // Only increment j for letters, skip spaces
        } else if (msg[i] == ' ') {
            cipherText += ' ';  // Keep spaces as is
        }
    }

    return cipherText;
}

string encryptCaesar(string text, int shift) {
    string result;
    for (auto &i : text) {
        if (i >= 'A' && i <= 'Z')
            result += (i - 'A' + shift) % 26 + 'A';
        else if (i >= 'a' && i <= 'z')
            result += (i - 'a' + shift) % 26 + 'a';
        else
            result += i;
    }
    return result;
}

string decryptCaesar(string encText, int shift) {
    string result;
    for (auto &i : encText) {
        if (i >= 'A' && i <= 'Z')
            result += (i - 'A' - shift + 26) % 26 + 'A';
        else if (i >= 'a' && i <= 'z')
            result += (i - 'a' - shift + 26) % 26 + 'a';
        else
            result += i;
    }
    return result;
}

string decryptOTP(string encMsg) {
    ifstream input("./recvrPad.txt");
    string keyword, plainText;
    int i, j = 0;  // j to track the keyword index (skipping spaces)

    getline(input, keyword);
    input.close();

    for (i = 0; i < encMsg.size(); i++) {
        if (islower(encMsg[i])) {
            plainText += ((encMsg[i] - 'a') - (keyword[j] - 'a') + 26) % 26 + 'a';  // OTP decryption
            j++;  // Increment j only for non-space characters
        } else if (encMsg[i] == ' ') {
            plainText += ' ';  // Preserve spaces
        }
    }

    return plainText;
}

int main() {
    int shift = 3;
    string msg, encOTP, encCaesar, decCaesar, decOTP;
    ifstream in("./inOTP.txt", ios::in);

    getline(in, msg);
    cout << "Input Text: " << msg << endl;

    encOTP = encryptOTP(msg);
    cout << "One Time Pad Cipher: " << encOTP << endl;

    encCaesar = encryptCaesar(encOTP, shift);
    cout << "Caesar Cipher: " << encCaesar << endl;

    decCaesar = decryptCaesar(encCaesar, shift);
    cout << "Decrypted Caesar: " << decCaesar << endl;

    decOTP = decryptOTP(decCaesar);
    cout << "PlainText: " << decOTP << endl;

    in.close();
    return 0;
}
