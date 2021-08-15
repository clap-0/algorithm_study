#include <iostream>
#include <cstring>
using namespace std;
int n, m;
long long cache[11][2001];
//DP를 이용하여 구매하는 로또의 개수를 구한다
long long countLotto(int curr, int num){
  //기저사례: 로또의 모든 수를 고른 경우 1반환
  if(curr==1) return 1;
  //메모이제이션
  long long& ret=cache[curr][num];
  if(ret!=-1) return ret;
  ret=0;
  for(int prevNum=num/2; prevNum>=(1<<(curr-2)); prevNum--) ret+=countLotto(curr-1, prevNum);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  memset(cache, -1, sizeof(cache));
  while(T--){
    cin >> n >> m;
    long long ans=0;
    for(int i=m; i>=(1<<(n-1)); i--) ans+=countLotto(n,i);
    cout << ans << '\n';
  }
}
