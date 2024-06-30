#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

const char ENDL = '\n';
const ll MOD = 1e9 + 7;

void solve()
{
    int n, h;
    cin>>n>>h;
    vector<int> damages(n), resting(n);

    for (int& d: damages) cin>>d;
    for (int& r: resting) cin>>r;

    set<pair<ll, int>> powers;
    for (int i = 0; i < n; i++) {
        powers.insert({1, i});
    }

    ll max_turn = 0;

    while (h > 0) {
        auto ptr = powers.begin();
        auto [turn, idx] = *ptr;
        powers.erase(ptr);
        h -= damages[idx];
        max_turn = turn;
        powers.insert({turn + resting[idx], idx});
    }

    cout << max_turn << ENDL;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}