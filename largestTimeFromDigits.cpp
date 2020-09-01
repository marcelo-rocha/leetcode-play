#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <unordered_set>

using namespace std;

class Solution {
private:
    int takeMax(unordered_multiset<int> &digits, int maxValue) {
        int r = -1;
        unordered_multiset<int>::iterator resultPos;
        for(auto it = digits.begin(); it != digits.end(); ++it) {
            auto n = *it;
            if ((n <= maxValue) && (n > r)) {
                r = n;
                resultPos = it;
            }
        }
        if (r != -1) {
            digits.erase(resultPos);
        }
        return r;
    }
public:
    string largestTimeFromDigits(vector<int>& A) {
        unordered_multiset<int> digits;

        const int maxDigits[4] = {2, 9, 5, 9};
        string result;
        result.reserve(5);

        for (int i = 0; i < 3; i++) {
            digits.clear();
            for(auto n: A) {
                digits.insert(n);
            }
            
            for(int j = 0; j < 4; j++) {
                int max = maxDigits[j];
                if (j==0) {
                    max -= i;
                } else if ((j == 1) && (result[0] == '2')) {
                    max = 3;
                } 
                int d = takeMax(digits, max);
                if (d == -1) {
                    break;
                }
                result.push_back('0' + d);
                if (j == 1) {
                    result.push_back(':');
                }  
            }
            if (result.size() == 5)
                break;
            else
                result.clear();
        }
        return result;
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    vector<int> digits{1,2,3,4};
    auto r = sol.largestTimeFromDigits(digits);
    REQUIRE(r == "23:41");
}

TEST_CASE("sample 2", "[samples]") {
    Solution sol;
    vector<int> digits{5,5,5,5};
    auto r = sol.largestTimeFromDigits(digits);
    REQUIRE(r == "");
}

TEST_CASE("sample 3", "[samples]") {
    Solution sol;
    vector<int> digits{0,0,0,0};
    auto r = sol.largestTimeFromDigits(digits);
    REQUIRE(r == "00:00");
}

TEST_CASE("sample 4", "[samples]") {
    Solution sol;
    vector<int> digits{2,0,6,6};
    auto r = sol.largestTimeFromDigits(digits);
    REQUIRE(r == "06:26");
}


TEST_CASE("case 1", "[mycases]") {
    Solution sol;
    vector<int> digits{1, 9, 8, 5};
    auto r = sol.largestTimeFromDigits(digits);
    REQUIRE(r == "19:58");
}