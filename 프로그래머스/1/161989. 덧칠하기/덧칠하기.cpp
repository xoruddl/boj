#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int t = 0;
    for (int i = 0; i < section.size(); i++) {
        if (section[i] <= t) {
            continue;
        }
        t = section[i] + m - 1;
        if (t > n) {
            answer++;
            break;
        }
        answer++;
    }
    return answer;
}