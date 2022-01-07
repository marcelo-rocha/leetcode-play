#include <vector>
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        auto b = arr.size() - 1;
        size_t a = 0;

        while(a < b) {
            auto mid = a + (b - a) / 2;
            if (arr[mid] < arr[mid + 1]) {
                a = mid + 1;
            } else if (arr[mid] > arr[mid + 1]) {
                b = mid;
            } else {
                break;
            }
        }        
        return a;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    std::vector<int> v({0, 1, 0});
    auto r = sol.peakIndexInMountainArray(v);
    REQUIRE(r == 1);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    std::vector<int> v({0, 2, 1, 0});
    auto r = sol.peakIndexInMountainArray(v);
    REQUIRE(r == 1);
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    std::vector<int> v({0, 10, 5, 2});
    auto r = sol.peakIndexInMountainArray(v);
    REQUIRE(r == 1);
}