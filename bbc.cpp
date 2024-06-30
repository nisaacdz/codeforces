#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

const char ENDL = '\n';
const ll MOD = 1e9 + 7;

void solve()
{
    int n, k, num;
    cin>>n>>k;
    unordered_map<int, multiset<int>> mods;
    for (int i = 0; i < n; i++) {
        cin>>num;
        mods[num % k].insert(num);
    }
    int fails = 0;
    for (const auto& [mod, set]: mods) {
        fails += (set.size() & 1);
    }

    if (fails > 1) {
        cout << -1 << ENDL;
        return;
    }

    ll ans = 0;


    for (const auto& [mod, set]: mods) {
        int prev = -1;

        vector<int> nums;
        for (int num: set) {
            nums.push_back(num);
        }
        if (nums.size() % 2 == 1) {
            for (int i = 0; i < n; i++) {
                
            }
        }
        int left = 0, right = nums.size() - 1;
        while (right > left) {
            if (nums[right] - nums[right - 1] > nums[left + 1] - nums[left]) {
                ans += (nums[left + 1] - nums[left]) / k;
                left += 2;
            } else {
                ans += (nums[right] - nums[right - 1]) / k;
                right -= 2;
            }
        }
    }

    cout << ans << ENDL;

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

/*
0
83966524
1
4
7
1
48
-1
0
14
0
*/