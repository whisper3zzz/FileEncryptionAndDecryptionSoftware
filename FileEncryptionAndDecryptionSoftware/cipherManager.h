#ifndef CIPHERMANAGER_H
#define CIPHERMANAGER_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Cipher.h"
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include "XorCipher.h"
#include "TranspositionCipher.h"
#include "Singleton.h" // 引入单例基类

class CipherManager : public Singleton<CipherManager> {
    friend class Singleton<CipherManager>; // 允许 Singleton 访问构造函数

  public:
    // 可用算法列表
    std::vector<std::string> getAvailableAlgorithms() const {
        std::vector<std::string> algorithmNames;
        for (const auto& pair : ciphers) {
            algorithmNames.push_back(pair.first);
        }
        return algorithmNames;
    }

           // 加密和解密功能
    std::string encrypt(const std::string& algorithm, const std::string& plaintext) {
        auto it = ciphers.find(algorithm);
        if (it != ciphers.end()) {
            return it->second->encrypt(plaintext);
        }
        return "";
    }

    std::string decrypt(const std::string& algorithm, const std::string& ciphertext) {
        auto it = ciphers.find(algorithm);
        if (it != ciphers.end()) {
            return it->second->decrypt(ciphertext);
        }
        return "";
    }

  private:
    // 构造函数
    CipherManager() {
        // 注册算法
        registerCipher("Caesar", &CaesarCipher::instance());
        registerCipher("Vigenere", &VigenereCipher::instance());
        registerCipher("Xor", &XorCipher::instance());
        registerCipher("Transposition", &TranspositionCipher::instance());
    }

           // 注册算法
    void registerCipher(const std::string& name, Cipher* cipher) {
        ciphers[name] = cipher;
    }

           // 存储可用算法的映射
    std::unordered_map<std::string, Cipher*> ciphers;
};

#endif // CIPHERMANAGER_H
