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
    string s;
    cin >> s;
    int res = 0;
    int cary = 0;
    char prev = s[s.length() - 1];
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != prev)
        {
            prev = s[i];
            if (s[i] == '0')
                cary += 1;
            else
                res += 1;
        }
    }
    cout << 1 + res + max(0, cary - 1) << endl;
}

/*
11010
00000000
1
10
0001111
0110
*/

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