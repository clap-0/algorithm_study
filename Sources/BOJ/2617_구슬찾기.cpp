#include <iostream>
using namespace std;
const int MAX=99;
int main()
{
  int n, m;
  bool adj[MAX][MAX]={0};
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
  //자신보다 가볍거나 무거운 구슬 개수가
  //전체의 중간 순서((n+1)/2)보다 크면 중간이 될 가능성이 없음
  int mid=(n+1)/2, ans=0;
  for(int i=0; i<n; i++){
    //i보다 무거운 구슬 수와 가벼운 구슬 수
    int heavier=0, lighter=0;
    for(int j=0; j<n; j++){
      if(adj[i][j]) lighter++;
      else if(adj[j][i]) heavier++;
    }
    if(heavier>=mid || lighter>=mid) ans++;
  }
  cout << ans << '\n';
}
