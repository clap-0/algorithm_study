#include <iostream>
using namespace std;
const int MAX_N=20000;
int N;
int height[MAX_N];
//[left,right] 범위내에서 얻을 수 있는 최대 직사각형의 넓이 반환
int maxRectangle(int left, int right){
  //기저사례 : 너비가 1이면 해당 나무판자의 넓이 반환
  if(left==right) return height[left];
  int mid = (left+right)/2;
  int ret = max(maxRectangle(left,mid), maxRectangle(mid+1,right));
  int lo = mid, hi = mid+1, h=min(height[lo],height[hi]);
  ret=max(ret, h*2);
  //왼쪽과 오른쪽 중 높이가 더 높은 나무판자 순으로 직사각형의 넓이를 구한다
  while(left<lo || hi<right){
    if(left<lo && (hi==right || height[lo-1]>height[hi+1])) h=min(h, height[--lo]);
    else h=min(h, height[++hi]);
    ret=max(ret, (hi-lo+1)*h);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int C;
  cin >> C;
  while(C--){
    cin >> N;
    for(int i=0; i<N; i++) cin >> height[i];
    cout << maxRectangle(0,N-1) << '\n';
  }
}
