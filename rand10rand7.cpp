// Implement Rand10() Using Rand7()
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;


// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand7() {
    return rand() % 7 + 1;
}

class Solution {
public:
    int rand10() {
        for(;;) {
            int y = rand7();
            int x = rand7();
            if (y == 7)
              continue;
            int m = (y - 1)*7 + (x - 1);
            int n = m / 4;
            if (n < 10)
                return n + 1;
        }
    }
};

