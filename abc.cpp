#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    unordered_map<string, pair<int, int>> table;
    for (int i = 0; i < 12; i++) {
        string t1, t2, vs;
        int g1, g2;
        cin>>t1>>g1>>vs>>g2>>t2;
        if (g1 > g2) {
            table[t1].first += 3;
            table[t1].second += g1 - g2;
            table[t2].second += g2 - g1;
        } else if (g1 < g2) {
            table[t2].first += 3;
            table[t2].second += g2 - g1;
            table[t1].second += g1 - g2;
        } else {
            table[t1].first += 1;
            table[t2].first += 1;
        }
        vector<pair<string, pair<int, int>>> records;
        for (const auto& [team, val]: table) {
            records.push_back({team, val});
        }
        sort(records.begin(), records.end(),
              [](const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
                  const auto& t1 = a.second;
                  const auto& t2 = b.second;
                  if (t1.first < t2.first) {
                      return false;
                  } else if (t2.first < t1.first) {
                      return true;
                  } else {
                      return t1.second > t2.second;
                  }
              });
        
        cout << records[0].first << " " << records[1].first;
    }
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)solve();
}