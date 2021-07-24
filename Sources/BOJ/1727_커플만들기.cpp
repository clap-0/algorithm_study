#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
//boys[]와 girls[]을 가리키는 포인터
int *bp, *gp;
//남자들과 여자들의 성격 수치
int boys[1000], girls[1000];
int cache[1000][1000];
//재귀적동적계획법을 이용하여 성격 차이의 합의 최솟값을 구한다
int personalityGap(int b, int g){
  //기저사례 : 최대한 많은 커플을 만든 경우 0 반환
  if(b==n) return 0;
  //메모이제이션
  int& ret = cache[b][g];
  if(ret!=-1) return ret;
  ret=abs(bp[b]-gp[g])+personalityGap(b+1, g+1);
  if(g<m-n+b) ret=min(ret, personalityGap(b, g+1));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> boys[i];
  for(int i=0; i<m; i++) cin >> girls[i];
  sort(boys, boys+n); sort(girls, girls+m);
  bp=boys; gp=girls;
  if(n>m){
    swap(n, m);
    swap(bp, gp);
  }
  memset(cache, -1, sizeof(cache));
  cout << personalityGap(0, 0) << '\n';
}
