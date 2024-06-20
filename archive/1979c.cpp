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


ll hcf(ll a, ll b) {
    if (b == 0) return a;
    return hcf(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / hcf(a, b);
}

void solve()
{
    int n, v;
    cin>>n;
    vector<ll> odds(n);
    for (int i = 0; i < n; i++) {
        cin>>odds[i];
    }

    ll den = odds[0];

    for (int i = 1; i < n; i++) 
        den = lcm(odds[i], den);

    for (int i = 0; i < n; i++) 
        odds[i] = den / odds[i];

    if (accumulate(odds.begin(), odds.end(), 0) >= den) {
        cout << -1 << ENDL;
    } else {
        for (int odd: odds) {
            cout << odd << ' ';
        }
        cout << ENDL;
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