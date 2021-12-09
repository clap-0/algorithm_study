#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  // wateringCnt = 2번 물뿌리개로 물을 줄 수 있는 횟수
  int N, sum=0, wateringCnt=0;
  cin >> N;
  for(int i=0; i<N; i++){
    int h;
    cin >> h;
    sum += h;
    wateringCnt += h/2;
  }
  // 1번과 2번 물뿌리개를 사용하면 한번 물을 줄 때마다 총 3만큼 나무가 성장하므로 사과나무 높이는 결과적으로 3의 배수여야 한다
  // 1번 물뿌리개를 사용했을 때 자라는 수치 1이 나무길이의 최소 단위와 같으므로 물을 줘야 하는 횟수는 2번 물뿌리개로 물을 줄 수 있는 횟수보다 작거나 같다
  if(sum%3==0 && wateringCnt>=sum/3){
    cout << "YES" << '\n';
  }
  else {
    cout << "NO" << '\n';
  }
}
