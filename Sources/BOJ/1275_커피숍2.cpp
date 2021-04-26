#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> arr;
vector<long long> segTree; //세그먼트트리
//arr[start..end] 배열을 표현하는 노드 node가 주어질 때
//node를 루트로 하는 서브트리를 초기화하고, node에서의 수의 합 반환
long long init(int node, int start, int end){
  if(start==end) return segTree[node] = arr[start]; //잎노드인 경우
  int mid = (start+end)/2;
  return segTree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}
//arr[nodeLeft..nodeRight] 배열을 표현하는 노드 node가 주어질 때
//arr[start..end]과의 교집합에서의 수의 합 반환
long long query(int start, int end, int node, int nodeLeft, int nodeRight){
  if(start>nodeRight || end<nodeLeft) return 0;
  if(start<=nodeLeft && nodeRight<=end) return segTree[node];
  int mid = (nodeLeft+nodeRight)/2;
  return query(start, end, node*2, nodeLeft, mid) + query(start, end, node*2+1, mid+1, nodeRight);
}
//arr[index]=newVal로 바뀌었을 때 node를 루트로 하는
//세그먼트트리 갱신하고 node가 표현하는 구간에서의 수의 합 반환
long long update(int index, int newVal, int node, int nodeLeft, int nodeRight){
  //노드가 표현하는 구간 안에 index가 없는 경우 무시
  if(index<nodeLeft || nodeRight<index) return segTree[node];
  if(nodeLeft==nodeRight) return segTree[node] = newVal;
  int mid = (nodeLeft+nodeRight)/2;
  return segTree[node] = update(index, newVal, node*2, nodeLeft, mid) + update(index, newVal, node*2+1, mid+1, nodeRight);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n >> q;
  arr = vector<int>(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  //세그먼트트리 만들고 초기화
  segTree.resize(1<<((int)ceil(log2(n))+1));
  init(1, 0, n-1);
  
  for(int i=0; i<q; i++){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if(x>y) swap(x, y);
    cout << query(x-1, y-1, 1, 0, n-1) << '\n';
    update(a-1, b, 1, 0, n-1);
  }
}
