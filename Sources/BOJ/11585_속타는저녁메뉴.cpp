#include <iostream>
#include <algorithm>
using namespace std;

char P[1000000];
int fail[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  // 룰렛이 원형이라 P를 돌리면 현재 룰렛의 순서가 나오기 때문에 굳이 입력받지 않았다
  for(int i = 0; i < N; i++) cin >> P[i];

  // 배열 P[]의 실패함수를 구한다
  for(int i = 1, j = 0; i < N; i++) {
    while(j > 0 && P[i] != P[j]) j = fail[j - 1];
    if(P[i] == P[j]) fail[i] = ++j;
  }

  // tmp : P를 P의 특정 접두사 문자열의 반복으로 나타낼 수 있는 가장 많은 횟수
  int tmp = N / (N - fail[N - 1]);
  if(N % tmp) tmp = 1;
  cout << 1 << "/" << N / tmp << '\n';
}
