#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "Cipher.h"
#include "Singleton.h"

class CaesarCipher : public Singleton<CaesarCipher>, public Cipher {
  public:
    void setShift(int shift) { this->shift = shift % 26; }

    std::string encrypt(const std::string &plaintext) const override;
    std::string decrypt(const std::string &ciphertext) const override;

  private:
    CaesarCipher() : shift(0) {} // 保护构造函数
    int shift;
};

#endif // CAESARCIPHER_H
