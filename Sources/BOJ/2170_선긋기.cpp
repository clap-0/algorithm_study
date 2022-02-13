#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> lines[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> lines[i].first >> lines[i].second;
  sort(lines, lines + N);

  // 스위핑 알고리즘을 이용하여
  // 선의 시작지점 기준으로 오름차순 정렬된 선들의 집합을 순회하며
  // 이전에 그은 [left, right] 범위의 선과 겹치면 이번 선분과 합치고
  // 겹치지 않는다면 기존에 그린 선의 길이만큼의 값을 ans에 더하고, [left, right]를 이번 선분으로 초기화시킨다
  int ans = 0;
  int left, right;
  left = right = -1e9 - 1;
  for(int i = 0; i < N; i++) {
    if(right < lines[i].first) {
      ans += right - left;
      left = lines[i].first, right = lines[i].second;
    }
    else 
      right = max(right, lines[i].second);
  }
  ans += right - left;
  
  cout << ans << '\n';
}
