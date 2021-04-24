#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> preorder; //트리의 전위순회순서
void printPostorder(int lower, int upper){
  if(lower==upper) return; //기저사례 : 구간 내 노드가 없으면 종료
  
  int root = preorder[lower]; //전위순회 시 루트를 제일 먼저 방문함
  //전위순회 결과에서 root 다음부터 root보다 작은 수들이 root의 왼쪽 서브트리이다
  //원래 upper_bound()는 정렬 후 사용해야 하지만, 어차피 root이후의 수들은 root보다 작은 구간과 큰 구간으로 나누어진다
  vector<int>::iterator next = preorder.begin()+lower+1;
  int L = upper_bound(next, preorder.end(), root) - next;
  
  //왼쪽, 오른쪽 서브트리에서 후위순회결과 출력
  printPostorder(lower+1, lower+L+1);
  printPostorder(lower+L+1, upper);
  cout << root << '\n';
}
int main()
{
  for(int key; cin >> key;) preorder.push_back(key);
  printPostorder(0, preorder.size());
}
