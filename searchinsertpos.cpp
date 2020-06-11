#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        int idx = low - nums.begin();
        if (low == nums.end()) {
            return nums.size();
        }
        return low - nums.begin();
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    vector<int> input({1, 3, 5, 6});
    int r = sol.searchInsert(input, 5);
    REQUIRE(r == 2);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    vector<int> input({1, 3, 5, 6});
    int r = sol.searchInsert(input, 2);
    REQUIRE(r == 1);
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    vector<int> input({1, 3, 5, 6});
    int r = sol.searchInsert(input, 7);
    REQUIRE(r == 4);
}

TEST_CASE( "Sampple 4", "[samples]" ) {
    Solution sol;
    vector<int> input({1, 3, 5, 6});
    int r = sol.searchInsert(input, 0);
    REQUIRE(r == 0);
}
