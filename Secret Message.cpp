#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    // Define the alphabet
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    // Generate a random key by shuffling the alphabet
    string key = alphabet;
    random_device rd;
    mt19937 g(rd());
    shuffle(key.begin(), key.end(), g);

    // Output the key for reference (in practice, this would be kept secret)
    cout << "Generated random key: " << key << endl;

    // Input the secret message from the user
    string secret_message;
    cout << "Enter your secret message: ";
    getline(cin, secret_message);

    // Encrypt the message
    string encrypted_message;
    cout << "\nEncrypting message..." << endl;
    for (char c : secret_message) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            char new_char = key.at(position);
            encrypted_message += new_char;
        } else {
            encrypted_message += c;
        }
    }
    cout << "\nEncrypted message: " << encrypted_message << endl;

    // Ask the user if they want to decrypt the message
    char choice;
    cout << "Do you want to decrypt the message? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        // Decrypt the message
        string decrypted_message;
        cout << "Decrypting message..." << endl;
        for (char d : encrypted_message) {
            size_t position = key.find(d);
            if (position != string::npos) {
                char d_char = alphabet.at(position);
                decrypted_message += d_char;
            } else {
                decrypted_message += d;
            }
        }
        cout << "Decrypted message: " << decrypted_message << endl;
    } else if (choice == 'n' || choice == 'N') {
        cout << "Okay!" << endl;
    } else {
        cout << "Sorry! Your choice is not valid." << endl;
    }

    return 0;
}