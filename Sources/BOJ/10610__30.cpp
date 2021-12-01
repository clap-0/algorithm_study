#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string N;
  cin >> N;

  // 각 자릿수의 합이 3의 배수이어야 30의 배수이다
  int sum=0;
  for(int i=0; i<N.length(); i++) sum += N[i]-'0';
  if(sum%3){
    cout << -1 << '\n';
    return 0;
  }

  // 내림차순 정렬했을 때 마지막 자릿수(1의자리)가 0이어야 한다
  sort(N.rbegin(), N.rend());
  if(N[N.length()-1] != '0'){
    cout << -1 << '\n';
    return 0;
  }

  cout << N << '\n';
}
