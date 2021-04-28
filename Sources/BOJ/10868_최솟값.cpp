#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 2e9;
struct SegTree {
  int n;
  vector<int> rangeMin;
  SegTree(const vector<int>& arr){
    n = arr.size();
    int treeSize = (1<<((int)ceil(log2(n))+1));
    rangeMin.resize(treeSize);
    init(arr, 1, 0, n-1);
  }
  int init(const vector<int>& arr, int node, int left, int right){
    if(left==right) return rangeMin[node] = arr[left];
    int mid = (left+right)/2;
    return rangeMin[node] = min(init(arr, node*2, left, mid), init(arr, node*2+1, mid+1, right));
  }
  int query(int start, int end, int node, int nodeLeft, int nodeRight){
    if(start>nodeRight || end<nodeLeft) return INF;
    if(start<=nodeLeft && nodeRight<=end) return rangeMin[node];
    int mid = (nodeLeft+nodeRight)/2;
    return min(query(start, end, node*2, nodeLeft, mid), query(start, end, node*2+1, mid+1, nodeRight));
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  vector<int> arr;
  cin >> n >> m;
  arr = vector<int>(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  SegTree ST(arr);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    cout << ST.query(a-1, b-1, 1, 0, n-1) << '\n';
  }
}
