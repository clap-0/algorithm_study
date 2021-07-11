#include <cstdio>
using namespace std;
int N, W[10][10], ans=987654321;
bool visited[10];
//브루트포스로 외판원순회문제 풀기
void TSP(int curr, int sum, int cnt){
  //현재까지 들은 비용의 합이 이전에 구한 순회비용보다 큰 경우 답이 될 수 없다
  if(sum>ans) return;
  //모든 도시를 거친 경우 순회비용의 최솟값을 구한다
  if(cnt==N){
    if(W[curr][0] && ans>sum+W[curr][0]) ans=sum+W[curr][0];
    return;
  }
  //현재 도시에서 길이 있는 아직 가지 않은 도시로 이동한다
  for(int next=0; next<N; next++)
    if(!visited[next] && W[curr][next]){
      visited[next]=true;
      TSP(next, sum+W[curr][next], cnt+1);
      visited[next]=false;
    }
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) scanf("%d", &W[i][j]);
  visited[0]=true;
  TSP(0, 0, 1);
  printf("%d\n", ans);
}
