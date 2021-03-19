#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
  int n, m;
  vector<string> itosPokedex; //포켓몬번호기준으로 도감 정렬
  map<string, int> stoiPokedex; //포켓몬이름기준으로 도감 정렬
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    char pokemon[21];
    scanf("%s", pokemon);
    itosPokedex.push_back(string(pokemon));
    stoiPokedex.insert({string(pokemon), i});
  }
  for(int i=0; i<m; i++){
    char test[21];
    scanf("%s", test);
    if(test[0]>='0'&&test[0]<='9') //입력이 숫자로 들어오면 포켓몬이름 출력
      cout << itosPokedex[atoi(test)-1] << '\n';
    else //입력이 문자로 들어오면 포켓몬번호 출력
      printf("%d\n", stoiPokedex[string(test)]);
  }
}
