#include <iostream>
#include <queue>
using namespace std;

int num[10000];
bool visited[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, a, b;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  cin >> a >> b;
  --a; --b;

  int ans = 0;
  queue<int> Q;
  Q.push(a);
  visited[a] = true;
  while (!Q.empty()) {
    int qsize = Q.size();
    while (qsize--) {
      int here = Q.front();
      Q.pop();

      if (here == b) {
        cout << ans << '\n';
        return 0;
      }

      int jump = num[here];
      while (0 <= here - jump || here + jump < n) {
        if (here - jump >= 0 && !visited[here - jump]) {
          Q.push(here - jump);
          visited[here - jump] = true;
        }
        if (here + jump < n && !visited[here + jump]) {
          Q.push(here + jump);
          visited[here + jump] = true;
        }
        jump += num[here];
      }
    }
    ++ans;
  }

  cout << -1 << '\n';
}
