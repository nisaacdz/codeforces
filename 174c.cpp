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

void handle_test_case() {
    int n;
    cin >> n;
    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (nums.empty() || nums[nums.size() - 1].first != val) {
            nums.push_back({ val, 1});
        } else {
            nums[nums.size() - 1].second += 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i].second >= 3) {
            ans += i > 0;
            ans += i < nums.size() - 1;
        }
        if (nums[i].second >= 2 && i > 0 && nums[i - 1].second >= 2) {
            ans += 1;
        }
    }

    cout << ans << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) handle_test_case();
    
    return 0;
}