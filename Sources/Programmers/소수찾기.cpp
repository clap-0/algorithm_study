#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

std::vector<bool> isPrime;

using namespace std;

// 에라토스테네스의 체 알고리즘
void eratosthenes(int numbers) {
    isPrime = vector<bool>(numbers + 1, true);
    isPrime[0] = isPrime[1] = false;
    int sqrtn = (int)sqrt(numbers);
    for(int i = 2; i <= sqrtn; i++)
        if(isPrime[i]) 
            for(int j = i * i; j <= numbers; j += i)
                isPrime[j] = false;
}

int solution(string numbers) {
    // 종이조각으로 만들 수 있는 가장 큰 수까지의 수들에 대하여 소수판별을 한다
    sort(numbers.begin(), numbers.end(), greater<int>());
    eratosthenes(stoi(numbers));
  
    // next_permutation()을 위해 오름차순 정렬
    reverse(numbers.begin(), numbers.end());
    int len = numbers.length();
    set<int> primes;
    do {
        for(int i = 0; i < len; i++) {
            int num = stoi(numbers.substr(i));
            if(isPrime[num]) {
                primes.insert(num);
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return primes.size();
}
