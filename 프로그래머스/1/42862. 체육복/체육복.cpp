#include <string>
#include <vector>

using namespace std;

vector<int> students(33, 1);

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (auto i : lost) {
        students[i]--;
    }
    for (auto i : reserve) {
        students[i]++;
    }
    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) {
            if (students[i - 1] == 2) {
                students[i]++;
                students[i - 1]--;
            } else if (students[i + 1] == 2) {
                students[i]++;
                students[i + 1]--;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (students[i]) {
            answer++;
        }
    }
    
    return answer;
}