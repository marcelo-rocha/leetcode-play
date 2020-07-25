// Find Minimum in Rotated Sorted Array problem
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = 0;
        int last = nums.size() - 1;
        int len; 
        while((len = (last - first)) > 1) {
            int middle = first + len / 2;
            if (nums[first] > nums[middle]) {
                last = middle;
            } else if (nums[middle] > nums[last]) {
                first = middle;
            } else {
                break;
            }
        }
        return std::min(nums[first], nums[last]);
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    vector<int> v({3,4,5,1,2});
    REQUIRE(sol.findMin(v) == 1);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    vector<int> v({4,5,6,7,0,1,2});
    REQUIRE(sol.findMin(v) == 0);
}
