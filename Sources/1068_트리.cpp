#include <iostream>
#include <vector>
using namespace std;
int del;
vector<int> adj[50];
bool visited[50];
int dfs(int here){
  visited[here] = true;
  int ret=0;
  for(auto there : adj[here])
    if(!visited[there])
      ret += dfs(there);
  if(ret==0) ret=1;
  return ret;
}
int main()
{
  int n, root, leafs=0;
  cin >> n;
  for(int i=0; i<n; i++){
    int parent;
    cin >> parent;
    if(parent!=-1){
      adj[parent].push_back(i);
      adj[i].push_back(parent);
    }
    else root = i;
  }
  cin >> del;
  visited[del] = true;
  if(!visited[root]) leafs = dfs(root);
  cout << leafs << endl;
  return 0;
}
