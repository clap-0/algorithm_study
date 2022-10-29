#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    pair<int,int> point;
    vector<pair<int,int> > stores(n);
    queue<pair<int,int> > Q;
    cin >> point.first >> point.second;
    Q.push(point);
    for (int i = 0; i < n; i++)
      cin >> stores[i].first >> stores[i].second;
    cin >> point.first >> point.second;

    bool canReach = false;
    vector<bool> visited(n, false);
    while (!Q.empty())
    {
      int x = Q.front().first, y = Q.front().second;
      Q.pop();
      if (abs(x - point.first) + abs(y - point.second) <= 1000)
      {
        canReach = true;
        break;
      }
      for (int i = 0; i < stores.size(); i++)
      {
        int nx = stores[i].first, ny = stores[i].second;
        if (!visited[i] && abs(x - nx) + abs(y - ny) <= 1000)
        {
          visited[i] = true;
          Q.push({ny, nx});
        }
      }
    }
    cout << (canReach ? "happy\n" : "sad\n");
  }
}
