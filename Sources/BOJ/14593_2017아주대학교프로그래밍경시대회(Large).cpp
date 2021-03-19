#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  vector<vector<int>> info(10000, vector<int>(4));
  cin >> n;
  for(int i=0; i<n; i++){ //배열에 참가자정보 저장
    info[i][0] = i+1;
    cin >> info[i][1] >> info[i][2] >> info[i][3];
  }
  vector<vector<int>>::iterator iter = info.begin();
  while(++iter!=info.end()){ //운영방식에 따라 정렬해 info배열 첫번째 원소에 1등 참가자정보 놓기
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
