#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        auto slow = to_string(low), shigh = to_string(high);
        int j = slow[0] - '0';
        for(int i = slow.length(); i <= shigh.length(); ++i, j = 1) {
            int m = 11 - i;
            while(j < m) {
                string v;
                for(int k = 0; k < i; k++) {
                    v.push_back('0' + j + k);
                }
                int n = stoi(v);
                if (n <= high) {
                    if (n >= low) {
                        result.push_back(n);
                    } 
                } 
                else
                    break;
                j++;
            }
        }
        return result;
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    vector<int> expected{123, 234};
    auto r = sol.sequentialDigits(100, 300);
    REQUIRE(r == expected);
}

TEST_CASE("sample 2", "[samples]") {
    Solution sol;
    vector<int> expected{1234,2345,3456,4567,5678,6789,12345};
    auto r = sol.sequentialDigits(1000, 13000);
    REQUIRE(r == expected);
}
