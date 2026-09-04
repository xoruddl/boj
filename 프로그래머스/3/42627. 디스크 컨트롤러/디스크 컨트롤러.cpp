#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct P {
    int idx;
    int start;
    int work;
    
    bool operator < (const P& o) const {
        if (work != o.work) {
            return work > o.work;
        }
        if (start != o.start) {
            return start > o.start;
        }
        return idx > o.idx;
    }
};

priority_queue<P> pq;


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    int i = 0;
    int time = 0;
    
    sort(jobs.begin(), jobs.end());
    
    while (1) {
        if (i >= n && pq.empty()) {
            break;
        }
        
        while (i < n && time >= jobs[i][0]) {
            pq.push({i, jobs[i][0], jobs[i][1]});
            i++;
        }
        
        if (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            
            time += p.work;
            
            answer += time - p.start;
        } else {
            time = jobs[i][0];
        }
    }
    
    return answer / n;
}