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
#include <vector>

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

typedef long long ll;
typedef long double ld;
using namespace std;

ll findmax(const vector<ll>& mvals) {
    ll sum = 0, ml = 0, mr = mvals.size() - 1;
    while (ml < mr) {
        if (mvals[ml] < 0) {
            ml++;
        } else if (mvals[mr] < 0) {
            mr--;
        } else {
            sum += mvals[ml++] + mvals[mr--];
        }
    }
    if (ml == mr && mvals[ml] > 0) sum += mvals[ml];
    return sum;
}

void solve() {
    int n, m;
    cin >> n;
    vector<ll> nvals(n);
    for (int i = 0; i < n; i++) {
        cin >> nvals[i];
    }
    cin >> m;
    vector<ll> mvals(m);
    for (int i = 0; i < m; i++) {
        cin >> mvals[i];
    }
    
    ll sum = findmax(mvals);
    ll ans = sum;
    
    ll cur = sum;
    for (int i = 0; i < n; i++) {
        cur = max(cur + nvals[i], nvals[i]);
        ans = max(ans, cur);
    }
    
    nvals.push_back(sum);
    cur = 0;
    for (int i = 0; i < n; i++) {
        cur = max(cur + nvals[i], nvals[i]);
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
