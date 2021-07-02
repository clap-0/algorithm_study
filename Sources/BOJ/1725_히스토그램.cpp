#include <iostream>
using namespace std;
int height[100000];
//분할정복을 이용한 풀이
int solve(int left, int right){
  //기저사례 : 더 이상 분할이 되지 않는 경우 해당 칸의 높이 반환
  if(left==right) return height[left];
  int mid=(left+right)/2;
  int ret=max(solve(left, mid), solve(mid+1,right));
  //중앙에서부터 좌,우 중 높이가 더 높은 곳 순으로 직사각형의 넓이를 구한다
  int lo=mid, hi=mid+1, h=min(height[lo], height[hi]);
  ret=max(ret, h*2);
  while(left<lo || hi<right){
    if(hi<right && (lo==left || height[lo-1]<height[hi+1])) h=min(h, height[++hi]);
    else h=min(h, height[--lo]);
    ret=max(ret, (hi-lo+1)*h); 
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> height[i];
  cout << solve(0, N-1) << '\n';
}
