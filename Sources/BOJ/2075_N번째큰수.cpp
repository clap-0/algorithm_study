#include <iostream>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, num;
  priority_queue<int, vector<int>, greater<int> > pq;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> num;
      pq.push(num);
    }
    if(i!=0)
      for(int cnt=0; cnt<n; cnt++)
        pq.pop();
  }
  cout << pq.top() << endl;
  return 0;
}
