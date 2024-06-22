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
    vector<int> a(n);
    vector<int> b(n + 1);
    
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i <= n; i++) {
        cin>>b[i];
    }

    ll shifts = 0;
    for (int i = 0; i < n; i++) {
        shifts += abs(b[i] - a[i]);
    }
    ll last_op = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x = min(a[i], b[i]), y = max(a[i], b[i]);
        ll k = b[n] > y ? (b[n] - y): (b[n] < x ? x - b[n]: 0);
        last_op = min(last_op, 1 + k);
    }

    cout << shifts + last_op << ENDL;
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