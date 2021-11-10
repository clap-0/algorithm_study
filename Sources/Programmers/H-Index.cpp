#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 인용횟수에 대해 내림차순 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    // 내림차순 정렬되어있으므로 i번째 인덱스에 대해
    // 해당 인덱스의 인용횟수 이상으로 인용된 논문들의 수는 i+1이다
    // 따라서 citations[i] >= i+1인 가장 큰 i를 구하면 된다
    for(int i=citations.size(); i>0; i--)
        if(citations[i-1] >= i){
            answer = i;
            break;
        }
        
    return answer;
}
