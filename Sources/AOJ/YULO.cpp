#include <cstdio>
#include <algorithm>
using namespace std;
int score[40];
int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", score+i);
    // 기대점수를 낮추기 위해서는 점수가 가장 높은 학생과 가장 낮은 학생을 한 팀으로 묶어야 한다
    sort(score, score+N);
    // 학생 수가 홀수인 경우 등수가 중간인 학생은 팀으로 묶지 않아도 된다
    double ans = (N%2 ? score[N/2] : 0);
    for(int i=0; i<N/2; i++) ans=max(ans, (score[i]+score[N-1-i])/2.0);
    printf("%.1lf\n", ans);
  }
}
