#include <iostream>
#include <set>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int k;
    multiset<int, greater<int> > q; //이중우선순위큐
    cin >> k;
    while(k--){
      char operation;
      int n;
      cin >> operation >> n;
      switch(operation){
        case 'I' :
          q.insert(n);
          break;
        case 'D' :
          if(q.empty()) break; //큐가 비어있을 경우 연산무시
          if(n==1) q.erase(q.begin()); //1이면 최댓값 삭제
          else q.erase(prev(q.end())); //-1이면 최솟값 삭제
          break;
      }
    }
    if(q.empty()) cout << "EMPTY" << '\n';
    else cout << *(q.begin()) << ' ' << *(prev(q.end())) << endl;
  }
  return 0;
}
