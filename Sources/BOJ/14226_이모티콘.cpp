#include <iostream>
#include <queue>
using namespace std;

bool visited[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int S;
  cin >> S;

  queue<pair<int,int> > Q;
  Q.push({1, 0});
  visited[1][0] = true;
  int ans = 0;
  while(!Q.empty()) {
    int qsize = Q.size();
    while(qsize--) {
      int len = Q.front().first, clipboard = Q.front().second;
      Q.pop();

      // S개의 이모티콘을 만든 경우
      if(len == S) {
        cout << ans << '\n';
        return 0;
      }

      // 복사
      if(!visited[len][len]) {
        visited[len][len] = true;
        Q.push({len, len});
      }

      // 삭제
      if(len > 1 && !visited[len - 1][clipboard]) {
        visited[len - 1][clipboard] = true;
        Q.push({len - 1, clipboard});
      }

      // 붙여넣기
      if(len + clipboard <= S && !visited[len + clipboard][clipboard]) {
        visited[len + clipboard][clipboard] = true;
        Q.push({len + clipboard, clipboard});
      }
    }
    ++ans;
  }
}
