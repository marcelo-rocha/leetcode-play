#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

static unsigned char lookup[16] = {
    0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
    0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf };

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return (lookup[n & 0xf] << 28) |
            (lookup[(n >> 4) & 0xf] << 24) |
            (lookup[(n >> 8) & 0xf] << 20) |
            (lookup[(n >> 12) & 0xf] << 16) |
            (lookup[(n >> 16) & 0xf] << 12) |
            (lookup[(n >> 20) & 0xf] << 8) |
            (lookup[(n >> 24) & 0xf] << 4) |
            (lookup[(n >> 28) & 0xf]);
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.reverseBits(43261596) == 964176192 );
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.reverseBits(4294967293) == 3221225471 );
}
