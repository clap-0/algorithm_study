#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[200001];  // 인접리스트
// believers[i] = i번 사람 주변인 중 루머를 믿는 사람들의 수
// believedTime[i] = i번 사람이 루머를 믿은 시간
int believers[200001], believedTime[200001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N;
  for(int i = 1; i <= N; i++)
  {
    int j;
    while(true)
    {
      cin >> j;
      if(!j) break;
      adj[i].push_back(j);
    }
  }

  memset(believedTime, -1, sizeof(believedTime));
  queue<int> Q;
  cin >> M;
  // 루머 유포자들을 큐에 넣는다.
  for(int i = 0; i < M; i++)
  {
    int rumormonger;
    cin >> rumormonger;
    Q.push(rumormonger);
    believedTime[rumormonger] = 0;
  }

  int time = 1;
  while(!Q.empty())
  {
    int qSize = Q.size();
    while(qSize--)
    {
      int believer = Q.front();
      Q.pop();
      // believer의 주변인 중 루머를 믿지 않으면서 주변인의 절반 이상이 루머를 믿는 사람이 있으면
      // 루머를 믿기 시작했으므로 큐에 넣는다.
      for(int friends : adj[believer])
        if(believedTime[friends] == -1 && ++believers[friends] * 2 >= adj[friends].size())
        {
          Q.push(friends);
          believedTime[friends] = time;
        }
    }
    ++time;
  }

  for(int i = 1; i <= N; i++)
    cout << believedTime[i] << ' ';
}
