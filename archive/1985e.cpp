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
    ll x, y, z, k;
    cin>>x>>y>>z>>k;
    ll ans = 0;
    for (ll a = 1; a <= x; a++) {
        for (ll b = 1; b <= y; b++) {
            if (k % (b * a) != 0) continue;
            ll c = k / (a * b);
            if (c > z) continue;
            ll res = (x - a + 1) * (y - b + 1) * (z - c + 1);
            ans = max(ans, res);
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