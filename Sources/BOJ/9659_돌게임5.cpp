#include <cstdio>
using namespace std;
int main()
{
  long long N;
  scanf("%lld", &N);
  //돌을 홀수개수만큼(1개 또는 3개) 가져갈 수 있고
  //게임은 무조건 상근이부터 시작하므로
  //N이 홀수면 상근이가, 짝수면 창영이가 이길 수 밖에 없다
  printf("%s\n",N%2?"SK":"CY");
}
