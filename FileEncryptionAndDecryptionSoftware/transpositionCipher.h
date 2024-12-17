#ifndef TRANSPOSITIONCIPHER_H
#define TRANSPOSITIONCIPHER_H

#include "Cipher.h"
#include "Singleton.h"
#include <vector>
#include <algorithm>

class TranspositionCipher : public Singleton<TranspositionCipher>, public Cipher {
  public:
    void setKey(const std::vector<int>& key) { this->key = key; }

    std::string encrypt(const std::string &plaintext) const override;
    std::string decrypt(const std::string &ciphertext) const override;

  private:
    TranspositionCipher() = default; // 保护构造函数
    std::vector<int> key;
};

#endif // TRANSPOSITIONCIPHER_H
