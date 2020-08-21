#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
        result.resize(A.size());
        int i = 0, j = A.size() - 1;
        for(auto n: A) {
            n & 1 ? result[j--] = n : result[i++] = n;
        }
        return result; 
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    vector<int> input{3, 1, 2, 4};
    auto output = sol.sortArrayByParity(input);
    vector<int> expected{2,4,1,3};
    REQUIRE(output == expected);
}
