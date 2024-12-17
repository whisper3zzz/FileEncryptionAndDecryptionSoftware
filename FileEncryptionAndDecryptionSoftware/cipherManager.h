#ifndef CIPHERMANAGER_H
#define CIPHERMANAGER_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Cipher.h"
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include "XorCipher.h"
#include "Singleton.h"
#include"substitutionCipher.h"
class CipherManager : public Singleton<CipherManager> {
    friend class Singleton<CipherManager>;

  public:
    // 算法列表
    std::vector<std::string> getAvailableAlgorithms() const {
        std::vector<std::string> algorithmNames;
        for (const auto& pair : ciphers) {
            algorithmNames.push_back(pair.first);
        }
        return algorithmNames;
    }


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

    CipherManager() {

        registerCipher("Caesar", &CaesarCipher::instance());
        registerCipher("Vigenere", &VigenereCipher::instance());
        registerCipher("Xor", &XorCipher::instance());
        registerCipher("Substitution", &SubstitutionCipher::instance());
    }


    void registerCipher(const std::string& name, Cipher* cipher) {
        ciphers[name] = cipher;
    }


    std::unordered_map<std::string, Cipher*> ciphers;
};

#endif // CIPHERMANAGER_H
