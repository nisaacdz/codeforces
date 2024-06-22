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
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    int a = nums[0];
    int b = nums[1];
    int i = 2;
    while (i < nums.size() && (b % a == 0)) {
        b = nums[i++];
    }

    bool res = true;
    while (i < nums.size() && res) {
        res = nums[i] % a == 0 || nums[i] % b == 0;
        i++;
    }

    if (res) {
        cout << "Yes" << ENDL;
    } else {
        cout << "No" << ENDL;
    }
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