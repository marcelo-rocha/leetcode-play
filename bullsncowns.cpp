#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <array>
#include <sstream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0; 
        int cows = 0;
        array<int, 10> digits;
        digits.fill(0);
        for(int i = 0; i < secret.length(); ++i) {
            int c = secret[i]; 
            if (c == guess[i]) {
                bulls++;
            } else {
                digits[c - '0'] += 1;
            }
        }
        for(int i = 0; i < guess.length(); ++i) {
            char g = guess[i];
            if (g == secret[i]) {
                continue;
            }
            int d = g - '0';
            if (digits[d] > 0) {
                digits[d] -= 1;
                cows++;
            }
        } 

        stringstream ss;
        ss << bulls << "A" << cows << "B";
        return ss.str();        
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.getHint("1807", "7810") == "1A3B");
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    REQUIRE(sol.getHint("1123", "0111") == "1A1B");
}
