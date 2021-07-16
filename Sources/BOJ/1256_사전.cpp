#include <iostream>
#include <cstring>
using namespace std;
const int INF=1000000001;
int cache[201][201];
//DP를 이용하여 이항계수를 구한다
int bino(int n, int r){
  if(n==r || r==0) return 1;
  int& ret = cache[n][r];
  if(ret!=-1) return ret;
  return ret = min(INF, bino(n-1, r) + bino(n-1, r-1));
}
//n과 m이 주어졌을 때 skip번째 문자열을 구한다
string kString(int n, int m, int skip){
  //문자열을 모두 완성시킨 경우
  if(n+m==0) return "";
  //남은 문자열이 m개의 'z'로만 이루어진 경우
  if(n==0) return string(m,'z');
  //aStart : n개의 'a'와 m개의 'z'로 만들 수 있는 문자열 중 'a'로 시작하는 문자열의 개수
  int aStart=bino(n+m-1, n-1);
  //skip번째 문자열이 aStart보다 작거나 같으면 a로 시작하고, 크면 'z'로 시작한다
  if(skip<=aStart) return 'a'+kString(n-1, m, skip);
  return 'z'+kString(n, m-1, skip-aStart);
}
int main()
{
  ios_base::sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;
  memset(cache, -1, sizeof(cache));
  //규완이의 사전에 수록된 문자열 개수가 K보다 작은 경우 -1 출력
  if(K>bino(N+M,N)) cout << -1 << '\n';
  else cout << kString(N, M, K) << '\n';
}
