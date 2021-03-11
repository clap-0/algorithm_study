#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
const int MAX_N=101, INF=987654321;
int adj[MAX_N][MAX_N];
void floyd()
{
  for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      adj[i][j] = ((i==j) ? 0 : INF);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a][b] = adj[b][a] = 1;
  }
  floyd();
  //각 유저의 케빈 베이컨의 수 저장
  vector<int> KB(n+1, 0); 
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      KB[i] += adj[i][j];
  //케빈 베이컨의 수가 가장 작은 사람(가장 작은 인덱스번호) 출력
  cout << min_element(KB.begin()+1, KB.end()) - KB.begin() << endl;
  return 0;
}
