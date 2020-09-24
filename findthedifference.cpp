#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <algorithm>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    
    char findTheDifference(string s, string t) {
        array<int, 26> counters;
        counters.fill(0);
        for(char c: t) {
            counters[c - 'a']++;
        }
        for(char c: s) {
            counters[c - 'a']--;
        }
        for(int i = 0; i < counters.size(); i++) {
            if (counters[i] > 0) {
                return 'a' + i;
            }
        }
        return ' ';
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    auto r = sol.findTheDifference("abcd", "abcde");
    REQUIRE(r == 'e');
}

