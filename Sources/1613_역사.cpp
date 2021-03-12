#include <iostream>
using namespace std;
int n, k, s;
const int MAX_N=401;
int adj[MAX_N][MAX_N];
void floyd(){
  for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        adj[i][j] = adj[i][j]||(adj[i][k]&&adj[k][j]);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for(int i=0; i<k; i++){
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
  }
  floyd();
  cin >> s;
  for(int i=0; i<s; i++){
    int u, v;
    cin >> u >> v;
    if(adj[u][v]) cout << -1 << '\n';
    else if(adj[v][u]) cout << 1 << '\n';
    else cout << 0 << '\n';
  }
  return 0;
}
