#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> ans;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  adj = vector<vector<int> >(N, vector<int>());
  ans = vector<int>(N);
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    // 사전순으로 가장 앞서도록 칠해야하므로
    // 번호가 큰 건물이 번호가 작은 건물만 참고하도록 한다.
    if (u < v)
      swap(u, v);
    adj[u - 1].push_back(v - 1);
  }

  for (int i = 0; i < N; i++)
    for (int color = 1; ; color++)
    {
      ans[i] = color;
      // 자신보다 번호가 작은 건물들 중에 색이 color인 건물이 있는지 확인한다.
      bool hasSame = false;
      for (int connected : adj[i])
        if (ans[connected] == color)
        {
          hasSame = true;
          break;
        }
      // 색이 color인 건물이 없다면 i번 건물의 색깔을 color로 칠한다.
      if (!hasSame)
        break;
    }

  for (int i = 0; i < N; i++)
    cout << ans[i] << ' '; 
}
