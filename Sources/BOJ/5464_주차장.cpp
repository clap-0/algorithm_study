#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// rate[i] = i번째 주차공간의 단위무게당 요금
// weight[i] = i번째 차량의 무게
// parkedSpace[i] = i번째 차량이 주차된 주차공간의 번호
// isParked[i] = i번째 주차공간에 주차가 되어있는지 여부
int rate[100], weight[2001], parkedSpace[2001];
bool isParked[100];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> rate[i];
  for(int i=1; i<=M; i++) cin >> weight[i];
  // 비어있는 주차공간이 없는 경우 큐에 넣는다
  queue<int> Q;
  int earnings=0, spaces=N;
  for(int i=0; i<2*M; i++){
    int order;
    cin >> order;
    // 차가 들어오는 경우
    if(order>0){
      // 비어있는 주차공간이 있다면 가장 번호가 작은 주차공간을 찾아 주차한다
      if(spaces>0){
        spaces--;
        for(int i=0; i<N; i++)
          if(!isParked[i]){
            isParked[i]=true;
            parkedSpace[order]=i;
            earnings+=rate[i]*weight[order];
            break;
          }
      }
      // 비어있는 주차공간이 없다면 큐에 차량번호를 넣는다
      else Q.push(order);
    }
    // 차가 나가는 경우
    else{
      int position=parkedSpace[-order];
      // 대기중인 차량이 있는 경우 차가 나간 자리에
      // 가장 빨리 온 대기차량을 넣는다
      if(!Q.empty()){
        int frontCar=Q.front();
        Q.pop();
        parkedSpace[frontCar]=position;
        earnings+=rate[position]*weight[frontCar];
      }
      // 대기중인 차량이 없는 경우 현재 주차공간의 수와
      // 차가 나간 자리가 비워진 것을 최신화시킨다
      else{
        spaces++;
        isParked[position]=false;
      }
    }
  }
  cout << earnings << '\n';
}
