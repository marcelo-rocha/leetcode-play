#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size(), tlen = t.size();
        if (slen >= tlen) {
            return slen == tlen ? s == t : false;
        } else if (slen == 0) {
            return true;
        } 

        int i = 0, j = 0;
        while(j < tlen) {
            if (s[i] == t[j++]) {
                if (++i == slen) {
                    return true;
                }
            }
        }
        return false;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.isSubsequence("abc", "ahbgdc") == true);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.isSubsequence("axc", "ahbgdc") == false);
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.isSubsequence("", "ahbgdc") == true);
}
