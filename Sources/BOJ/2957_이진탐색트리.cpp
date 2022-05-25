#include <iostream>
#include <map>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  long long C = 0;
  map<int,int> tree;
  map<int,int>::iterator lowNode, upNode;
  tree.insert({0, -1});
  tree.insert({300001, -1});
  cin >> N;
  for(int i = 0; i < N; i++) {
    int X;
    cin >> X;
    // upNode: 트리에서 X보다 큰 가장 작은 수
    upNode = tree.upper_bound(X);
    // lowNode: 트리에서 X보다 작은 가장 큰 수
    lowNode = upNode; --lowNode;
    
    // X는 lowNode와 upNode 사이의 수이므로
    // 트리상에서 upNode와 lowNode 중 더 깊은 곳에 있는 노드의 자식노드로 X가 들어간다
    int depth = max(lowNode->second, upNode->second) + 1;
    tree.insert({X, depth});
    cout << (C += depth) << '\n';
  }
}
