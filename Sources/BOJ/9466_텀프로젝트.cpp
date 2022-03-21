#include <iostream>
#include <cstring>
using namespace std;

// edge[i] = i번 학생이 선택한 학생의 번호
int edge[100001];
bool visited[100001];
bool finished[100001];

// SCC를 구하는 알고리즘을 응용하여
// curr노드를 루트로 하는 서브트리에서
// 아직 발견한 적 없는 사이클을 이루는 노드의 개수를 구한다
int getCycleSize(int curr) {
  visited[curr] = true;
  int ret = 0;
  int next = edge[curr];
  // next가 아직 방문한 적 없는 노드인 경우 방문한다
  if(!visited[next]) ret += getCycleSize(next);
  // next가 curr의 조상노드인 경우 사이클이므로 next에서 curr까지의 노드의 개수를 구한다
  else if(!finished[next]) {
    ++ret;
    for(int k = next; k != curr; k = edge[k]) ++ret;
  }
  
  finished[curr] = true;
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> edge[i];

    // 초기화
    memset(visited, 0, sizeof(visited));
    memset(finished, 0, sizeof(finished));
    
    // 전체 학생수에서 사이클을 이루는 학생들의 수를 뺀다
    int ans = n;
    for(int i = 1; i <= n; i++)
      if(!visited[i]) 
        ans -= getCycleSize(i);
    cout << ans << '\n';
  }
}
