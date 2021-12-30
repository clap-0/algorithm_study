#include <iostream>
#include <queue>
using namespace std;

const int dr[6] = {-2, -2, 0, 0, 2, 2}, dc[6] = {-1, 1, -2, 2, -1, 1};
bool discovered[200][200];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  pair<int, int> s, e;
  cin >> N >> s.first >> s.second >> e.first >> e.second;
  
  // 너비우선탐색 알고리즘
  queue<pair<int,int> > Q;
  int ans = 0;
  Q.push(s);
  while(!Q.empty()) {
    int qsize = Q.size();
    for(int i=0; i<qsize; i++){
      pair<int,int> curr = Q.front(); Q.pop();
      if(curr == e) {
        cout << ans << '\n';
        return 0;
      }
      int r = curr.first, c = curr.second;
      for(int d=0; d<6; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if(nr < 0 || nc < 0 || nr >= N || nc >= N || discovered[nr][nc]) continue;
        discovered[nr][nc] = true;
        Q.push({nr, nc});
      }
    }
    ++ans;
  }
  cout << -1 << '\n';
}
