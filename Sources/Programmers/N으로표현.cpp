#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// dp[i] = N을 i번 사용하여 만들 수 있는 수의 집합
// 중복을 제거하기 위해 set을 사용했다.
unordered_set<int> dp[9];

int solution(int N, int number) {
    // N과 number이 같은 경우 N을 한 번만 사용한다
    if(N == number) return 1;
    
    dp[1].insert(N);
    
    int temp = N;
    for(int k = 2; k < 9; k++) {
        // temp = k자리의 N으로만 이루어진 수
        temp = temp * 10 + N;
        dp[k].insert(temp);
        
        // N을 i번 사용하여 만드는 수들과 k-i번 사용하는 수들로
        // 사칙연산을 한 값들 중 양수들만을 dp[k]에 저장한다
        for(int i = 1; i < k; i++) {
            int j = k - i;
            for(int a : dp[i]) {
                for(int b : dp[j]) {
                    dp[k].insert(a + b);
                    if(a - b > 0) dp[k].insert(a - b);
                    dp[k].insert(a * b);
                    if(a >= b) dp[k].insert(a / b);
                }
            }
        }
      
        // N을 k번 사용하여 number을 만든 경우 k 반환
        if(dp[k].count(number)) return k;
    }
    return -1;
}
