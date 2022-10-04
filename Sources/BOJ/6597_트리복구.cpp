#include <iostream>
using namespace std;

int rootIdx;
void postorder(string preorder, string inorder)
{
  if (inorder == "" || rootIdx == preorder.length())
    return;
  char root = preorder[rootIdx++];
  int L = inorder.find(root);
  postorder(preorder, inorder.substr(0, L));
  postorder(preorder, inorder.substr(L + 1));
  cout << root;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  string preorder, inorder;
  while (cin >> preorder >> inorder)
  {
    rootIdx = 0;
    postorder(preorder, inorder);
    cout << '\n';
  }
}
