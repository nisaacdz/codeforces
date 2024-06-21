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
    int x, y;
    cin >> x >> y;
    ll res = 0;
    while (x > 0 || y > 0)
    {
        if ((x & 1) == (y & 1))
        {
            res += 1;
            x = x >> 1, y = y >> 1;
        }
        else
        {
            break;
        }
    }

    res = 1 << res;
    cout << res << endl;
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