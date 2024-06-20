#include<bits/stdc++.h>

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

typedef long long ll;
typedef long double ld;
using namespace std;


class Solution {
public:
    static bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        int n = s3.length();
        int m = s1.length();
        int x = s2.length();
        vector<vector<pair<bool, bool>>> dp(n + 1, vector<pair<bool, bool>>(m + 1, {false, false}));
        dp[0][0] = {true, true};
        
        // dp[i][j].first represents we can find an interleaving of first j chars of 
        // s1 and the remaining i - j chars of s2 to form s3 such that the interleaving
        // ends with some substring of s1
        
        for (int i = 1; i <= n; i++) {
            for (int j = max(0, i - x); j <= min(i, m); j++) {
                bool res1 = false, res2 = false;
                int k = i - j;
                for (int l = 1; l <= j && !res1; l++) {
                    res1 = s3.substr(i - l, i) == s1.substr(j - l, j) && dp[i - l][j - l].second;
                }
                for (int l = 1; l <= (i - j) & !res2; l++) {
                    res2 = s3.substr(i - l, i) == s2.substr(k - l, k) && dp[i - l][j].first;
                }
                dp[i][j].first = res1;
                dp[i][j].second = res2;
            }
        }
        
        return dp[n][m].first || dp[n][m].second;
    }
};

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    bool res = Solution::isInterleave(s1, s2, s3);
    if (res) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}