#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
int cache[301];//시작점 고려해서 n+1
vector<int> score(300);
int climbStairs(int stair)
{
  int& ret = cache[stair+1];
  if(ret!=-1) return ret;
  //n번째 계단 밟았을때 최댓값: n-2번째 계단 밟았을때 최댓값 +n번째 계단점수 or n-3번째 계단에서의 최댓값 +n-1번째 계단점수 +n번째 계단점수
  return ret=max(climbStairs(stair-2), climbStairs(stair-3)+score[stair-1])+score[stair];
}
int main()
{
  cin >> n;
  for(int i=0; i<n; i++) cin >> score[i];
  memset(cache, -1, sizeof(cache));
  cache[0]=0, cache[1]=score[0], cache[2]=score[0]+score[1];
  cout << climbStairs(n-1) << endl;;
  return 0;
}
