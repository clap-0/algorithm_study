#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int m, cnt;
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    cin >> m;
    cout << (m+1)/2 << '\n';
    //홀수번째 수를 입력받을때마다 중앙값 출력
    for(cnt=1; cnt<=m; cnt++){
      int num;
      cin >> num;
      //불변식1: 최대힙의 크기는 최소힙 크기와 같거나, 하나 더 크다
      if(maxHeap.size()==minHeap.size()) maxHeap.push(num);
      else minHeap.push(num);
      //불변식2: 최대힙의 최대원소는 최소힙 최소원소보다 작거나 같다
      if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top()>minHeap.top()){
        int a = maxHeap.top(), b = minHeap.top();
        maxHeap.pop(); minHeap.pop();
        maxHeap.push(b); minHeap.push(a);
      }
      if(cnt%2) cout << maxHeap.top() << ' ';
      if(cnt%20==0) cout << '\n'; //한 줄에 10개씩 출력
    }
    if((cnt-1)%20) cout << '\n';
  }
}
