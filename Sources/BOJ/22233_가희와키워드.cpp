#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

int n, m;
string text, keyword;
unordered_set<string> us;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> keyword;
    us.insert(keyword);
  }
  for (int i = 0; i < m; i++) {
    cin >> text;
    istringstream ss(text);
    while (getline(ss, keyword, ',')) {
      auto it = us.find(keyword);
      if (it != us.end())
        us.erase(it);
    }
    cout << us.size() << '\n';
  }
}
