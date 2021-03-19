#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> lessons;
bool f(long long blueraySize){ //정해진 블루레이크기에 모든 레슨 녹화시 m개 이하인지 반환
  int cnt=1;
  long long temp=0;
  for(auto &length : lessons){
    if(length > blueraySize) return 0; //블루레이크기보다 영상길이가 더 길면 불가능
    temp+=length;
    if(temp>blueraySize){
      cnt++;
      temp=length;
    }
  }
  if(cnt>m) return 0;
  else return 1;
}
int main()
{
  long long sum=0, ans=987654321;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    int length;
    cin >> length;
    lessons.push_back(length);
    sum+=length;
  }
  long long lo=0, hi=sum;
  //불변식 1.lo일 땐 모든 레슨 블루레이m개 이하로 녹화불가
  //불변식 2.hi일 땐 모든 레슨 블루레이m개 이하로 녹화가능
  while(lo<=hi){
    long long mid = (lo+hi)/2;
    if(f(mid)){
      hi = mid-1;
      ans = min(ans, mid);
    }
    else lo = mid+1;
  }
  cout << ans << endl;
  return 0;
}
