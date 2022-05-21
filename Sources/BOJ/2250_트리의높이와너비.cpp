#include <iostream>
using namespace std;

pair<int,int> child[10001]; // child[i] = i번 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호
bool isSubtree[10001];  // isSubtree[i] = i번 노드가 서브트리의 루트이면 true, 트리 전체의 루트면 false
int minColumn[10001], maxColumn[10001]; // 레벨이 k일 때 해당 레벨에서의 노드가 배치된 가장 왼쪽 열과 가장 오른쪽 열의 번호
int depth;  // 트리의 깊이
int columnCount; // 함수 inorder()로 각 노드에 열번호를 매길 때 들어갈 열번호 저장

// 레벨이 level인 node번 노드를 루트로 하는 서브트리에서 열번호를 매기며
// level 레벨의 가장 왼쪽 열번호와 가장 오른쪽 열번호를 구한다
void inorder(int node, int level) {
  depth = max(depth, level);
  // 왼쪽 서브트리에 대하여 열번호를 매긴다
  if(child[node].first != -1) inorder(child[node].first, level + 1);
  
  // 현재 노드의 레벨에서 가장 왼쪽의 열번호와 가장 오른쪽의 열번호를 구한다
  // 열번호는 방문하는 노드 순서대로 증가하므로 현재 노드가 가장 오른쪽 노드가 된다
  maxColumn[level] = ++columnCount;
  if(!minColumn[level]) minColumn[level] = columnCount; 
  
  // 오른쪽 서브트리에 대하여 열번호를 매긴다
  if(child[node].second != -1) inorder(child[node].second, level + 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int node, left, right;
    cin >> node >> left >> right;
    child[node] = {left, right};
    isSubtree[left] = isSubtree[right] = true;
  }

  // 루트 번호를 구한다
  int root;
  for(int i = 1; i <= N; i++)
    if(!isSubtree[i]) {
      root = i;
      break;
    }
  
  inorder(root, 1);

  // 너비가 가장 넓은 레벨과 해당 레벨의 너비를 구한다
  int maxWidth = 0, maxWidthLevel = 0;
  for(int i = 1; i <= depth; i++)
    if(maxWidth < maxColumn[i] - minColumn[i] + 1) {
      maxWidth = maxColumn[i] - minColumn[i] + 1;
      maxWidthLevel = i;
    }

  cout << maxWidthLevel << ' ' << maxWidth << '\n';
}
