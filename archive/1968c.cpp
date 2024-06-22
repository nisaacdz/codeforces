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
    vector<int> nums(n,  0);
    for (int i = 1; i < n; i++) {
        cin>>nums[i];
    }
    nums.push_back(nums[n - 1] + 1);
    vector<int> res(n, 0);
    res[0] = nums[1] + 1;

    for (int i = 1; i < n; i++) {
        int d = nums[i + 1] / res[i - 1];
        res[i] = nums[i] + (d * res[i - 1]  + res[i - 1]);
    }

    for (int num: res) {
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