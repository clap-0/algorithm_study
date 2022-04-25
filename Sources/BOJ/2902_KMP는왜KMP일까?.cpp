#include <cstdio>

int main()
{
  printf("%c", getchar());
  char ch;
  while((ch = getchar()) != '\n')
    // 성의 앞 글자를 제외하면 모두 소문자나 하이픈이다
    if('A' <= ch && ch <= 'Z') printf("%c", ch);
}
