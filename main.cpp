#include <iostream> 
#include <string>
#include <iomanip>

using namespace std; 

int main(){
     const string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
     const string cipher {"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA"};
    string message {};
    string enc_message {};
    
    cout << "Enter a secret message to encrypt: ";
    getline(cin,message);
    
    cout << "Encrypting message....\n" << endl; 
    for (size_t i {0}; i < message.length(); i++){
        size_t posit {};
        if (alphabet.find(message.at(i)) != string::npos){
            posit = alphabet.find(message.at(i)); 
            posit = posit + 2 % 26; // maths 
            enc_message += cipher.at(posit);
            }
        else
            enc_message += message.at(i);
        }
    message.erase(0, message.length());
    cout << "the encrypted message is: " + enc_message << endl; 
    
    cout << "Decrypting message...\n" << endl; 
    for (size_t i {0}; i < enc_message.length(); i++){
        size_t posit {};
        if (cipher.find(enc_message.at(i)) != string::npos){
            posit = cipher.find(enc_message.at(i)); 
            posit = posit - 2 % 26; // maths
            message += alphabet.at(posit);
            }
        else 
            message +=enc_message.at(i);
        }
    cout << "The decrypted message is : " << message << endl; 

    return 0;
}