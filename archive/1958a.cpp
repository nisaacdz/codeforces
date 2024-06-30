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
    // 3x + 5y <= n
    // I want the integer values of x and y that makes 3x + 5y maximum
    // 0, 3, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    int res = INT_MAX;

    for (int i = 0; i <= n/5; i++) {
        for (int j = 0; j <= n/3; j++) {
            if (5*i + 3*j <= n) res = min(res, n - (5*i + 3*j));
        }
    }

    cout << res << ENDL;
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