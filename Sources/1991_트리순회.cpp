#include <iostream>
using namespace std;
struct Node {
  char left, right;
};
Node Tree[26];
void preorder(char root) //root를 루트로 하는 전위순회 출력
{
  if(root=='.') return;
  cout << root;
  preorder(Tree[root].left);
  preorder(Tree[root].right);
}
void inorder(char root) //root를 루트로 하는 중위순회 출력
{
  if(root=='.') return;
  inorder(Tree[root].left);
  cout << root;
  inorder(Tree[root].right);
}
void postorder(char root) //root를 루트로 하는 후위순회 출력
{
  if(root=='.') return;
  postorder(Tree[root].left);
  postorder(Tree[root].right);
  cout << root;
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    char root, lc, rc;
    cin >> root >> lc >> rc;
    Tree[root].left = lc;
    Tree[root].right = rc;
  }
  preorder('A'); cout << '\n';
  inorder('A'); cout << '\n';
  postorder('A'); cout << '\n';
  return 0;
}
