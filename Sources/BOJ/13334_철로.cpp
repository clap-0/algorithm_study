#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int,int> lines[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, d;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    // 도착지(s와 e중 더 오른쪽에 있는 곳)을 기준으로 오름차순 정렬을 하기 위해
    // s와 e를 lines[i]에 거꾸로 삽입했다
    if(s < e) lines[i] = {e, s};
    else lines[i] = {s, e};
  }
  cin >> d;
  sort(lines, lines + n);

  int ans = 0;
  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i = 0; i < n; i++) {
    int end = lines[i].first, start = end - d;
    // 출발지와 도착지 사이의 거리가 d를 초과하는 경우
    if(lines[i].second < start) continue;
    while(!pq.empty() && pq.top() < start) pq.pop();
    pq.push(lines[i].second);
    ans = max(ans, (int)pq.size());
  }
  cout << ans << '\n';
}
