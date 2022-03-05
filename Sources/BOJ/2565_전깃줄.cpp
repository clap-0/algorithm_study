#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
P wires[100];
int dp[100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    wires[i] = P(a, b);
  }

  // 전깃줄을 전봇대 A와 연결된 위치에 대하여 오름차순으로 정렬한다
  sort(wires, wires + N, [](P& a, P& b) {
    return a.first < b.first;
  });

  // lis : 정렬된 wires 배열에서 각각의 전봇대 B와 연결된 위치들로 수열 arr를 만들었을 때
  // arr에서 가장 긴 증가하는 부분수열(LIS)의 길이
  int lis = 0;
  
  // arr에 대하여 LIS를 구한다
  // dp[i] = 범위 arr[..i]에서 arr[i]를 포함하는 LIS의 길이
  for(int i = 0; i < N; i++) {
    int curr = wires[i].second;
    dp[i] = 1;
    for(int j = i - 1; j >= 0; j--)
      if(wires[j].second < curr) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    lis = max(lis, dp[i]);
  }

  cout << N - lis << '\n';
}
