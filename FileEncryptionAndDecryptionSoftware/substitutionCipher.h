#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H

#include "Cipher.h"
#include "Singleton.h"
#include <unordered_map>
#include <string>

class SubstitutionCipher : public Singleton<SubstitutionCipher>, public Cipher {
  public:
    void setSubstitution(const std::unordered_map<char, char>& substitutionMap) {
        this->substitutionMap = substitutionMap;
    }

    std::string encrypt(const std::string &plaintext) const override;
    std::string decrypt(const std::string &ciphertext) const override;


    SubstitutionCipher() = default; // 保护构造函数
    std::unordered_map<char, char> substitutionMap;
};

#endif // SUBSTITUTIONCIPHER_H
