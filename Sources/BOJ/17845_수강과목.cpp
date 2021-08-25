#include <iostream>
using namespace std;
int I[1000], T[1000];
int cache[10001][1000];
//DP를 이용하여 배낭문제 풀기
int knapsack(int n, int k){
  //기저사례: 모든 과목을 확인한 경우 0반환
  if(k==-1) return 0; 
  //메모이제이션
  int& ret=cache[n][k];
  if(ret!=0) return ret;
  //이 과목을 수강하지않는 경우의 최대중요도
  ret=knapsack(n, k-1);
  //이 과목을 수강하는 경우의 최대중요도
  if(n>=T[k]) ret=max(ret, I[k]+knapsack(n-T[k], k-1));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  cin >> N >> K;
  for(int i=0; i<K; i++) cin >> I[i] >> T[i];
  cout << knapsack(N, K-1) << '\n';
}
