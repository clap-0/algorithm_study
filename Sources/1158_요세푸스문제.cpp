#include <iostream>
#include <queue>
using namespace std;
int main()
{
  int n, k;
  cin >> n >> k;
  queue<int> remaining; //살아있는 사람들
  for(int i=1; i<=n; i++)
    remaining.push(i);
  cout << "<";
  while(!remaining.empty()){
    for(int i=0; i<k-1; i++){ //k-1번 앞사람을 맨 뒤로 이동
      remaining.push(remaining.front());
      remaining.pop();
    }
    cout << remaining.front();
    remaining.pop(); //맨 앞사람 죽음
    if(!remaining.empty()) cout << ", ";
  }
  cout << ">" << endl;
  return 0;
}
