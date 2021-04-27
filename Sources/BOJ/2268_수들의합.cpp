#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct SegTree{ //구간합 해결을 위한 세그먼트트리
  int size; //배열의 길이
  vector<long long> rangeSum; //각 구간의 구간합
  SegTree(int n){
    size = n;
    rangeSum.resize(1<<((int)ceil(log2(n))+1), 0);
  }
  //A[i]부터 A[j]까지의 합을 구하는 함수
  long long Sum(int i, int j){ return Sum(i-1, j-1, 1, 0, size-1); }
  long long Sum(int start, int end, int node, int nodeLeft, int nodeRight){
    if(start>nodeRight || end<nodeLeft) return 0; //합을 구하려는 구간과 안 겹치면 무시
    if(start<=nodeLeft && nodeRight<=end) return rangeSum[node]; //합을 구하려는 구간에 완전히 포함되는 구간이면 구간합 반환
    int mid = (nodeLeft+nodeRight)/2;
    return Sum(start, end, node*2, nodeLeft, mid) + Sum(start, end, node*2+1, mid+1, nodeRight);
  }
  //A[i]값을 k로 바꾸는 함수
  long long Modify(int i, int k){ return Modify(i-1, k, 1, 0, size-1); }
  long long Modify(int index, int newVal, int node, int nodeLeft, int nodeRight){
    if(index<nodeLeft || index>nodeRight) return rangeSum[node]; //노드가 표현하는 구간과 index가 상관없으면 무시
    if(nodeLeft==nodeRight) return rangeSum[node] = newVal;
    int mid = (nodeLeft+nodeRight)/2;
    return rangeSum[node] = Modify(index, newVal, node*2, nodeLeft, mid) + Modify(index, newVal, node*2+1, mid+1, nodeRight);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  SegTree ST(n);
  for(int i=0; i<m; i++){
    int order, a, b;
    cin >> order >> a >> b;
    if(order) ST.Modify(a, b);
    else {
      if(a>b) swap(a, b);
      cout << ST.Sum(a, b) << '\n';
    }
  }
}
