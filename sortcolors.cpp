#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0;
        int m, n;
        int len = nums.size();
        int x = 0, y = len - 1;
        while(x <= y) {
            m = nums[x];
            nums[x] = 1;
            if(m == 2) {
                while(x <= y) {
                    if (nums[y] != 2)
                        break; 
                    y--;
                }
                if (x <= y) {
                    n = nums[y];
                    nums[y--] = 2;
                    if (n==0) {
                        nums[z++] = 0;
                    } 
                }
            } else if(m == 0) {
                nums[z++] = 0;
            } 
            x++;
        }
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    vector<int> input = {2,0,2,1,1,0};
    vector<int> expected = {0,0,1,1,2,2}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    vector<int> input = {1,2,0,0};
    vector<int> expected = {0,0,1,2}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}



TEST_CASE( "My case 1", "[samples]" ) {
    Solution sol;
    vector<int> input = {2,2,2,1,1,0};
    vector<int> expected = {0,1,1,2,2,2}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}

TEST_CASE( "My case 2", "[samples]" ) {
    Solution sol;
    vector<int> input = {2,2,2,1,1,0,0};
    vector<int> expected = {0,0,1,1,2,2,2}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}

TEST_CASE( "My case 3", "[samples]" ) {
    Solution sol;
    vector<int> input = {2,2,2,2,2,0};
    vector<int> expected = {0,2,2,2,2,2}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}

TEST_CASE( "My case 4", "[samples]" ) {
    Solution sol;
    vector<int> input = {0,0,0,0,0,0};
    vector<int> expected = {0,0,0,0,0,0}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}

TEST_CASE( "My case 5", "[samples]" ) {
    Solution sol;
    vector<int> input = {0,1,0,1,2,0};
    vector<int> expected = {0,0,0,1,1,2}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}

TEST_CASE( "My case 6", "[samples]" ) {
    Solution sol;
    vector<int> input = {2,2,2,1,2,2};
    vector<int> expected = {1,2,2,2,2,2}; 
    sol.sortColors(input);
    REQUIRE(input == expected);
}
