#include <iostream>
using namespace std;
char rectangle[50][50];
int main()
{
  int n, m, largest=1;
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> rectangle[i];
  
  for(int y=0; y<n-1; y++){
    for(int x=0; x<m-1; x++){
      int len=1;
      char check = rectangle[y][x];
      while((y+len<n)&&(x+len<m)){
        if(check==rectangle[y+len][x+len]&&rectangle[y][x+len]==rectangle[y+len][x]&&check==rectangle[y][x+len]) largest=max(largest, (len+1)*(len+1));
        len++;
      }
    }
  }
  cout << largest << endl;
  return 0;
}
