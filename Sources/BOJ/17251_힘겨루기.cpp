#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  pair<int,int> left={0,-1}, right={0,-1};
  cin >> N;
  // N개의 수에서 왼쪽 반중에 제일 큰 수와 인덱스, 오른쪽 반중에 제일 큰 수와 인덱스 번호를 구한다
  for(int i=0; i<N; i++){
    int str;
    cin >> str;
    if(i<N/2 && left.first<str) left={str, i};
    if(i>=N/2 && right.first<=str) right={str, i};
  }
  // 범위 내의 가장 큰 수의 위치에 따라 승패가 갈리게 된다
  // 예를 들어 1 2 3 BIG 5 6 7 8 9 10 이라고 하면 왼쪽팀(홍팀)은 기준선이 BIG이전에 있는 3번은 지고 나머지는 이기게 된다
  // 따라서 가장 큰 수가 왼쪽에 가까우면 홍팀이, 오른쪽에 가까우면 청팀이 이기게 된다
  if(left.first!=right.first) cout << (left.first>right.first ? "R" : "B") << endl;
  // 가장 큰 수가 두 개 이상인 경우도 팀 내의 가장 큰 수를 제외한 다른 수를 사용하지 않으므로
  // 홍팀에서 왼쪽에 가장 가까운 큰 수와 청팀에서 오른쪽에 가장 가까운 큰 수의 위치를 비교해 끝에 더 가까운 팀이 승리하게 된다
  // 예를 들어 BIG 2 3 4 5 6 7 8 BIG 10 의 경우 기준선이 두 BIG의 오른쪽에 있을 때를 제외하고 무승부가 되어 홍팀이 승리한다
  else cout << (left.second<N-1-right.second ? "R" : (left.second>N-1-right.second ? "B" : "X")) << endl;
}
