#include <iostream>
#include <string.h>
#include "sha256.h"

bool is_prefix(std::string target, std::string data) {
    // checks if the target is a prefix of the data at index 0
    // i.e. the data "starts with" the target

    return data.substr(0, target.length()) == target;
}

std::string get_hash(std::string s) {
    // hashes data using sha256 and returns the digest

    SHA256 sha256;
    std::string digest = sha256(s);
    return digest;
}

void mine(std::string keyword, std::string data, std::string target, std::string mode) {
    // performs the mining, mode 1 -> rotate, mode 2 -> fork

    // perform initial total hash
    int nonce = 0;
    std::string data_hash = get_hash(data);
    std::string concatenated_str = keyword + data_hash + std::to_string(nonce);
    std::string total_hash = get_hash(concatenated_str);

}

int main(int argc, char* argv[]) {
    if (argc < 4)
        perror("Provide 4 args in order: {keyword} {data} {target} {mining mode}");
        return 1;
    
    std::string keyword = argv[1];
    std::string data = argv[2];
    std::string target = argv[3];
    std::string mode = argv[4];

    mine(keyword, data, target, mode);

    return 0;
}