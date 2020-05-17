#include <bits/stdc++.h>

using namespace std;

void printVector(const vector<int> &v) {
  for(int n: v) {
    cout << n << " ";
  }
  cout << "\n";
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      int plen = p.length();
      if(s.length() < plen) {
        return {};
      }
      
      array<short int, 28> anagramFrequency;
      anagramFrequency.fill(0);
      for(char c: p) {
        anagramFrequency[c - 0x60]++;
      }

      vector<int> result;
      int lastIdx = s.length() - plen;
      for(int i = 0; i <= lastIdx ; ++i) {
        auto c = s[i];
        if (anagramFrequency[c - 0x60] > 0) {
          auto wordFreq = anagramFrequency;
          int count = plen;
          for(int j = i; j < s.length(); ++j) {
            if((--wordFreq[s[j] - 0x60]) < 0) {
              break;
            }
            if (--count == 0) {
              result.push_back(i);
              for(int k = i; k < lastIdx; ++k) {
                if(s[k] == s[k + plen]) {
                  result.push_back(i = (k+1));
                }
                else
                  break;
              }
              break;
            }
          }
        }
      }
      return result;
    }
};

int main() {
  
  string s("cbaebabacd");
  string  p("abc");

  Solution sol;
  auto r = sol.findAnagrams(s, p);

  printVector(r);

  string s2("abab");
  string  p2("ab");

  Solution sol2;
  auto r2 = sol2.findAnagrams(s2, p2);

  printVector(r2);


  return 0;
}