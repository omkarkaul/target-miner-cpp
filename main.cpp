#include <iostream>
#include <string.h>
#include "sha256.h"

void output_state(std::string keyword, std::string data, std::string data_hash, 
    std::string rotation_hash, int nonce, std::string target) {
    // output the state of a successful mining rotation to stdout

    std::cout << "DATA: " << data << std::endl;
    std::cout << "DATA HASH: " << data_hash << std::endl;
    std::cout << "ROTATION HASH: " << rotation_hash << std::endl;
    std::cout << "NONCE: " << nonce << std::endl;
    std::cout << "SOURCE: " << keyword << std::endl;
    std::cout << "TARGET: " << target << std::endl;
    std::cout << "-------------------------------\n" << std::endl;
}

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

int mine(std::string keyword, std::string data, std::string target, std::string mode) {
    // performs the mining, mode 1 -> rotate, mode 2 -> fork

    // perform initial total hash
    std::cout << "ROTATION 0:" << std::endl;
    int nonce = 1;
    std::string data_hash = get_hash(data);
    std::string concatenated_str = keyword + data_hash + std::to_string(nonce);
    std::string total_hash = get_hash(concatenated_str);

    // perform first rotation of mining
    while (!is_prefix(target, total_hash)) {
        nonce += 1;
        concatenated_str = keyword + data_hash + std::to_string(nonce);
        total_hash = get_hash(concatenated_str);
    }
    
    output_state(keyword, data, data_hash, total_hash, nonce, target);

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc <= 4) {
        std::cout << "Provide 4 args: {keyword} {data} {target} {mining mode}" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::string keyword = argv[1];
    std::string data = argv[2];
    std::string target = argv[3];
    std::string mode = argv[4];

    int val = mine(keyword, data, target, mode);

    return val;
}