#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> blocks[50];
int cache[50][1001];
//DP를 이용하여 [0,n]번 학생들의 블록들로 높이가 k인 블록을 만드는 경우의 수 구하기
//각 학생의 블록들 중 하나씩만 사용하므로 배낭문제를 응용하였다
int knapsack(int n, int k){
  //기저사례: 블록을 다 쌓은 경우 1반환
  if(k==0) return 1;
  //기저사례: 블록을 완성할 수 없는 경우 0반환
  if(n<0) return 0;
  //메모이제이션
  int& ret=cache[n][k];
  if(ret!=-1) return ret;
  ret=0;
  //n번학생의 블록들중 하나를 사용한다
  for(int h : blocks[n])
    if(k-h>=0) ret=(ret+knapsack(n-1, k-h))%10007;
  return ret;
}
int main()
{
  int N, M, H;
  scanf("%d %d %d", &N, &M, &H);
  for(int i=0; i<N; i++){
    //각 학생들이 블록을 사용하지 않는 경우를 구현하기 위해 높이 0을 포함시킨다
    blocks[i].push_back(0);
    int height;
    while(1){
      scanf("%d", &height);
      blocks[i].push_back(height);
      if(getchar()=='\n') break;
    }
  }
  memset(cache, -1, sizeof(cache));
  printf("%d\n", knapsack(N-1, H));
}
