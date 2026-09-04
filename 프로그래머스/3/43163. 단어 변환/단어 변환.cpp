#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[52];
int answer = 987654321, tmp;

bool oneDiff(string s1, string s2) { // 하나만 다른 문자열인지 확인
    int cnt = 0;
    
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            cnt++;
            if (cnt >= 2) {
                return false;
            }
        }
    }
    if (cnt == 1) return true;
}

void dfs(string cur, int cnt, string target, vector<string>& words) {
    if (cur == target) {
        answer = min(answer, cnt);
        return;
    }
    
    for (int i = 0; i < words.size(); i++) {
        if (visited[i]) continue;
        if (oneDiff(cur, words[i])) {
            visited[i] = true;
            dfs(words[i], cnt + 1, target, words);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    
    dfs(begin, 0, target, words);
    
    return answer;
}