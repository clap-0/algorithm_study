#include <iostream>
#include <cstring>
using namespace std;
const int INF=987654321;
const int d[3]={-1,0,1};
int N;
int cache[10001][150];
bool isSmall[10000];
//DP를 이용하여 현재 서있는 돌의 번호와 이전에 뛰었던 칸의 수가 주어졌을 때
//이 돌에서 N번 돌까지 필요한 최소의 점프 횟수를 구한다
int countMinJump(int here, int jump){
  //기저사례: N번 돌에 도착한 경우 0반환
  if(here==N) return 0;
  //메모이제이션
  int& ret=cache[here][jump];
  if(ret!=-1) return ret;
  ret=INF;
  for(int i=0; i<3; i++){
    int nextJump=jump+d[i], there=here+nextJump;
    //점프를 한칸이상 못하거나, N번 돌을 넘어서 점프하거나, 다음에 갈 돌이 작은 경우 패스
    if(nextJump<1||there>N||isSmall[there]) continue;
    ret=min(ret, 1+countMinJump(there, nextJump));
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int M;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int rock;
    cin >> rock;
    isSmall[rock]=true;
  }
  memset(cache, -1, sizeof(cache));
  int jumps=countMinJump(1, 0);
  cout << (jumps!=INF?jumps:-1) << '\n';
}
