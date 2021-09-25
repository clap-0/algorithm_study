#include <iostream>
#include <cstring>
using namespace std;
int N, M, K;
int orangeSize[20000];
long long cache[20000];
// DP를 이용하여 start부터 N까지의 오렌지를 상자에 나눠서 넣는 최소비용을 구한다
long long packingCost(int start){
  //기저사례: 모든 오렌지를 상자에 나눈 경우 0반환
  if(start==N) return 0;
  //메모이제이션
  long long& ret = cache[start];
  if(ret!=-1) return ret;
  ret=1e18;
  //start부터 i개의 오렌지를 상자에 넣을 때의 비용을 구한다
  int biggest = orangeSize[start], smallest = orangeSize[start];
  for(long long i=1; i<=M; i++)
    if(start+i<=N){
      biggest = max(biggest, orangeSize[start+i-1]);
      smallest = min(smallest, orangeSize[start+i-1]);
      ret = min(ret, K+i*(biggest-smallest) + packingCost(start+i));
    }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> M >> K;
  for(int i=0; i<N; i++) cin >> orangeSize[i];
  memset(cache, -1, sizeof(cache));
  cout << packingCost(0) << '\n';
}
