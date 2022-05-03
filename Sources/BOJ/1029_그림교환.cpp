#include <cstdio>
#include <algorithm>

int N;
int price[15][15];
int cache[10][15][1 << 15];

// 현재 가격과 현재 소유주, 지금까지 그림을 소유했던 모든 소유주들이 비트마스킹으로 주어졌을 때
// 그림을 소유했던 사람들의 최댓값을 반환한다
int getOwners(int currentPrice, int currentOwner, int owners) {
  // 메모이제이션
  int& ret = cache[currentPrice][currentOwner][owners];
  if(ret) return ret;

  // i번째 사람이 이전에 그림을 소유하지 않았고, 마지막으로 구매했던 가격 이상의 돈으로 구매한다면
  // i번째 사람에게 그림을 판매한다
  for(int i = 0; i < N; i++)
    if(!(owners & (1 << i)) && price[currentOwner][i] >= currentPrice) 
      ret = std::max(ret, getOwners(price[currentOwner][i], i, owners | (1 << i)));

  return ++ret;
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      scanf("%1d", &price[i][j]);

  printf("%d\n", getOwners(0, 0, 1));  
}
