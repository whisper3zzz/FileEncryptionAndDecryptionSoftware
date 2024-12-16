#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include "Cipher.h"
#include "Singleton.h"
#include <string>

class VigenereCipher : public Singleton<VigenereCipher>, public Cipher {
  public:
    void setKey(const std::string &key) { this->key = key; }

    std::string encrypt(const std::string &plaintext) const override;
    std::string decrypt(const std::string &ciphertext) const override;

  private:
    VigenereCipher() = default; // 保护构造函数
    std::string key;
};

#endif // VIGENERECIPHER_H
