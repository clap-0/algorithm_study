#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    string P, numbers;
    int n;
    cin >> P >> n >> numbers;

    // 함수 R이 나올 때마다 reverse()를 사용하면 시간초과가 되므로
    // deque의 pop_front()와 pop_back()을 사용한다
    
    deque<int> arr;
    string s = "";
    for(auto ch : numbers) {
      if(isdigit(ch)) s += ch;
      else if(!s.empty()) {
        arr.push_back(stoi(s));
        s = "";
      }
    }

    bool isReversed = false, isError = false;
    for(char p : P) {
      if(p == 'R') isReversed = !isReversed;
      else {
        if(arr.empty()) {
          cout << "error\n";
          isError = true;
          break;
        }
        isReversed ? arr.pop_back() : arr.pop_front();
      }
    }

    if(!isError) {
      cout << "[";
      if(isReversed) 
        while(!arr.empty()) {
          cout << arr.back();
          arr.pop_back();
          if(!arr.empty()) cout << ",";
        }
      else 
        while(!arr.empty()) {
          cout << arr.front();
          arr.pop_front();
          if(!arr.empty()) cout << ",";
        }
      cout << "]\n";
    }
  }
}
