# Target miner

Provide some data, mine a sha256 hash of this data that matches a particular target. 

### Compile and Run

Tested on a Linux machine (Ubuntu 18.04 LTS). Compile with the following command:  
```g++ -Wall -o main.o main.cpp sha256.cpp -I ./```

Then run the binary like so:  
```./main.o {keyword} {data} {target} {mining mode}```

An example of this would be:  
```./main.o omkar http://makeomkarveryrich.com 21e8 1```

And would result in the following output:  
```
ROTATION 0:
DATA: http://www.makeomkarveryrich.com
DATA HASH: 266f341a14ac6ef22c0e2fe7c9fb2bd6fcd297c978bd6dccf1cc7ee54d401511
ROTATION HASH: 21e8d55d2418e2cbcf64e61d997694f3ee2950ee63743b4600c485e3a768a91e
NONCE: 137314
SOURCE: omkar
TARGET: 21e8
```
Where the combined keyword, data, and incrementing nonce are hashed until one is found with the target value as a prefix for the hash. This is the idea behind blockchain PoW.

Can be extended to mine multiple rotations using the two different mining modes (rotation 0 is identical for both rotate and fork modes).

SHA256 library is not made by me and is copyright of the respective owners. Accessible here:  
https://create.stephan-brumme.com/hash-library/  