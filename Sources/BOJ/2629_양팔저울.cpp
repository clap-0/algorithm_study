#include <iostream>
using namespace std;
int N;
int weight[30];
bool dp[31][15001];
//주어진 추를 이용하여 측정할 수 있는 모든 무게를 미리 확인해본다
void preMeasure(int n, int k){
  //모든 추를 전부 확인했거나
  //이미 n-1번 추까지 사용해서 무게가 k가 되는 경우를 확인했다면 패스
  if(n>N || dp[n][k]) return;
  dp[n][k]=true;
  //n번 추는 사용하지 않는다
  preMeasure(n+1, k);
  //n번 추를 구슬 반대편에 놓는다
  preMeasure(n+1, k+weight[n]);
  //n번 추를 구슬이 있는 접시에 놓는다
  preMeasure(n+1, abs(k-weight[n]));
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N;
  for(int i=0; i<N; i++) cin >> weight[i];
  //가능한 모든 경우를 미리 확인한다
  preMeasure(0, 0);
  int M;
  cin >> M;
  while(M--){
    int bead;
    cin >> bead;
    if(bead>15000 || !dp[N][bead]) cout << "N ";
    else cout << "Y ";
  }
}
