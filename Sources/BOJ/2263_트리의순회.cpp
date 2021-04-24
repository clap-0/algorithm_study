//배열과 구간이 주어질 때 주어진 배열을 구간에 맞게 자르는 slice() 함수를 썼더니
//메모리초과가 발생하여 printPreorder() 함수 내에서 구간을 고려해 답을 구하도록 코드를 짰다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> inorder, postorder; //트리의 중위순회순서와 후위순회순서
int cnt;
void printPreorder(int inLower, int inUpper, int postLower, int postUpper){
  if(postLower>=postUpper) return; //기저사례 : 주어진 구간 내에 노드가 없으면 종료
  //주어진 구간 내 노드의 수
  const int n = postUpper - postLower;
  //후위순회에서 가장 마지막에 나오는 게 루트
  const int root = postorder[postUpper-1]; 
  //중위순회에서 루트 이전에 나온 노드들은 루트의 왼쪽 서브트리
  const int left = find(inorder.begin(), inorder.end(), root) - inorder.begin() - inLower;
  cout << root << ' ';
  //왼쪽, 오른쪽 서브트리 전위순회로 출력
  printPreorder(inLower, inLower+left, postLower, postLower+left);
  printPreorder(inLower+left+1, inLower+n, postLower+left, postLower+n-1);
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    inorder.push_back(num);
  }
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    postorder.push_back(num);
  }
  printPreorder(0, n, 0, n);
}
