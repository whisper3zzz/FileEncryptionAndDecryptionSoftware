#include "VigenereCipher.h"

std::string VigenereCipher::encrypt(const std::string &plaintext) const {
    std::string result;
    size_t keyLength = key.length();
    size_t keyIndex = 0;

    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            char keyChar = tolower(key[keyIndex % keyLength]) - 'a'; // 使用小写字符的偏移量
            result += (ch - base + keyChar) % 26 + base;
            keyIndex++;
        } else {
            result += ch; // 保留非字母字符
        }
    }

    return result;
}

std::string VigenereCipher::decrypt(const std::string &ciphertext) const {
    std::string result;
    size_t keyLength = key.length();
    size_t keyIndex = 0;

    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            char keyChar = tolower(key[keyIndex % keyLength]) - 'a'; // 使用小写字符的偏移量
            result += (ch - base - keyChar + 26) % 26 + base;
            keyIndex++;
        } else {
            result += ch; // 保留非字母字符
        }
    }

    return result;
}
