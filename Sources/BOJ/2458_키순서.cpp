#include <iostream>
using namespace std;

const int MAX=500;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  bool adj[MAX][MAX]={false};
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b; a--; b--;
    adj[a][b]=true;
  }
  //플로이드-와샬 알고리즘
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(adj[i][k]&&adj[k][j]) adj[i][j]=true;
  //i번학생이 다른 모든 학생들과 연결된 경로가 있는 경우
  //키 순서를 정확하게 알 수 있다
  int ans=0;
  for(int i=0; i<n; i++){
    int temp=0;
    for(int j=0; j<n; j++)
      if(adj[i][j]||adj[j][i]) temp++;
    if(temp==n-1) ans++;
  }
  cout << ans << '\n';
}
