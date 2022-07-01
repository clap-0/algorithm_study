#include <iostream>
#include <cstring>
using namespace std;

// 알파벳 소문자의 개수
const int ALPHABETS = 26;

// 문자열 입력에 사용되는 문자 배열
char input[501];

// 트라이의 한 노드를 나타내는 객체
struct Trie {
  Trie* children[ALPHABETS];
  // 이 노드가 종료노드인가?
  bool isTerminal;
  Trie() : isTerminal(false) {
    memset(children, 0, sizeof(children));
  }
  ~Trie() {
    for(int i = 0; i < ALPHABETS; i++)
      if(children[i])
        delete children[i];
  }

  // 이 노드를 루트로 하는 트라이에 문자열 key를 추가한다.
  void insert(const char* key) {
    // 문자열이 끝나면 terminal만 참으로 바꾸고 종료
    if(*key == 0)
      isTerminal = true;
    else {
      int next = *key - 'a';
      // 해당 자식노드가 없다면 생성한다.
      if(!children[next])
        children[next] = new Trie();
      // 해당 자식노드로 재귀호출
      children[next]->insert(key + 1);
    }
  }

  // 이 노드를 루트로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다.
  // 없으면 NULL을 반환
  Trie* find(const char* key) {
    if(*key == 0) return this;
    int next = *key - 'a';
    if(!children[next]) return NULL;
    return children[next]->find(key + 1);
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  Trie* trie = new Trie();
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> input;
    trie->insert(input);
  }

  int ans = 0;
  for(int i = 0; i < M; i++) {
    cin >> input;
    if(trie->find(input))
      ++ans;
  }

  cout << ans << '\n';
}
