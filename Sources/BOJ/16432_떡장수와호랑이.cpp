#include <iostream>
using namespace std;

int N;
bool hasCake[1001][10], visited[1001][10];
int ans[1000];

bool dfs(int day, int cake) {
  // N일동안 잡아먹히지 않고 떡을 주는 방법이 있는 경우 true 반환
  if(day == N) return true;
  
  // 다음날에 어떤 떡을 줄 지 정한다
  // (day+1)일에 k번 떡을 주었던 적이 있는 경우(visited[day+1][k] == true), 해당 떡을 주면 나중에 죽는다는 뜻이므로 다른 떡을 준다
  for(int i = 1; i < 10; i++) 
    if(hasCake[day + 1][i] && !visited[day + 1][i] && i != cake) {
      visited[day + 1][i] = true;
      // N일동안 사는 방법을 찾은 경우, 탐색을 종료한다
      if(dfs(day + 1, i)) {
        ans[day] = i;
        return true;
      }
    }
  
  // 살 수 있는 방법이 없다
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    int m;
    cin >> m;
    while(m--) {
      int cake;
      cin >> cake;
      hasCake[i][cake] = true;
    }
  }

  if(dfs(0, 0)) {
    for(int i = 0; i < N; i++) cout << ans[i] << '\n';
  }
  else cout << -1 << '\n';
}
