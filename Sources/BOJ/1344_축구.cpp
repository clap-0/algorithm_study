#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//간격의 수
const int MAX=90/5;
//각 팀이 득점할 확률
double A, B;
double cache[MAX][MAX+1][MAX+1];
//소수인지 여부 저장
bool isPrime[MAX+1];
//에라토스테네스의 체 알고리즘
void eratosthenes(){
  fill(isPrime+2, isPrime+MAX+1, true);
  int sqrtn = int(sqrt(MAX));
  for(int i=2; i<=sqrtn; i++)
    if(isPrime[i]){
      for(int j=i*i; j<=MAX; j+=i) isPrime[j]=false;
    }
}
//DP를 이용하여 현재 간격, A팀의 득점 수, B팀의 득점 수가 주어질 때
//적어도 한 팀이 골을 소수로 득점할 확률을 구한다
double primeGoal(int interval, int aScore, int bScore){
  //기저사례 : 경기가 끝난 후 한 팀이라도 득점수가 소수인 경우 1.0 반환
  if(interval==MAX) return isPrime[aScore] || isPrime[bScore];
  //메모이제이션
  double& ret = cache[interval][aScore][bScore];
  if(ret>-0.5) return ret;
  return ret = 
    //A팀이 득점하고 B팀은 득점 못 할 확률
    A*(1-B)*primeGoal(interval+1, aScore+1, bScore) + 
    //B팀이 득점하고 A팀은 득점 못 할 확률
    (1-A)*B*primeGoal(interval+1, aScore, bScore+1) + 
    //A팀과 B팀 모두 득점할 확률
    A*B*primeGoal(interval+1, aScore+1, bScore+1) + 
    //A팀과 B팀 모두 득점 못 할 확률
    (1-A)*(1-B)*primeGoal(interval+1, aScore, bScore);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int percentA, percentB;
  cin >> percentA >> percentB;
  //백분율로 확률을 구한다
  A=percentA/100.0; B=percentB/100.0;
  fill((double*)cache, (double*)(cache+MAX), -1.0);
  eratosthenes();
  //소수점 아래 16자리까지 출력
  cout << fixed; cout.precision(16);
  cout << primeGoal(0, 0, 0) << '\n';
}
