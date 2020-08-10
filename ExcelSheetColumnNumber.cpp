#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <string>

using namespace std;

class Solution {
    const int multiples[7] = {1, 26, 676, 17576, 456976, 11881376, 308915776}; 
public:
    int titleToNumber(string s) {
        int r = 0;
        int j = 0;
        for(auto it = s.crbegin(); it != s.crend(); ++it, ++j) {
            r += (*it - 'A' + 1) * multiples[j];
        }
        return r;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    auto r = sol.titleToNumber("AB");
    REQUIRE(r == 28);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    auto r = sol.titleToNumber("ZY");
    REQUIRE(r == 701);
}
