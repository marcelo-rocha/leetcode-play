#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        auto alen = a.size(), blen = b.size();
        int maxlen = max(alen, blen), minlen = min(alen, blen);
        string r;
        r.resize(maxlen);
        int c = 0;
        int i;
        int j = maxlen - 1;
        for(i = 0; i < minlen; i++) {
            int sum = (a[alen - i - 1] - '0') + (b[blen -i -1] - '0') + c;
            r[j--] = '0' + (sum & 1);
            c = sum >> 1;
        }
        if (alen != blen) {
            string &s = alen < blen ? b : a;
            auto slen = s.size();
            for(;i < maxlen && c > 0; i++) {
                int sum = c + (s[slen -i -1] - '0');
                r[j--] = '0' + (sum & 1);
                c = sum >> 1;
            }
            for(;i < maxlen; i++) {
                r[j--] = s[slen -i -1];
            }
        }
        if (c != 0) {
            r.insert(0, 1, '1');
        } 
        return r;
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    string r = sol.addBinary("11", "1");
    REQUIRE(r == "100");
}

TEST_CASE("sample 2", "[samples]") {
    Solution sol;
    string r = sol.addBinary("1010", "1011");
    REQUIRE(r == "10101");
}
