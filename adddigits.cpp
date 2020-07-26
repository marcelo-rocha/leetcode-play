#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
    array<short, 10> digitsCount;
    int len = 0;
    void removePairs(int d) {
        int n = min(digitsCount[d], digitsCount[9-d]);
        if (n > 0) {
            if (len == 2*n) {
                n--;
            }
            digitsCount[d] -= n;
            digitsCount[9-d] -= n;
            len -= 2 * n;
        }
    };
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        digitsCount.fill(0);
        while(num > 0) {
            int d = num % 10;
            if(d > 0) {
                digitsCount[d]++;
                len++;
            }
            num /= 10;
        }
        if (digitsCount[9] > 1) {
            digitsCount[9]--;
            len--;
        }

        removePairs(1);
        removePairs(2);
        removePairs(3);
        removePairs(4);

        int total = 0;
        for(int i = 1; i <= 9; i++) {
            total += digitsCount[i] * i;
        }

        while (total > 9) {
            int sum = 0;
            do {
                sum += total % 10;
                total /= 10;
            }
            while(total > 9);
            total += sum;
        }
        return total;
        
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    int r = sol.addDigits(38);
    REQUIRE(r == 2);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    int r = sol.addDigits(18);
    REQUIRE(r == 9);
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    int r = sol.addDigits(90);
    REQUIRE(r == 9);
}

TEST_CASE( "Sampple 4", "[samples]" ) {
    Solution sol;
    int r = sol.addDigits(108);
    REQUIRE(r == 9);
}


TEST_CASE( "test 1", "[custom]" ) {
    Solution sol;
    int r = sol.addDigits(27518);
    REQUIRE(r == 5);
}
