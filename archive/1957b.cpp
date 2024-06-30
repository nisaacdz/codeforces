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
    int n, k;
    cin>>n>>k;

    if (n == 1) {
        cout << k << ENDL;
        return;
    } else if (k == 1) {
        cout << 1 << ' ';
        for (int i = 1; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << ENDL;
        return;
    }

    int first = -1, second = 0;
    for (int i = 31; i >= 0; i--) {
        if (first == -1) {
            first = (k & (1 << i)) - 1;
        } else {
            second = second | (k & (1 << i));
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << first << ' ';
        } else if (i == 1) {
            cout << (second + 1) << ' ';
        } else {
            cout << 0 << ' ';
        }
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