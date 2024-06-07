#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

void handle_test_case()
{
    int n;
    cin >> n;

    vector<char> instructions(n);

    for (int i = 0; i < n; i++)
    {
        cin >> instructions[i];
    }

    int X = 0, Y = 0;

    for (int i = 0; i < n; i++)
    {
        if (instructions[i] == 'N')
        {
            Y += 1;
        }
        else if (instructions[i] == 'S')
        {
            Y -= 1;
        }
        else if (instructions[i] == 'E')
        {
            X += 1;
        }
        else
        {
            X -= 1;
        }
    }
    if (instructions.size() < 2 || (instructions.size() == 2 && (X == 0 || Y == 0)) || (X % 2) != 0 || (Y % 2) != 0) {
        cout << "NO" << endl;
    }
    else
    {
        string ans;
        // SNNNNN
        /*
            Y = 4
            Y = 6,
            Y = 4,
            Y = 2,
            Y = 0,
        */
        for (int i = 0; i < n; i++)
        {
            if (instructions[i] == 'N')
            {
                if (Y == 0)
                    ans.push_back('R');
                else
                {
                    ans.push_back('H');
                    Y -= 2;
                }
            }
            else if (instructions[i] == 'S')
            {
                if (Y == 0)
                    ans.push_back('R');
                else
                {
                    ans.push_back('H');
                    Y += 2;
                }
            }
            else if (instructions[i] == 'E')
            {
                if (X == 0)
                    ans.push_back('R');
                else
                {
                    ans.push_back('H');
                    X -= 2;
                }
            }
            else
            {
                if (X == 0)
                    ans.push_back('R');
                else
                {
                    ans.push_back('H');
                    X += 2;
                }
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        handle_test_case();

    return 0;
}