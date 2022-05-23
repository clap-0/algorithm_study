#include <iostream>
#include <algorithm>
using namespace std;

int preorder[1000]; // 트리의 전위순회 결과
int inorder[1000];  // 트리의 중위순회 결과

// 중위순회결과에서 범위 [inLeft, inRight)의 루트 번호가 preorder[preIdx]일 때
// 후위순회결과를 출력한다
void postorder(int inLeft, int inRight, int preIdx) {
  if(inLeft >= inRight) return;

  // [inLeft, inRight)에서 루트가 있는 인덱스를 찾는다
  int index = find(inorder + inLeft, inorder + inRight, preorder[preIdx]) - inorder;

  // 왼쪽 서브트리에서 후위순회 실행
  postorder(inLeft, index, preIdx + 1);

  // 오른쪽 서브트리 후위순회 실행
  // 오른쪽 서브트리의 루트는 전위순회 결과에서
  // 이전에 출력된 노드의 개수(preIdx) + 현재 노드(루트, 1) + 왼쪽 서브트리의 크기(index - inLeft)에 있다
  postorder(index + 1, inRight, preIdx + 1 + index - inLeft);

  // 현재 서브트리의 루트번호 출력
  cout << preorder[preIdx] << ' ';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> preorder[i];
    for(int i = 0; i < n; i++) cin >> inorder[i];
    postorder(0, n, 0);
    cout << '\n';
  }
}
