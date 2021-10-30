#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;
// i번째 앵무새가 말한 문자열를 단어별로 큐 S[i]에 저장한다
queue<string> S[100];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  // cin과 getline의 입력방식 차이때문에 입력버퍼를 비워준다
  cin.ignore();
  // 개행문자('\n')를 구분자로 하여 문자열 sentence를 입력받은 뒤
  // sentence를 공백문자(' ')로 구분하여 여러 문자열로 분리해
  // 각각의 문자열을 큐 S[i]에 추가한다
  for(int i=0; i<N; i++){
    string sentence, word;
    getline(cin, sentence);
    istringstream ss(sentence);
    while (ss>>word){
      S[i].push(word);
    }
  }
  string L, word;
  getline(cin, L);
  // 문자열 L을 공백문자를 기준으로 여러 문자열로 분리하고
  // 각각의 문자열들을 앞의 문자열부터 앵무새가 말할 문자열과 비교한다
  istringstream ss(L);
  while(ss>>word){
    bool isSame=false;
    // 앵무새들이 앞으로 말할 문자열(큐의 가장 앞에 있는 문자열)중에
    // word와 일치하는 문자열이 있다면 pop시킨다
    for(int i=0; i<N; i++)
      if(word==S[i].front()){
        S[i].pop();
        isSame=true;
        break;
      }
    // 앵무새가 말할 문자열중에 일치하는 게 없다면 "Impossible"
    if(!isSame){
      cout << "Impossible\n";
      return 0;
    }
  }
  // L의 문자열들을 모두 확인했는데 아직 앵무새가 말해야되는 문자열이 남아있는 경우 "Impossible"
  for(int i=0; i<N; i++)
    if(!S[i].empty()){
      cout << "Impossible\n";
      return 0;
    }
  cout << "Possible\n";
}
