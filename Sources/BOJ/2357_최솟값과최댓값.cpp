#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long INF = 1e9;
struct SegTree{ //구간의 최솟값을 구하는 세그먼트트리
  int n; //배열 arr의 크기
  vector<long long> rangeMin;
  SegTree(const vector<long long>& arr){
    n = arr.size();
    int treeSize = (1<<((int)ceil(log2(n))+1));
    rangeMin.resize(treeSize);
    init(arr, 1, 0, n-1);
  }
  //node 노드가 arr[nodeLeft..nodeRight] 배열을 표현할 때
  //node를 루트로 하는 서브트리 초기화, 이 구간의 최소치 반환
  long long init(const vector<long long>& arr, int node, int nodeLeft, int nodeRight){
    if(nodeLeft==nodeRight) return rangeMin[node] = arr[nodeLeft];
    int mid = (nodeLeft+nodeRight)/2;
    return rangeMin[node] = min(init(arr, node*2, nodeLeft, mid), init(arr, node*2+1, mid+1, nodeRight));
  }
  //arr[start..end]과 arr[nodeLeft..nodeRight]의 교집합 구간의 최소치 반환
  long long query(int start, int end) { return query(start-1, end-1, 1, 0, n-1); }
  long long query(int start, int end, int node, int nodeLeft, int nodeRight){
    if(start>nodeRight || end<nodeLeft) return INF; //node가 표현하는 구간이 구하려는 구간과 전혀 상관없으면 무시
    if(start<=nodeLeft && nodeRight<=end) return rangeMin[node]; //구하려는 구간에 node가 표현하는 구간이 완전히 포함되면 최소치반환
    int mid = (nodeLeft+nodeRight)/2;
    return min(query(start, end, node*2, nodeLeft, mid), query(start, end, node*2+1, mid+1, nodeRight));
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  vector<long long> arr;
  cin >> n >> m;
  
  arr = vector<long long>(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  SegTree minST(arr); //구간의 최소치를 찾는 세그먼트트리
  
  //arr[]부호 바꿔서 구간의 최소치 찾는 세그먼트트리 만들면, 최대치 찾는 세그먼트트리와 같음
  for(int i=0; i<n; i++) arr[i] = -arr[i]; 
  SegTree maxST(arr);
  
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    cout << minST.query(a, b) << ' ' << -maxST.query(a, b) << '\n';
  }
}
