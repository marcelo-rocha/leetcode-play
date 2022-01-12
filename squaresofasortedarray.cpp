// https://leetcode.com/problems/squares-of-a-sorted-array/
#include <vector>
#include <cstdlib>
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        result.resize(nums.size());

        int m = 0, n = nums.size() - 1;
        int i = n;
        while (i>=0) {
            auto x = abs(nums[m]);
            auto y = abs(nums[n]);
            if (y > x) {
                result[i--] = y*y;
                n--;
            } else {
                result[i--] = x*x;
                m++;
            }
        }

        return result;
    }
};

TEST_CASE( "Sampple 1", "[leetcode]" ) {
    Solution sol;
    vector<int> v({-4,-1,0,3,10});
    auto r = sol.sortedSquares(v);
    REQUIRE(r == vector<int>({0,1,9,16,100}));
}

TEST_CASE( "Sampple 2", "[leetcode]" ) {
    Solution sol;
    vector<int> v({-7,-3,2,3,11});
    auto r = sol.sortedSquares(v);
    REQUIRE(r == vector<int>({4,9,9,49,121}));
}