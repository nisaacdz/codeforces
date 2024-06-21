#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

const char ENDL = '\n';
const ll MOD = 1e9 + 7;

template <typename T>
void printVector(const std::vector<T> &vec, const std::string &delimiter = ", ")
{
    if (vec.empty())
    {
        std::cout << "[]";
        return;
    }

    std::cout << "[";
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        std::cout << vec[i] << delimiter;
    }
    std::cout << vec[vec.size() - 1] << "]";
}

void solve()
{
    unsigned long long x;
    cin>>x;
    
    vector<int> nums(31, 0);

    for (int i = 0; i <= 30; i++) {
        if ((x & (1 << i)) != 0) {
            if (nums[i] == 1) {
                nums[i] = 0;
                nums[i + 1] = 1;
            } else if (i > 0 && nums[i - 1] == 1) {
                nums[i - 1] = -1;
                nums[i + 1] = 1;
            } else {
                nums[i] = 1;
            }
        } 
    }

    cout << nums.size() << ENDL;

    for (int num: nums) {
        cout << num << ' ';
    }

    cout << ENDL;
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