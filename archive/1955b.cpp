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
    int n, c, d, v;
    cin>>n>>c>>d;
    int a = INT_MAX;
    unordered_multiset<int> nums;
    for (int i = 0; i < n * n; i++) {
        cin>>v;
        a = min(a, v);
        nums.insert(v);
    }
    bool res = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto pp = nums.find(a + (i * c) + (j * d));
            if (pp == nums.end()) {
                res = false;
            } else {
                nums.erase(pp);
            }
        }
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