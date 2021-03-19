#include <iostream>
using namespace std;
int n, m;
const int MAX_N=100;
bool adj[MAX_N][MAX_N]; //인접행렬
void floyd(){ //플로이드 알고리즘을 이용한 경로존재여부 찾기
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        adj[i][j] = (adj[i][j]||(adj[i][k]&&adj[k][j]));
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> adj[i][j];
  floyd();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cout << adj[i][j] << ' ';
    cout << '\n';
  }
}
