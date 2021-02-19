#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct compare{ //절댓값의 오름차순으로, 절댓값이 같다면 원래 수의 오름차순으로 정렬하는 비교연산자
  bool operator()(int a, int b){
    if(abs(a)==abs(b)) return a > b;
    return abs(a) > abs(b);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, x;
  priority_queue< int, vector<int>, compare > arr;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> x;
    if(x!=0){
      arr.push(x);
    }
    else{
      if(!(arr.empty())){
        cout << arr.top() << '\n';
        arr.pop();
     }
     else cout << 0 << '\n';
    }
  }
  return 0;
}
