#include <iostream>
#include <vector>
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
        dwarfs.erase(dwarfs.begin()+i);
        dwarfs.erase(dwarfs.begin()+j-1);
        break;
      }
    }
    if(dwarfs.size()==7) break;
  }
  for(int i=0; i<7; i++){
    cout << dwarfs[i] << endl;
  }
  return 0;
}
