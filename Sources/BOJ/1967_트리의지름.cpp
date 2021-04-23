#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=10001;
vector<pair<int,int> > adj[MAX_N];
int diameter=0; //트리의 지름 (==트리의 가장 긴 경로)
//root를 루트로 하는 서브트리의 높이 반환
int height(int root){
  if(adj[root].empty()) return 0;
  vector<int> heights;
  for(auto &edge : adj[root]){
    int c = edge.first, w = edge.second;
    heights.push_back(height(c)+w);
  }
  sort(heights.begin(), heights.end());
  if(heights.size()>=2) diameter = max(diameter, heights[heights.size()-2]+heights[heights.size()-1]);
  return heights.back();
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int parent, child, weight;
    cin >> parent >> child >> weight;
    adj[parent].push_back({child, weight});
  }
  int h = height(1);
  cout << max(h, diameter) << endl;
}
