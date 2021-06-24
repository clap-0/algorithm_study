#include <iostream>
using namespace std;
int N;
int S[20][20];
bool picked[20];
//백트래킹을 이용한 풀이
int backtracking(int curr=-1, int cnt=0){
  if(cnt==N/2){
    int sum[2]={0};
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++){
        //i와 j가 모두 같은 팀에 속한 경우 능력치 합침
        if(picked[i]&&picked[j]) sum[0]+=S[i][j];
        else if(!picked[i]&&!picked[j]) sum[1]+=S[i][j];
      }
    return sum[0]>sum[1] ? sum[0]-sum[1] : sum[1]-sum[0];
  }
  int res=987654321;
  for(int next=curr+1; next<N; next++){
    picked[next]=true;
    res = min(res,backtracking(next, cnt+1));
    picked[next]=false;
  }
  return res;
}
int main()
{
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> S[i][j];
  cout << backtracking() << '\n';
}
