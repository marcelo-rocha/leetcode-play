#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) {
            return 0;
        }
        int profit = 0;
        int minStock = prices[0];
        for(auto p: prices) {
            profit = max(profit, p - minStock);
            minStock = min(minStock, p);
        }
        return profit;    
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    vector<int> prices{7,1,5,3,6,4};
    auto r = sol.maxProfit(prices);
    REQUIRE(r == 5);
}

TEST_CASE("sample 2", "[samples]") {
    Solution sol;
    vector<int> prices{7,6,4,3,1};
    auto r = sol.maxProfit(prices);
    REQUIRE(r == 0);
}
