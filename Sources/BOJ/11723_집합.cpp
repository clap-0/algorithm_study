#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int m, S=0;
  cin >> m;
  while(m--){
    string order;
    int x;
    cin >> order;
    if(order == "add"){ //S에 x추가
      cin >> x;
      S |= (1<<(x-1));
    }
    else if(order == "remove"){ //S에서 x제거
      cin >> x;
      S &= ~(1<<(x-1));
    }
    else if(order == "check"){ //S에 x유무 확인
      cin >> x;
      cout << ((S&(1<<(x-1)))>0 ? 1 : 0) << '\n';
    }
    else if(order == "toggle"){ //S에 x있으면 제거, 없으면 추가
      cin >> x;
      S ^= (1<<(x-1));
    }
    else if(order == "all") S = (1<<20)-1; //S를 {1,2,...,20}로 변경
    else if(order == "empty") S = 0; //S를 공집합으로 변경
  }
}
