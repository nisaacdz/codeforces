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
    int n, m;
    string val;
    cin >> n >> m;
    vector<string> grid;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        grid.push_back(val);
    }

    bool res = (grid[0][0] == grid[n - 1][m - 1]) || (grid[n - 1][0] == grid[0][m - 1]);

    if (grid[0][0] == grid[n - 1][0])
    {
        for (int i = 0; i < n; i++)
        {
            res = res || (grid[i][0] != grid[0][0]);
        }
    }

    if (grid[0][0] == grid[0][m - 1])
    {
        for (int j = 0; j < m; j++)
        {
            res = res || (grid[0][j] != grid[0][0]);
        }
    }

    if (grid[n - 1][m - 1] == grid[n - 1][0])
    {
        for (int j = 0; j < m; j++)
        {
            res = res || (grid[n - 1][j] != grid[n - 1][m - 1]);
        }
    }

    if (grid[n - 1][m - 1] == grid[0][m - 1])
    {
        for (int i = 0; i < n; i++)
        {
            res = res || (grid[i][m - 1] != grid[n - 1][m - 1]);
        }
    }

    if (res)
    {
        cout << "Yes" << ENDL;
    }
    else
    {
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