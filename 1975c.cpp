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
typedef long long ll;
typedef long double ld;
using namespace std;

int median(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3) {
        return max(num2, num3);
    } else if (num2 >= num1 && num2 >= num3) {
        return max(num1, num3);
    } else {
        return max(num1, num2);
    }
}

void handle_test_case() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;

    if (nums.empty()) {
        ans = 0;
    } else if (nums.size() == 2) {
        ans = min(nums[0], nums[1]);
    } else {
        for (int i = 2; i < n; i++) {
            ans = max(ans, median(nums[i], nums[i - 1], nums[i - 2]));
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