#include <iostream>
#include <algorithm>
using namespace std;
const int NUMBER=10; //문자열에 출현가능한 문자의 개수
int toNumber(char ch) {return ch-'0';}
//트라이의 노드를 나타내는 객체
struct TrieNode{
  bool terminal, hasChild; //이 노드가 종료노드인지, 이 노드가 자손이 있는지를 저장
  TrieNode* children[NUMBER];
  TrieNode(): terminal(false), hasChild(false){
    fill(children, children+NUMBER, nullptr);
  }
  ~TrieNode(){
    for(TrieNode* child : children)
      if(child) delete child;
  }
  //이 노드를 루트로 하는 트라이에 문자열 key를 추가
  //일관성이 있으면 true, 없으면 false 리턴
  bool insert(const char* key){
    if(*key==0){ //더 입력할 문자가 없으면 종료노드
      terminal=true;
      //종료노드가 자손을 가지면 입력된 문자열이 다른 문자열의 접두사이므로 일관성 없음
      return !hasChild;
    }
    int next = toNumber(*key);
    //해당 자식노드가 없으면 생성
    if(children[next]==NULL){
      children[next] = new TrieNode;
      hasChild = true;
    }
    //이 노드가 종료노드면 입력된 문자열의 접두사인 문자열이므로 일관성 없음
    return !terminal && children[next]->insert(key+1);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    TrieNode* root = new TrieNode;
    bool res=true; //일관성 여부
    cin >> n;
    for(int i=0; i<n; i++){
      char phoneNum[11];
      cin >> phoneNum;
      //일관성 없음으로 판명나면 굳이 트라이에 삽입 안 함
      res = res && root->insert(phoneNum);
    }
    cout << (res ? "YES" : "NO") << '\n';
    delete root;
  }
}
