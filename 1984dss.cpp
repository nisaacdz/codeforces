#include<bits/stdc++.h>
 
typedef long long LL;
using namespace std;
const int MOD = 998244353;
 
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (count(s.begin(), s.end(), 'a') == n) {
        cout << n - 1 << endl;
        return;
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            a.emplace_back(i);
        }
    }
    int m = a.size();
    LL ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (m % i) {
            continue;
        }
        int ok = 1;
        for (int j = i; j < m; ++j) {
            int o = j % i;
            if (s[a[j]] != s[a[o]] || (o && a[o] - a[o - 1] != a[j] - a[j - 1])) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            int mi = n;
            for (int j = i; j < m; j += i) {
                mi = min(mi, a[j] - a[j - 1] - 1);
            }
            int r = n - a.back() - 1;
            for (int l = 0; l <= a[0]; ++l) {
                ans += max(0, min(r + 1, mi - l + 1));
            }
        }
    }
    cout << ans << endl;
}
 
 
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}