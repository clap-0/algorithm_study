#include <iostream>
#include <algorithm>
using namespace std;

string words[50];

// A가 B의 접두사면 true, 아니면 false를 반환하는 함수
// A의 길이는 항상 B의 길이보다 작거나 같다.
bool isPrefix(string A, string B)
{
  int length = A.length();
  for (int i = 0; i < length; i++)
    if (A[i] != B[i])
      return false;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> words[i];

  // words를 사전순으로 오름차순 정렬한다.
  sort(words, words + N);

  int ans = 1;  // 접두사X집합에는 최소 하나의 원소가 들어간다.
  for (int i = 1; i < N; i++)
  {
    string word1 = words[i - 1], word2 = words[i];
    // word1은 항상 word2보다 길이가 작거나 같다.
    if (word1.length() > word2.length())
      swap(word1, word2);
    // 사전순으로 바로 이전인 단어가 i번 단어의 접두사가 아니면 접두사X집합의 크기 증가
    if (!isPrefix(word1, word2))
      ++ans;
  }
  cout << ans << '\n';
}
