#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <array>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        array<short int, 80> counters;
        counters.fill(0);
        for(char c: s) {
            counters[c-0x30]++;
        }
        int r = 0;
        int leftovers = 0;
        for(auto n: counters) {
            if (n & 1) {
                leftovers++;
                n--;
            }
            r += n;
        }
        if (leftovers > 0)
            r += 1;
        return r;        
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    int r = sol.longestPalindrome("abccccdd");
    REQUIRE(r == 7);
}