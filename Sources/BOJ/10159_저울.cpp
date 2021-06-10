#include <iostream>
using namespace std;
const int MAX=100;
int main()
{
  int n, m;
  bool adj[MAX][MAX]={false};
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;;
    adj[a-1][b-1]=true;
  }
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(adj[i][k]&&adj[k][j]) adj[i][j]=true;
  for(int i=0; i<n; i++){
    int knowable=0;
    for(int j=0; j<n; j++)
      if(adj[i][j]||adj[j][i]) knowable++;
    cout << n-1-knowable << '\n';
  }
}
