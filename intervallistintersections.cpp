// problem https://leetcode.com/problems/interval-list-intersections/
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        auto i = 0, j = 0;
        vector<vector<int>> result;

        while ((i < firstList.size()) && (j < secondList.size())) {
            //cout << "i -> " << i << "; j -> " << j << endl;
            auto a = firstList[i], b = secondList[j];
            auto r = getIntersection(a, b);
            if (r.size() > 0) {
                result.push_back(r);
            }
            a[1] < b[1] ? i++ : j++;
        }
        return result;
    }
private:
    vector<int> getIntersection(vector<int> a, vector<int> b) {
        auto x = max(a[0], b[0]);

        if ((x > a[1]) || (x > b[1])) {
            return vector<int>();
        }

        auto y = min(a[1], b[1]);
        return vector<int>{x, y};
    }
};

TEST_CASE( "test1", "[samples]" ) {
    Solution sol;
    vector<vector<int>> firstList({{0,2},{5,10},{13,23},{24,25}});
    vector<vector<int>> secondList({{1,5},{8,12},{15,24},{25,26}});

    auto r = sol.intervalIntersection(firstList, secondList);

    vector<vector<int>> expectedResult({{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}});
    REQUIRE(r == expectedResult);
}

TEST_CASE( "test2", "[samples]" ) {
    Solution sol;
    vector<vector<int>> firstList({{0,3},{5,9}});
    vector<vector<int>> secondList;

    auto r = sol.intervalIntersection(firstList, secondList);

    vector<vector<int>> expectedResult;
    REQUIRE(r == expectedResult);
}