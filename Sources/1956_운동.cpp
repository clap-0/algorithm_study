#include <iostream>
using namespace std;
int v, e;
const int MAX_V=401, INF=987654321;
int adj[MAX_V][MAX_V];
void floyd(){
  for(int k=1; k<=v; k++)
    for(int i=1; i<=v; i++)
      for(int j=1; j<=v; j++)
        adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> v >> e;
  for(int i=1; i<=v; i++)
    for(int j=1; j<=v; j++)
      adj[i][j] = INF;
  for(int i=0; i<e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
  }
  floyd();
  int ret=INF;
  for(int i=1; i<=v; i++)
    ret = min(ret, adj[i][i]);
  if(ret==INF) ret=-1;
  cout << ret << '\n';
}
