#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 1e9;
struct SegTree{
  int n;
  vector<pair<int,int> > rangeMin;
  SegTree(const vector<int>& arr){
    n = arr.size();
    int treeSize = (1<<((int)ceil(log2(n))+1));
    rangeMin.resize(treeSize);
    init(arr, 1, 0, n-1);
  }
  pair<int,int> init(const vector<int>& arr, int node, int left, int right){
    if(left==right) return rangeMin[node] = {arr[left],left+1};
    int mid = (left+right)/2;
    pair<int,int> leftSub = init(arr, node*2, left, mid);
    pair<int,int> rightSub = init(arr, node*2+1, mid+1, right);
    if(leftSub.first==rightSub.first)
      return rangeMin[node] = (leftSub.second<rightSub.second ? leftSub : rightSub);
    return rangeMin[node] = (leftSub.first<rightSub.first ? leftSub : rightSub);
  }
  pair<int,int> update(int index, int newVal, int node, int nodeLeft, int nodeRight){
    if(index<nodeLeft || index>nodeRight) return rangeMin[node];
    if(nodeLeft==nodeRight) return rangeMin[node] = {newVal, index+1};
    int mid = (nodeLeft+nodeRight)/2;
    pair<int,int> leftSub = update(index, newVal, node*2, nodeLeft, mid);
    pair<int,int> rightSub = update(index, newVal, node*2+1, mid+1, nodeRight);
    if(leftSub.first==rightSub.first)
      return rangeMin[node] = (leftSub.second<rightSub.second ? leftSub : rightSub);
    return rangeMin[node] = (leftSub.first<rightSub.first ? leftSub : rightSub);
  }
  pair<int,int> query(int start, int end, int node, int nodeLeft, int nodeRight){
    if(start>nodeRight || end<nodeLeft) return {INF,INF};
    if(start<=nodeLeft && nodeRight<=end) return rangeMin[node];
    int mid = (nodeLeft+nodeRight)/2;
    pair<int,int> leftSub = query(start, end, node*2, nodeLeft, mid);
    pair<int,int> rightSub = query(start, end, node*2+1, mid+1, nodeRight);
    if(leftSub.first==rightSub.first)
      return (leftSub.second<rightSub.second ? leftSub : rightSub);
    return (leftSub.first<rightSub.first ? leftSub : rightSub);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  vector<int> arr;
  cin >> n;
  arr = vector<int>(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  SegTree ST(arr);
  cin >> m;
  for(int i=0; i<m; i++){
    int order, a, b;
    cin >> order >> a >> b;
    if(order==1) ST.update(a-1, b, 1, 0, n-1);
    else cout << ST.query(a-1, b-1, 1, 0, n-1).second << '\n';
  }
}
