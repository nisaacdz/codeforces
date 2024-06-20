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
    ll v;
    cin>>v;
    bool res = (v % 10) < 9;
    v /= 10;

    while (v > 10 && res) {
      res = (v % 10) > 0 && (v % 10) < 10;
      v /= 10;
    }

    cout << res << endl;

    res &= v == 1;

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