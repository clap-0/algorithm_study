#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > adj; //인접행렬
vector<int> degree; 
bool checkEuler() //오일러회로가 가능한지 리턴하는 함수
{
  for(int i=0; i<degree.size(); i++){
    if(degree[i]%2)
      return false;
  }
  return true;
}
void getEulerCircuit(int here, vector<int>& circuit) //here에서 시작하는 오일러 회로 만듬
{
  for(int there=0; there<adj.size(); there++)
    while(adj[here][there]>0){
      adj[here][there]--;
      adj[there][here]--;
      getEulerCircuit(there, circuit);
    }
  circuit.push_back(here+1);
}
int main()
{
  int n;
  cin >> n;
  vector<int> circuit;
  adj = vector<vector<int> >(n, vector<int>(n, 0));
  degree = vector<int>(n, 0);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      cin >> adj[i][j];
      degree[i] += adj[i][j]; //각 정점의 차수 저장
    }
  
  if(checkEuler()){
    getEulerCircuit(0, circuit);
    reverse(circuit.begin(), circuit.end()); //양방향그래프이므로 굳이 안 해도 됨
  }
  else circuit.push_back(-1);
  for(int i=0; i<circuit.size(); i++)
    cout << circuit[i] << ' ';
  return 0;
}
