#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=50, INF=987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  int adj[MAX][MAX];
  fill(&adj[0][0], &adj[MAX-1][MAX], INF);
  cin >> n;
  while(1){
    int a, b;
    cin >> a >> b;
    if(a==-1 && b==-1) break;
    a--; b--;
    adj[a][b]=adj[b][a]=1;
  }
  //플로이드-와샬 알고리즘
  for(int i=0; i<n; i++) adj[i][i]=0;
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
  //회장후보 찾기
  vector<int> candidates;
  int minScore=INF;
  for(int i=0; i<n; i++){
    int score=0;
    for(int j=0; j<n; j++) score=max(score, adj[i][j]);
    if(minScore>score){
      minScore=score;
      candidates.clear();
    }
    if(minScore==score) candidates.push_back(i+1);
  }
  cout << minScore << ' ' << candidates.size() << '\n';
  for(int c : candidates) cout << c << ' ';
}
