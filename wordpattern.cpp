#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> wordMap;
        map<string, char> inverseMap;
        istringstream ss(str);
        string w;
        for(char c: pattern) {
            if(!getline(ss, w, ' ')) {
                return false;
            }
            auto pos = wordMap.find(c);
            auto invpos = inverseMap.find(w);
            if (pos == wordMap.end() && invpos == inverseMap.end()) {
                wordMap.emplace(c, w);
                inverseMap.emplace(w, c);
            } else if (pos == wordMap.end() || invpos == inverseMap.end()) {
                return false;
            } else if (pos->second != w || invpos->second != c) {
                return false;
            }
        } 
        return !getline(ss, w, ' ');
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.wordPattern("abba", "dog cat cat dog"));
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE_FALSE(sol.wordPattern("abba", "dog cat cat fish"));
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    REQUIRE_FALSE(sol.wordPattern("aaaa", "dog cat cat fish"));
}

TEST_CASE( "Sampple 4", "[samples]" ) {
    Solution sol;
    REQUIRE_FALSE(sol.wordPattern("abba", "dog dog dog dog"));
}

TEST_CASE( "corner 1", "[corner]" ) {
    Solution sol;
    REQUIRE_FALSE(sol.wordPattern("abba", "dog dog dog "));
}

TEST_CASE( "corner 2", "[corner]" ) {
    Solution sol;
    REQUIRE_FALSE(sol.wordPattern("aaa", "dog dog dog dog"));
}

