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

void solve(string& s)
{
    vector<int> balances(s.length());
    int pb = 0;
    for (int i = 0; i < s.length(); i++) {
        balances[i] = pb;
        pb += s[i] == '(' ? 1 : - 1;
    }
    vector<int> indices(s.length());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&s, &balances](int a, int b) {
        if (balances[a] == balances[b]) return b < a;
        else return balances[a] < balances[b];
    });

    string res;
    for (int idx: indices) {
        res.push_back(s[idx]);
    }
    cout << res << ENDL;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    solve(s);
    return 0;
}