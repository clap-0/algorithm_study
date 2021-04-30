#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct SegTree{
  int n;
  vector<long long> rangeSum;
  SegTree(int size){
    n = size;
    int treeSize = (1<<((int)ceil(log2(n))+1));
    rangeSum.resize(treeSize, 0);
  }
  long long add(int index, int value, int node, int nodeLeft, int nodeRight){
    if(index<nodeLeft || index>nodeRight) return rangeSum[node];
    if(nodeLeft==nodeRight) return rangeSum[node] += value;
    int mid = (nodeLeft+nodeRight)/2;
    return rangeSum[node] = add(index, value, node*2, nodeLeft, mid) + add(index, value, node*2+1, mid+1, nodeRight);
  }
  long long query(int start, int end, int node, int nodeLeft, int nodeRight){
    if(start>nodeRight || end<nodeLeft) return 0;
    if(start<=nodeLeft && nodeRight<=end) return rangeSum[node];
    int mid = (nodeLeft+nodeRight)/2;
    return query(start, end, node*2, nodeLeft, mid) + query(start, end, node*2+1, mid+1, nodeRight);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n >> q;
  SegTree ST(n);
  for(int i=0; i<q; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(a==1) ST.add(b-1, c, 1, 0, n-1);
    else cout << ST.query(b-1, c-1, 1, 0, n-1) << '\n';
  }
}
