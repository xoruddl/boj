#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(auto n: scoville) {
        pq.push(n);
    }
    
    while (pq.top() < K) {
        if (pq.size() == 1) {
            return -1;
        }
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a + b * 2);
        answer++;
    }
    

    return answer;
}