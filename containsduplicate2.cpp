#include <set>
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int len = nums.size();
        set<int> windown;

        int w = min(k + 1, len);
        for(int i = 0; i < w; i++) {
            auto r = windown.emplace(nums[i]);
            if (r.second == false) {
                return true;
            }
        }
        
        if (w == len) {
            return false;
        }
        
        for (int i = w; i < len; i++) {
            windown.erase(nums[i-w]);
            auto r = windown.emplace(nums[i]);
            if (r.second == false) {
                return true;
            }
        }
        return false;
    }
};
