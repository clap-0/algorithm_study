#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  vector<vector<int>> info(3, vector<int>(4));
  cin >> n;
  for(int i=0; i<n; i++){ // 참가자번호, 점수총합, 제출횟수, 업로드시간을 배열에 저장
    info[i][0] = i+1;
    cin >> info[i][1] >> info[i][2] >> info[i][3];
  }
  vector<vector<int>>::iterator iter = info.begin();
  while(++iter!=info.end()){ // info배열의 첫번째 원소에 운영방식에 따라 정렬해 1위 참가자정보를 넣음
    if(info[0][1] < (*iter)[1]){
      iter_swap(info.begin(), iter);
    }
    else if(info[0][1]==(*iter)[1]){
      if(info[0][2] > (*iter)[2]){
        iter_swap(info.begin(), iter);
      }
      else if(info[0][2]==(*iter)[2]){
        if(info[0][3] > (*iter)[3]){
          iter_swap(info.begin(), iter);
        }
      }
    }
  }
  cout << info[0][0] << endl;
  return 0;
}
