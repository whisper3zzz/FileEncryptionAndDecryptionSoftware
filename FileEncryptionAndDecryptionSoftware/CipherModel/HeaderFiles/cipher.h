#ifndef CIPHER_H
#define CIPHER_H

#include <string>

class Cipher {
  public:
    virtual ~Cipher() = default;

           // 加密方法
    virtual std::string encrypt(const std::string &plaintext) const = 0;

           // 解密方法
    virtual std::string decrypt(const std::string &ciphertext) const = 0;
};

#endif // CIPHER_H
