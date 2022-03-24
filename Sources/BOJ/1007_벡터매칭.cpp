#include <iostream>
#include <cmath>
using namespace std;

int N;
pair<int,int> points[20];
// isEndPoint[i] = i번째 점이 벡터의 끝점인지 여부
bool isEndPoint[20];
double ans;

void solve(int idx, int cnt) {
  if(cnt == N / 2) {
    int y = 0, x = 0;
    for(int i = 0; i < N; i++)
      if(isEndPoint[i]) y += points[i].first, x += points[i].second;  // i가 끝점이면 벡터 연산에 따라 점의 좌표를 더한다
      else y -= points[i].first, x -= points[i].second;               // i가 시작점이면 벡터 연산에 따라 점의 좌표를 뺀다
    ans = min(ans, sqrt(1LL * y * y + 1LL * x * x));
    return;
  }

  // N개의 점중에서 N/2개의 점을 고르는 모든 경우의 수를 구한다 
  for(int i = idx; i < N; i++) {
    isEndPoint[i] = true;
    solve(i + 1, cnt + 1);
    isEndPoint[i] = false;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  cout << fixed;
  cout.precision(6);
  while(T--) {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
    ans = 1e9;
    solve(0, 0);
    cout << ans << '\n';
  }
}
