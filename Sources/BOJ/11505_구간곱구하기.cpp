#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1000000007;
struct SegTree {
  int n;
  vector<long long> rangeProduct;
  SegTree(const vector<long long>& arr){
    n = arr.size();
    int treeSize = (1<<((int)ceil(log2(n))+1));
    rangeProduct.resize(treeSize);
    init(arr, 1, 0, n-1);
  }
  long long init(const vector<long long>& arr, int node, int left, int right){
    if(left==right) return rangeProduct[node] = arr[left];
    int mid = (left+right)/2;
    return rangeProduct[node] = (init(arr, node*2, left, mid) * init(arr, node*2+1, mid+1, right)) % MOD;
  }
  long long query(int start, int end, int node, int nodeL, int nodeR){
    if(start>nodeR || end<nodeL) return 1;
    if(start<=nodeL && nodeR<=end) return rangeProduct[node];
    int mid = (nodeL+nodeR)/2;
    return (query(start, end, node*2, nodeL, mid) * query(start, end, node*2+1, mid+1, nodeR)) % MOD;
  }
  long long update(int index, int newVal, int node, int nodeL, int nodeR){
    if(index<nodeL || index>nodeR) return rangeProduct[node];
    if(nodeL==nodeR) return rangeProduct[node] = newVal;
    int mid = (nodeL+nodeR)/2;
    return rangeProduct[node] = (update(index, newVal, node*2, nodeL, mid) * update(index, newVal, node*2+1, mid+1, nodeR)) % MOD;
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m, k;
  vector<long long> arr;
  cin >> n >> m >> k;
  arr = vector<long long>(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  SegTree ST(arr);
  for(int i=0; i<m+k; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(a==1) ST.update(b-1, c, 1, 0, n-1);
    else cout << ST.query(b-1, c-1, 1, 0, n-1) << '\n';
  }
}
