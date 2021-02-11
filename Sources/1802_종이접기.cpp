#include <iostream>
#include <string>
using namespace std;
bool canFold(string folded)
{
  if(folded.length()==1) return 1; //기저사례:길이가 1일때
  int center=folded.length()/2;
  if(folded[center-1]==folded[center+1]) return 0; //중심기준으로 양옆의 수가 같으면 안됨
  return canFold(folded.substr(0, center))*canFold(folded.substr(center+1));
}
int main()
{
  int t;
  bool check;
  string folded;
  cin >> t;
  while(t--){
    cin >> folded;
    if(canFold(folded)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
