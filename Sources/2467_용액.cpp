#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  int solution[100000];
  cin >> N;
  for(int i=0; i<N; i++) cin >> solution[i];
  //양 끝의 용액부터 시작해서
  //합이 양수면 합을 줄이는 방향으로,
  //합이 음수면 합을 늘리는 방향으로 lo나 hi를 옮긴다
  int A, B, least=2e9, lo=0, hi=N-1, sum;
  while(lo<hi){
    sum = solution[lo]+solution[hi];
    //지금까지 찾은 것보다 0에 더 가까운 용액을 만들 수 있는 경우 최신화
    if(abs(sum)<least){
      A=solution[lo], B=solution[hi];
      least = abs(sum);
    }
    if(sum>0) hi--;
    else lo++;
  }
  cout << A << ' ' << B << '\n';
}
