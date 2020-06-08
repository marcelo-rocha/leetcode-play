#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <bitset>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> nset(n);
        return n > 0 ? nset.count() == 1 : false;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.isPowerOfTwo(0) == true);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.isPowerOfTwo(16) == true);
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.isPowerOfTwo(218) == false);
}
