#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) {
            return 0;
        }
        int total = 0;
        int lastValue = timeSeries[0];
        for(int t: timeSeries) {
            total += min(t - lastValue, duration);
            lastValue = t;
        }
        total += duration;
        return total;
    }
};

TEST_CASE( "Sample 1", "[samples]" ) {
    Solution sol;
    int r = sol.findPoisonedDuration(vector<int>{1, 4}, 2);
    REQUIRE(r == 4);   
}

TEST_CASE( "Sample 2", "[samples]" ) {
    Solution sol;
    int r = sol.findPoisonedDuration(vector<int>{1, 2}, 2);
    REQUIRE(r == 3);   
}

TEST_CASE( "Test 1", "[samples]" ) {
    Solution sol;
    int r = sol.findPoisonedDuration(vector<int>{1, 2, 3, 4, 5}, 5);
    REQUIRE(r == 9);   
}
