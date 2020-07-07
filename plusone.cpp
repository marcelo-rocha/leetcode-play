#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

using namespace std;

class Solution {
    void inc(vector<int>& digits, int idx) {
        int d = digits[idx];
        if (d < 9) {
            digits[idx] = d + 1;
        } else {
            digits[idx] = 0;
            if (idx > 0) {
                inc(digits, idx - 1);
            } else {
                digits.insert(digits.begin(), 1);
            }
        }
    }
public:
    vector<int> plusOne(vector<int>& digits) {
        inc(digits, digits.size() - 1);
        return digits;        
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    vector<int> v({1, 2, 3});
    auto r = sol.plusOne(v);
    REQUIRE(r == vector<int>({1, 2, 4}));
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    vector<int> v({4, 3, 2, 1});
    auto r = sol.plusOne(v);
    REQUIRE(r == vector<int>({4, 3, 2, 2}));
}

TEST_CASE( "Corner 1", "[samples]" ) {
    Solution sol;
    vector<int> v({0});
    auto r = sol.plusOne(v);
    REQUIRE(r == vector<int>({1}));
}

TEST_CASE( "Corner 2", "[samples]" ) {
    Solution sol;
    vector<int> v({9});
    auto r = sol.plusOne(v);
    REQUIRE(r == vector<int>({1, 0}));
}

TEST_CASE( "Corner 3", "[samples]" ) {
    Solution sol;
    vector<int> v({9,9});
    auto r = sol.plusOne(v);
    REQUIRE(r == vector<int>({1, 0, 0}));
}
