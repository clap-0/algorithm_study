#include <iostream>
#include <vector>
using namespace std;
const int MAX=3000;
vector<int> adj[MAX];
int visited[MAX];
void dfs(int here){ //깊이우선탐색 알고리즘
  visited[here] = true;
  for(int there : adj[here])
    if(!visited[there]) dfs(there);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int v, e;
  int degree[MAX]={0}; //각 정점의 차수
  cin >> v >> e;
  for(int i=0; i<e; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    degree[a]++; degree[b]++;
  }
  bool isEuler = true; //오일러트레일이나 오일러서킷이 가능한가?
  int oddVertex=0; //홀수개의 차수를 가진 정점 수
  for(int i=0; i<v; i++)
    if(degree[i]%2==1) oddVertex++;
  if(!(oddVertex==0 || oddVertex==2)) isEuler=false; //홀수점이 하나도 없거나 두 개있는 경우 제외하면 오일러 안됨
  int num=0;
  for(int i=0; i<v; i++){
    if(!visited[i]){
      dfs(i);
      num++;
    }
    if(num>1){ //컴포넌트가 두 개 이상이면 오일러 안됨
      isEuler=false;
      break;
    }
  }
  cout << (isEuler?"YES":"NO") << '\n';
}
