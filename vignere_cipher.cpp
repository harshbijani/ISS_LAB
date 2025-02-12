#include <iostream>
#include <string>
#include <algorithm> // for transform

using namespace std;

// Function to encrypt the plaintext using Vigenère cipher
string vigenereEncrypt(const string& plaintext, const string& key) {
    string ciphertext = "";
    int keyLength = key.length();

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        // Ensure the characters are uppercase
        plainChar = toupper(plainChar);
        keyChar = toupper(keyChar);

        if (isalpha(plainChar)) {
            // Encrypt the character
            char encryptedChar = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';
            ciphertext += encryptedChar;
        } else {
            // If it's not a letter, leave it unchanged
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

// Function to decrypt the ciphertext using Vigenère cipher
string vigenereDecrypt(const string& ciphertext, const string& key) {
    string plaintext = "";
    int keyLength = key.length();

    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLength];

        // Ensure the characters are uppercase
        cipherChar = toupper(cipherChar);
        keyChar = toupper(keyChar);

        if (isalpha(cipherChar)) {
            // Decrypt the character
            char decryptedChar = ((cipherChar - 'A') - (keyChar - 'A') + 26) % 26 + 'A';
            plaintext += decryptedChar;
        } else {
            // If it's not a letter, leave it unchanged
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

// Function to run test cases
void runTestCases() {
    // Test Case 1
    string plaintext1 = "HELLO";
    string key1 = "KEY";
    string ciphertext1 = vigenereEncrypt(plaintext1, key1);
    string decryptedText1 = vigenereDecrypt(ciphertext1, key1);
    cout << "Test Case 1:" << endl;
    cout << "Plaintext: " << plaintext1 << endl;
    cout << "Key: " << key1 << endl;
    cout << "Encrypted Text: " << ciphertext1 << endl;
    cout << "Decrypted Text: " << decryptedText1 << endl;
    cout << "----------------------------------------" << endl;

    // Test Case 2
    string plaintext2 = "ATTACKATDAWN";
    string key2 = "LEMON";
    string ciphertext2 = vigenereEncrypt(plaintext2, key2);
    string decryptedText2 = vigenereDecrypt(ciphertext2, key2);
    cout << "Test Case 2:" << endl;
    cout << "Plaintext: " << plaintext2 << endl;
    cout << "Key: " << key2 << endl;
    cout << "Encrypted Text: " << ciphertext2 << endl;
    cout << "Decrypted Text: " << decryptedText2 << endl;
    cout << "----------------------------------------" << endl;

    // Test Case 3
    string plaintext3 = "CRYPTOGRAPHY";
    string key3 = "CODE";
    string ciphertext3 = vigenereEncrypt(plaintext3, key3);
    string decryptedText3 = vigenereDecrypt(ciphertext3, key3);
    cout << "Test Case 3:" << endl;
    cout << "Plaintext: " << plaintext3 << endl;
    cout << "Key: " << key3 << endl;
    cout << "Encrypted Text: " << ciphertext3 << endl;
    cout << "Decrypted Text: " << decryptedText3 << endl;
    cout << "----------------------------------------" << endl;

    // Test Case 4 (with spaces and non-alphabetic characters)
    string plaintext4 = "HELLO WORLD! 123";
    string key4 = "SECRET";
    string ciphertext4 = vigenereEncrypt(plaintext4, key4);
    string decryptedText4 = vigenereDecrypt(ciphertext4, key4);
    cout << "Test Case 4:" << endl;
    cout << "Plaintext: " << plaintext4 << endl;
    cout << "Key: " << key4 << endl;
    cout << "Encrypted Text: " << ciphertext4 << endl;
    cout << "Decrypted Text: " << decryptedText4 << endl;
    cout << "----------------------------------------" << endl;
}

int main() {
    // Run predefined test cases
    runTestCases();

    // Allow user to input their own plaintext and key
    string plaintext, key;
    cout << "Enter your own plaintext: ";
    getline(cin, plaintext);

    cout << "Enter your own key: ";
    getline(cin, key);

    // Encrypt the plaintext
    string ciphertext = vigenereEncrypt(plaintext, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = vigenereDecrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}