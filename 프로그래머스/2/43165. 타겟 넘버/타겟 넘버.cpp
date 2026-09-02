#include <string>
#include <vector>

using namespace std;

int T;
int answer = 0;

void dfs(int idx, int sum, const vector<int>& numbers) {
    
    if (idx == numbers.size()) {
        if (sum == T) {
            answer++;
        }
        return;
    }
    
    // +
    dfs(idx + 1, sum + numbers[idx], numbers);
    
    // -
    dfs(idx + 1, sum - numbers[idx], numbers);

}

int solution(vector<int> numbers, int target) {
    T = target;
    
    dfs(0, 0, numbers);
    
    return answer;
}