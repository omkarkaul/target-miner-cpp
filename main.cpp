#include <iostream>
#include <string.h>
#include "sha256.h"

void mine(std::string keyword, std::string data, std::string target, std::string mode) {
    return;
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