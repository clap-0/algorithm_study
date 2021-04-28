#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct SegTree{
  int n;
  vector<int> rangeSign; //구간내 값의 곱의 부호 (-1, 0, 1)
  SegTree(const vector<int>& arr){
    n = arr.size();
    int treeSize = (1<<((int)ceil(log2(n))+1));
    rangeSign.resize(treeSize);
    init(arr, 1, 0, n-1);
  }
  //node노드가 arr[left..right]를 표현할 때
  //node를 루트로 하는 서브트리 초기화 및 구간곱의 부호 반환
  int init(const vector<int>& arr, int node, int left, int right){
    if(left==right) return rangeSign[node] = arr[left];
    int mid = (left+right)/2;
    return rangeSign[node] = init(arr, node*2, left, mid) * init(arr, node*2+1, mid+1, right);
  }
  //arr[start..end]와 node가 표현하는 arr[nodeL..nodeR]의 교집합 구간의 구간곱 부호 반환
  int query(int i, int j){ return query(i-1, j-1, 1, 0, n-1); }
  int query(int start, int end, int node, int nodeL, int nodeR){
    if(start>nodeR || end<nodeL) return 1; //상관없는 구간은 무시
    if(start<=nodeL && nodeR<=end) return rangeSign[node];
    int mid = (nodeL+nodeR)/2;
    return query(start, end, node*2, nodeL, mid) * query(start, end, node*2+1, mid+1, nodeR);
  }
  //arr[i]=V로 바뀌었을 때 node를 루트로 하는
  //구간트리 갱신하고 node가 표현하는 구간 구간곱의 부호 반환
  int update(int i, int V){
    int sign = V>0 ? 1 : V<0 ? -1 : 0;
    return update(i-1, sign, 1, 0, n-1);
  }
  int update(int index, int sign, int node, int nodeL, int nodeR){
    if(index<nodeL || index>nodeR) return rangeSign[node];
    if(nodeL==nodeR) return rangeSign[node] = sign;
    int mid = (nodeL+nodeR)/2;
    return rangeSign[node] = update(index, sign, node*2, nodeL, mid) * update(index, sign, node*2+1, mid+1, nodeR);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k;
  while(cin >> n >> k){
    vector<int> arr(n);
    for(int i=0; i<n; i++){
      int x;
      cin >> x;
      arr[i] = x>0 ? 1 : x<0 ? -1 : 0; //값을 부호로 변환하여 저장
    }
    SegTree ST(arr);
    for(int i=0; i<k; i++){
      char order;
      int a, b;
      cin >> order >> a >> b;
      if(order=='C') ST.update(a, b);
      else {
        int res = ST.query(a, b);
        cout << (res>0 ? '+' : res<0 ? '-' : '0');
      }
    }
    cout << '\n';
  }
}
