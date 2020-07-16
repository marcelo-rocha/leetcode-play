#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;

class Solution {
private:
    map<unsigned, double> cache_;
    double x_;
    double pow(unsigned n) {
        if (n > 0) {
            if (cache_.count(n) == 1) {
                return cache_.at(n);
            } 
            unsigned p = n / 2;
            double r;
            if (n % 2 > 0) {
                r = x_ * pow(p) * pow(p);
             } else {
                 r = pow(p) * pow (p);
             }
             cache_[n] = r;
             return r;
        } else {
            return 1.0;
        } 
    }
public:
    double myPow(double x, int n) {
        cache_.clear();
        x_ = x;
        if (n >= 0) {
            return pow(n);
        } else {
            unsigned m = n > -2147483648 ? -n : static_cast<unsigned>(n);
            return 1.0 / pow(m);
        }    
    }
};

bool AreSame(double a, double b)
{
    return fabs(a - b) <= 0.00001;
}

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    auto r = sol.myPow(2.00000, 10);
    REQUIRE(AreSame(r, 1024.00000));
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    auto r = sol.myPow(2.10000, 3);
    REQUIRE(AreSame(r, 9.26100));
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    auto r = sol.myPow(2.00000, -2);
    REQUIRE(AreSame(r, 0.25000));
}

