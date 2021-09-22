#include <iostream>
#include <string>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  //기본변수형과 추가적인 변수형
  string basic;
  cin >> basic;
  while(1){
    int i=0;
    string str;
    cin >> str;
    
    //주어진 변수선언을 변수명 str[0,i)과 추가적인 변수형 str[i,str.size()-1)로 나눈다
    while(('a'<=str[i]&&str[i]<='z')||('A'<=str[i]&&str[i]<='Z')) i++;
    
    cout << basic;
    for(int c=str.size()-2; c>=i; c--) cout << (str[c]=='['?']':(str[c]==']'?'[':str[c]));
    cout << " ";
    for(int c=0; c<i; c++) cout << str[c];
    cout << ";\n";
    if(str[str.size()-1]==';') break;
  }
}
