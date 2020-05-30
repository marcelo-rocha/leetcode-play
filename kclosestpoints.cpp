#include <vector>
#include <map>
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, vector<int>> distances;
        for(auto &p: points) {
            int x = p[0];
            int y = p[1];
            distances.emplace(x*x + y*y, p);
        }

        vector<vector<int>> result;
        result.reserve(K);
        for(auto it = distances.cbegin(); it != distances.cend() && K > 0; ++it, --K) {
            result.push_back(std::move(it->second));
        }

        return result;
    }
};

TEST_CASE( "Two points", "[samples]" ) {
    Solution sol;
    vector<vector<int>> input = {{1,3}, {-2, 2}};
    auto r = sol.kClosest(input, 1);
    vector<vector<int>> expectedResult = {{-2, 2}};
    REQUIRE(r == expectedResult);
}