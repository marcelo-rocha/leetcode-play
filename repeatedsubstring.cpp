#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int ws = 0;
        int slen = s.size();
        int halfSize = slen / 2;
        while(++ws <= halfSize) {
            int j = ws;
            bool goodWord = true;
            for(int i = 0; i < ws; ++i) {
                if (s[i] != s[i+j]) {
                    goodWord = false;
                    break;
                }
            }
            if (!goodWord || ((slen % ws) > 0)) {
                continue;
            }
            int k = 2*ws;
            int remaining = slen - k;
            for(int x = 0; x < remaining; ++x) {
                if(s[k+x] != s[x % ws]) {
                    goodWord = false;
                    break;
                }
            }
            if (goodWord) {
                return true;
            }
        }
        return false;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.repeatedSubstringPattern("abab"));
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE_FALSE(sol.repeatedSubstringPattern("aba"));
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.repeatedSubstringPattern("abcabcabcabc"));
}

TEST_CASE( "test 1", "[mysamples]" ) {
    Solution sol;
    REQUIRE(sol.repeatedSubstringPattern("abaaabaaabaaabaa"));
}

TEST_CASE( "test 2", "[mysamples]" ) {
    Solution sol;
    REQUIRE_FALSE(sol.repeatedSubstringPattern("abcabcabcabcab"));
}
