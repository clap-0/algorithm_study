#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // sum : 가로길이와 세로길이의 합
    // product : 가로길이와 세로길이의 곱
    int sum = (brown+4)/2, product = brown+yellow;

    for(int x=sum-1; x>0; x--){
        if(x*(sum-x) == product){
            answer.push_back(x);
            answer.push_back(sum-x);
            break;
        }
    }

    return answer;
}
