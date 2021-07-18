#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  int C;
  scanf("%d", &C);
  while(C--){
    int N;
    int russian[100], korean[100];
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", russian+i);
    for(int i=0; i<N; i++) scanf("%d", korean+i);
    //최대 승수가 필요하므로 순서는 상관이 없다
    sort(russian, russian+N);
    sort(korean, korean+N);
    //러시아팀의 레이팅이 가장 낮은 선수를 한국팀의 이길 수 있는 선수와 붙인다
    int win=0, rusP=0;
    for(int korP=0; korP<N; korP++)
      if(korean[korP]>=russian[rusP]){
        win++;
        rusP++;
      }
    printf("%d\n", win);
  }
}
