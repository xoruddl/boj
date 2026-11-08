#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MOD 1000000007

typedef long long ll;

int dp[103][103];
vector<vector<int>> water;

int solution(int m, int n, vector<vector<int>> puddles) {
    water = puddles;
    int answer = 0;
    dp[1][1] = 1;
    
    for (auto p : puddles) {
        dp[p[1]][p[0]] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            
            ll left = dp[i][j - 1];
            ll up = dp[i - 1][j];
            
            dp[i][j] = (left + up) % MOD;
        }
    }
    
    return dp[n][m] % MOD;
    
}