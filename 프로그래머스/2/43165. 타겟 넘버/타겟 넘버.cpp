#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Target;
int ans;
vector<int> Numbers;

void dfs(int idx, int sum) {
    if (idx == N) {
        if (sum == Target) {
            ans++;
        }
        return;
    }
    
    // 더하기
    dfs(idx + 1, sum + Numbers[idx]);
    
    // 빼기
    dfs(idx + 1, sum - Numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    N = numbers.size();
    Numbers = numbers;
    Target = target;
    dfs(0, 0);
    
    return ans;
}