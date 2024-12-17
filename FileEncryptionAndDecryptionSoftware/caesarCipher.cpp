#include "CaesarCipher.h"

std::string CaesarCipher::encrypt(const std::string &plaintext) const {
    std::string result;
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            result += (ch - base + shift) % 26 + base;
        } else {
            result += ch; // 保留非字母字符
        }
    }
    return result;
}

std::string CaesarCipher::decrypt(const std::string &ciphertext) const {
    std::string result;
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            result += (ch - base - shift + 26) % 26 + base;
        } else {
            result += ch; // 保留非字母字符
        }
    }
    return result;
}
