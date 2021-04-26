#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> arr;
vector<long long> segTree; //세그먼트 트리
//node 노드가 arr[left...right] 배열을 표현할때
//node를 루트로 하는 서브트리를 초기화하고, 이 구간의 합 반환
long long init(int node, int left, int right){
  if(left == right) return segTree[node] = arr[left];
  int mid = (left + right)/2;
  return segTree[node] = init(node*2, left, mid)+init(node*2+1, mid+1, right);
}
//arr[index] = newVal로 바뀌었을 때 node를 루트로하는
//트리를 갱신하고 노드가 표현하는 구간의 합 반환
long long update(int index, long long newVal, int node, int nodeLeft, int nodeRight){
  if(index<nodeLeft || nodeRight<index) return segTree[node];
  if(nodeLeft==nodeRight) return segTree[node] = newVal;
  int mid = (nodeLeft+nodeRight)/2;
  segTree[node] = update(index, newVal, node*2, nodeLeft, mid) + update(index, newVal, node*2+1, mid+1, nodeRight);
  return segTree[node];
}
//node가 표현하는 범위 arr[nodeLeft...nodeRight]가 주어질때
//이 범위와 arr[L...R]의 교집합인 구간의 합 반환
long long query(int L, int R, int node, int nodeLeft, int nodeRight){
  if(R<nodeLeft || L>nodeRight) return 0;
  if(L<=nodeLeft && nodeRight<=R) return segTree[node];
  int mid = (nodeLeft+nodeRight)/2;
  return query(L, R, node*2, nodeLeft, mid) + query(L, R, node*2+1, mid+1, nodeRight);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    arr.push_back(num);
  }
  segTree.resize(n*4);
  init(1, 0, n-1);
  for(int i=0; i<m+k; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    if(a==1) update(b-1, c, 1, 0, n-1); 
    else if(a==2) cout << query(b-1, c-1, 1, 0, n-1) << '\n';
  }
}
