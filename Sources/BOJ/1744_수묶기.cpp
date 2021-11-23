#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, sum=0;
  bool hasZero=false;
  // 내림차순. 1을 제외한 양수
  priority_queue<int> maxHeap;
  // 오름차순. 음수
  priority_queue<int, vector<int>, greater<int> > minHeap;

  cin >> N;
  for(int i=0; i<N; i++){
    int num;
    cin >> num;
    switch (num){
      case 0:
        hasZero=true;
        break;
      case 1:
        sum += 1;
        break;
      default:
        if(num>1) maxHeap.push(num);
        else minHeap.push(num);
    }
  }

  // 1을 제외한 양수에 대해서 큰 수끼리 묶는다
  while(!maxHeap.empty()){
    int first = maxHeap.top(); maxHeap.pop();
    // 하나밖에 없는 경우 sum에 더한다
    if(maxHeap.empty()){
      sum += first;
      break;
    }
    int second = maxHeap.top(); maxHeap.pop();
    sum += first*second;
  }

  // 작은 음수들끼리 묶는다
  while(!minHeap.empty()){
    int first = minHeap.top(); minHeap.pop();
    // 하나밖에 없는 경우 수열에 0이 있었다면 0과 묶고, 없었다면 sum에 더한다
    if(minHeap.empty()){
      sum += (hasZero ? 0 : first);
      break;
    }
    int second = minHeap.top(); minHeap.pop();
    sum += first*second;
  }

  cout << sum << '\n';
}
