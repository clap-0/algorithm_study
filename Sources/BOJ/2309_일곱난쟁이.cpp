#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  vector<int> dwarfs(9);
  int sum=0;
  for(int i=0; i<9; i++){
    cin >> dwarfs[i];
    sum += dwarfs[i];
  }
  for(int i=0; i<8; i++){
    for(int j=i+1; j<9; j++){
      if((sum-dwarfs[i]-dwarfs[j])==100){
        dwarfs[i] = dwarfs[j] = 999;
        break;
      }
    }
    if(dwarfs[i]==999) break;
  }
  sort(dwarfs.begin(), dwarfs.end());
  for(int i=0; i<7; i++){
    cout << dwarfs[i] << endl;
  }
  return 0;
}
