#include "SubstitutionCipher.h"

std::string SubstitutionCipher::encrypt(const std::string &plaintext) const {
    std::string result;
    for (char ch : plaintext) {
        auto it = substitutionMap.find(ch);
        result += (it != substitutionMap.end()) ? it->second : ch; // 替换字符或保留原字符
    }
    return result;
}

std::string SubstitutionCipher::decrypt(const std::string &ciphertext) const {
    std::string result;
    // 反转映射
    std::unordered_map<char, char> reverseMap;
    for (const auto& pair : substitutionMap) {
        reverseMap[pair.second] = pair.first;
    }

    for (char ch : ciphertext) {
        auto it = reverseMap.find(ch);
        result += (it != reverseMap.end()) ? it->second : ch; // 替换字符或保留原字符
    }
    return result;
}
