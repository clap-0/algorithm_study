#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 역방향으로 이동하는 사람의 {목적지, 출발지}를 저장한다
// 역방향이므로 (목적지좌표 < 출발지좌표)를 만족한다
vector<pair<int,int> > backward;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    int u, v;
    cin >> u >> v;
    if(u > v) backward.push_back({v, u});
  }

  sort(backward.begin(), backward.end());

  //상근이는 0에서 M까지 가야하므로 기본적으로 M만큼의 거리는 이동해야한다
  long long ans = M;
  int left = 0, right = 0;
  for(auto &p : backward) {
    // start > end를 만족한다
    int start = p.second, end = p.first;
    if(end <= right) right = max(right, start);
    // 이번 사람이 기존까지 찾은 사람의 이동경로와 겹치지 않는 경우
    // 기존에 경로가 겹치던 사람들을 모두 도착지에 내려주고 온다.
    else {
      ans += 2LL * (right - left);
      left = end, right = start;
    }
  }
  ans += 2LL * (right - left);
  cout << ans << '\n';
}
