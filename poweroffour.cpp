#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <bitset>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) {
            return true;
        }
        if ((num == 0) || (num & 0x3 > 0))  { 
            return false;
        }
        if (num < 0) {
            return false;
        }
        bitset<32> bits(num);
        if (bits.count() > 1) {
            return false;
        }
        int idx = bits._Find_first();
        return (idx & 1) == 0; 
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(true == sol.isPowerOfFour(16));
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE(false == sol.isPowerOfFour(5));
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    REQUIRE(false == sol.isPowerOfFour(128));
}

TEST_CASE( "Sampple 4", "[samples]" ) {
    Solution sol;
    REQUIRE(true == sol.isPowerOfFour(256));
}
