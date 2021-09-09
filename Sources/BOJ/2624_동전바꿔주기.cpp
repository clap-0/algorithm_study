#include <iostream>
#include <cstring>
using namespace std;
int p[100], n[100];
int cache[10001][100];
//DP를 이용하여 t원을 k종류의 동전들을 이용하여 교환하는 방법의 수를 구한다
int solve(int t, int k){
  //기저사례: 교환하는 방법을 하나 찾은 경우 1반환
  if(t==0) return 1;
  //기저사례: 교환을 못했는데 더 사용할 동전 종류도 없는 경우 0반환
  if(k==-1) return 0;
  //메모이제이션
  int& ret=cache[t][k];
  if(ret!=-1) return ret;
  ret=0;
  //k번째 동전종류를 사용해 교환을 하고 남은 액수는 k-1이하번째 동전들로 교환한다
  for(int coins=0; coins<=n[k]; coins++)
    if(p[k]*coins<=t) ret+=solve(t-p[k]*coins, k-1);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T, K;
  cin >> T >> K;
  for(int i=0; i<K; i++) cin >> p[i] >> n[i];
  memset(cache, -1, sizeof(cache));
  cout << solve(T, K-1) << '\n';
}
