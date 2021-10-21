#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int N=phone_book.size();
    // phone_book을 사전순으로 정렬하게 되면
    // B의 접두사인 A가 있다고 가정할 때 무조건 A 바로 다음 인덱스에 B가 있게 된다
    sort(phone_book.begin(), phone_book.end());
    for(int n=0; n<N-1; n++){
        if(phone_book[n].length()<phone_book[n+1].length()){
            bool isPrefix=true;
            for(int i=0; i<phone_book[n].length(); i++){
                if(phone_book[n][i]!=phone_book[n+1][i]){
                    isPrefix=false;
                    break;
                }
            }
            if(isPrefix){
                answer=false;
                break;
            }
        }
    }
    return answer;
}
