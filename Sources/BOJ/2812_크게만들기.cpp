#include <iostream>
#include <string>
#include <deque>
using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, K;
  string number;
  cin >> N >> K >> number;
  
  // vector를 사용했을 때에 비해 메모리사용량이 적고, 새로운 원소 추가시 성능이 저하되는 단점 보완
  deque<char> dq;

  for(int i=0; i<N; i++){
    // 1. 가장 왼쪽의 a < b를 만족하는 a를 지운다 (417725에서 1)
    while(!dq.empty() && dq.back() < number[i] && K > 0){
      dq.pop_back();
      --K;
    }
    dq.push_back(number[i]);
  }
  // 2. 1의 조건을 만족하는 수가 없는 경우 마지막 수를 지운다 (775에서 5)
  while(K--){
    dq.pop_back();
  }
  
  for(char num : dq) cout << num;
}
