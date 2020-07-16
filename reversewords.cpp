#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        istringstream ss(s);
        int count = 0;
        do {
            string word;
            ss >> word;
            if (word.size() > 0) {
                stk.push(word);
                count += word.length() + 1;
            }
        } while (ss);

        string result;
        result.reserve(count);
        if(!stk.empty()) {
            for(;;) {
                result += stk.top();
                stk.pop();
                if (!stk.empty()) {
                    result += ' ';
                } else {
                    break;
                }
            }    
        }
        return result;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    auto r = sol.reverseWords("the sky is blue");
    REQUIRE(r == "blue is sky the");
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    auto r = sol.reverseWords("  hello world!  ");
    REQUIRE(r == "world! hello");
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    auto r = sol.reverseWords("a good   example");
    REQUIRE(r == "example good a");
}
