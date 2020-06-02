#include <vector>
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> D;
        int m = word1.length();
        int n = word2.length();
        if ((m == 0) || (n == 0)) {
            return max(m, n);
        } 
        D.reserve(m + 1);
        for (int i = 0; i <= m; ++i) {
            D.push_back(move(vector<int>(n + 1, 0)));
        }
        for(int x = 1; x <= m; ++x) {
            D[x][0] = x;
        }
        for(int y = 1; y <= n; ++y) {
            D[0][y] = y;
        }

        int subCost;
        for(int x = 1; x <= m; ++x) {
            for(int y = 1; y <= n; ++y) {
                subCost = word1[x-1] == word2[y - 1] ? 0 : 1;
                D[x][y] = min(
                    min(D[x-1][y] + 1, D[x][y-1] + 1),
                    D[x-1][y-1] + subCost);
            }
        }
        return D[m][n];
    }
};

TEST_CASE("levenshtein", "[samples]") {
    Solution sol;
    CHECK(sol.minDistance("kitten", "sitting") == 3);
}
