#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

using namespace std;

class Solution {
private:
    int getRevision(string::const_iterator &it, const string::const_iterator &end) {
        string s;
        while(it != end) {
            char c = *it;
            ++it;
            if(c == '.') {
                break;
            } else {
                s.push_back(c);   
            }
        }
        return s.length() > 0 ? stoi(s) : 0;
    }
public:
    int compareVersion(string version1, string version2) {
        auto it1 = version1.cbegin();
        auto it2 = version2.cbegin();
        auto end1 = version1.cend();
        auto end2 = version2.cend();

        while(it1 != end1 || it2 != end2) {
            int x = getRevision(it1, end1);
            int y = getRevision(it2, end2);
            if (x > y) {
                return 1;
            } else if (x < y) {
                return -1;
            }
        }
        return 0;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.compareVersion("0.1", "1.1") == -1);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.compareVersion("1.0.1", "1") == 1);
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.compareVersion("7.5.2.4", "7.5.3") == -1);
}

TEST_CASE( "Sampple 4", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.compareVersion("1.01", "1.001") == 0);
}

TEST_CASE( "Sampple 5", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.compareVersion("1.0", "1.0.0") == 0);
}
