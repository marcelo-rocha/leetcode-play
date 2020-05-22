#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
      vector<int> freq(0x60, 0);
      for(char c: s) {
        freq[c - 0x20] += 1;
      }
      
      multimap<int, char, greater<int>> chars;
      int f;
      for(int i = 0; i < freq.size(); ++i) {
        if((f = freq[i]) > 0) {
          chars.emplace(f, i + 0x20);
        }
      }

      string r;
      r.reserve(s.size());
      for (auto it = chars.cbegin(); it != chars.cend(); ++it) {
        for(int j = 0; j < it->first; ++j) {
          r.push_back(it->second);
        }
      }

      return r;
    }
};


int main() {
  Solution s;
  cout << s.frequencySort("Aaaaabb") << "\n";
  return 0;
}