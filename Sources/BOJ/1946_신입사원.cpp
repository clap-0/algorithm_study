#include <iostream>

using namespace std;

// scores[i] = 서류심사 성적이 i인 지원자의 면접성적
int scores[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
      int document, interview;
      cin >> document >> interview;
      // 정렬을 하지 않고, 각 지원자의 서류심사 성적에 해당하는 인덱스에
      // 면접성적을 넣어 서류심사 성적에 대해 오름차순 정렬되게 한다
      scores[document-1] = interview;
    }

    // i<j에 대해 scores[i].first < scores[j].first이 성립하므로 (위의 정렬때문에)
    // scores[i].second < scores[j].second라면 j는 탈락하게 된다
    // 따라서 마지막으로 채용된 지원자의 면접 성적을 저장하고
    // 그 성적보다 뛰어난 지원자를 뽑는 것을 반복한다
    int hired=0, interviewScore=N+1;
    for(int i=0; i<N; i++){
      if(scores[i] < interviewScore){
        interviewScore = scores[i];
        hired++;
      }
    }

    cout << hired << '\n';
  }
}
