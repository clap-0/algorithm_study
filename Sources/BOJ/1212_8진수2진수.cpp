#include <iostream>
#include <string>
using namespace std;

string octToBin(int oct)
{
  string bin;
  bin += to_string(oct / 4); oct %= 4;
  bin += to_string(oct / 2); oct %= 2;
  bin += to_string(oct);
  return bin;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string oct;
  cin >> oct;
  if (oct == "0")
    cout << "0\n";
  else {
    string bin;
    for (char o : oct)
      bin += octToBin(o - '0');
    int i = 0;
    while (bin[i] == '0')
      ++i;
    cout << bin.substr(i);
  }
}
