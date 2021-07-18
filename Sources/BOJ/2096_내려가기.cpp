#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int N;
  int num[3], minScore[2][3]={0}, maxScore[2][3]={0};
  scanf("%d", &N);
  //슬라이딩 윈도우 기법과 DP를 이용하여 문제풀기
  for(int r=0; r<N; r++){
    scanf("%d %d %d", num, num+1, num+2);
    minScore[r%2][0]=min(minScore[(r+1)%2][1], minScore[(r+1)%2][0])+num[0];
    maxScore[r%2][0]=max(maxScore[(r+1)%2][1], maxScore[(r+1)%2][0])+num[0];
    minScore[r%2][1]=min(minScore[(r+1)%2][1], min(minScore[(r+1)%2][0], minScore[(r+1)%2][2]))+num[1];
    maxScore[r%2][1]=max(maxScore[(r+1)%2][1], max(maxScore[(r+1)%2][0], maxScore[(r+1)%2][2]))+num[1];
    minScore[r%2][2]=min(minScore[(r+1)%2][1], minScore[(r+1)%2][2])+num[2];
    maxScore[r%2][2]=max(maxScore[(r+1)%2][1], maxScore[(r+1)%2][2])+num[2];
  }
  printf("%d %d\n", max(maxScore[(N-1)%2][0],max(maxScore[(N-1)%2][1],maxScore[(N-1)%2][2])), min(minScore[(N-1)%2][0],min(minScore[(N-1)%2][1],minScore[(N-1)%2][2])));
}
