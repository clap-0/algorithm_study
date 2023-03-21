#include <iostream>
#include <vector>

using namespace std;

int N;
int jump[100000];
bool visited[100000];

int dfs(int here)
{
  visited[here] = true;
  int ret = 1;
  if (here - jump[here] >= 0 && !visited[here - jump[here]]) {
    ret += dfs(here - jump[here]);
  }
  if (here + jump[here] < N && !visited[here + jump[here]]) {
    ret += dfs(here + jump[here]);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int s;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> jump[i];
  }
  cin >> s;

  cout << dfs(s - 1) << '\n';
}
