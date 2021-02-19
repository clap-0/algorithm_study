#include <iostream>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, x;
  priority_queue< int, vector<int>, greater<int> > arr; //오름차순 정렬하는 우선순위큐 만들기
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
