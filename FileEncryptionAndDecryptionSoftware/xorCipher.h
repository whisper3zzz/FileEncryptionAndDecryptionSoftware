#ifndef XORCIPHER_H
#define XORCIPHER_H

#include "Cipher.h"
#include "Singleton.h"

class XorCipher : public Singleton<XorCipher>, public Cipher {
  public:
    void setKey(char key) { this->key = key; }

    std::string encrypt(const std::string &plaintext) const override;
    std::string decrypt(const std::string &ciphertext) const override;

    XorCipher() : key(0) {}
    char key;
};

#endif // XORCIPHER_H
