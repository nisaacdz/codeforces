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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

using namespace std;

typedef long long ll;
typedef long double ld;

const char ENDL = '\n';

template <typename T>
void printVector(const std::vector<T> &vec, const std::string &delimiter = ", ")
{
  if (vec.empty())
  {
    std::cout << "[]" << ENDL;
    return;
  }

  std::cout << "[";
  for (size_t i = 0; i < vec.size() - 1; ++i)
  {
    std::cout << vec[i] << delimiter;
  }
  std::cout << vec[vec.size() - 1] << "]" << ENDL;
}

void solve()
{
  string s;
  cin >> s;
  int dict[26] = {0};
  for (char c : s)
  {
    dict[c - 'a']++;
  }

  vector<int> ccc;
  for (int i = 0; i < 26; i++)
  {
    if (dict[i] > 0)
      ccc.push_back(dict[i]);
  }

  std::sort(ccc.begin(), ccc.end());

  printVector(ccc);

  bool yes = true;
  for (int i = 2; i < ccc.size() && yes; i++)
  {
    yes = (ccc[i] == ccc[i - 1] + ccc[i - 2]) || (i == 3 ? ccc[i] == ccc[i - 1] + ccc[i - 3] : false);
  }

  if (yes)
  {
    cout << "Dynamic" << endl;
  }
  else
  {
    cout << "Not" << endl;
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
}
