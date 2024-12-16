#include "TranspositionCipher.h"

std::string TranspositionCipher::encrypt(const std::string &plaintext) const {
    std::string result;
    int rows = (plaintext.size() + key.size() - 1) / key.size(); // 计算行数
    std::vector<std::string> grid(rows, std::string(key.size(), ' '));

           // 填充网格
    for (size_t i = 0; i < plaintext.size(); ++i) {
        grid[i / key.size()][i % key.size()] = plaintext[i];
    }

           // 按照密钥进行列重排
    for (int col : key) {
        for (int row = 0; row < rows; ++row) {
            if (col < key.size() && row < grid.size()) {
                result += grid[row][col];
            }
        }
    }

    return result;
}

std::string TranspositionCipher::decrypt(const std::string &ciphertext) const {
    std::string result;
    int rows = (ciphertext.size() + key.size() - 1) / key.size(); // 计算行数
    std::vector<std::string> grid(rows, std::string(key.size(), ' '));

           // 填充网格并按照密钥索引重排
    std::vector<int> inverseKey(key.size());
    for (int i = 0; i < key.size(); ++i) {
        inverseKey[key[i]] = i;
    }

    int index = 0;
    for (int col : inverseKey) {
        for (int row = 0; row < rows; ++row) {
            if (row * key.size() + col < ciphertext.size()) {
                grid[row][col] = ciphertext[index++];
            }
        }
    }

           // 读取网格中的内容
    for (const auto& row : grid) {
        result += row;
    }

    return result;
}
