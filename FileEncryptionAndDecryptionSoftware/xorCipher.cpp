#include "XorCipher.h"

std::string XorCipher::encrypt(const std::string &plaintext) const {
    std::string result;
    for (char ch : plaintext) {
        result += ch ^ key; // 使用异或运算
    }
    return result;
}

std::string XorCipher::decrypt(const std::string &ciphertext) const {
    std::string result;
    for (char ch : ciphertext) {
        result += ch ^ key; // 使用异或运算
    }
    return result;
}
