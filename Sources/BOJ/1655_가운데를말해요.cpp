#include <iostream>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  priority_queue<int, vector<int>, less<int> > maxHeap;
  priority_queue<int, vector<int>, greater<int> > minHeap;
  cin >> n;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    //최대힙의 크기는 최소힙크기와 같거나, 하나 더 많아야 한다
    if(maxHeap.size()==minHeap.size()) maxHeap.push(num);
    else minHeap.push(num);
    //최대힙의 최대원소는 최소힙의 최소원소보다 작거나 같아야 한다
    if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top()>minHeap.top()){
      int a = maxHeap.top(), b = minHeap.top();
      maxHeap.pop(); minHeap.pop();
      maxHeap.push(b); minHeap.push(a);
    }
    cout << maxHeap.top() << '\n';
  }
}
