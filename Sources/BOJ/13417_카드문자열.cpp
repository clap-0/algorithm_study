#include <iostream>
#include <deque>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--){
    int N;
    char card;
    deque<char> dq;
    cin >> N >> card;
    dq.push_back(card);
    for(int i=1; i<N; i++){
      cin >> card;
      if(card <= dq.front()) dq.push_front(card);
      else dq.push_back(card);
    }
    for(char card : dq) cout << card;
    cout << '\n';
  }
}
