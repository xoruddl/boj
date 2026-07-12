#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int N = s.size();
    
    for (int i = 0; i < N; i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            answer += (s[i] - 'A' + n) % 26 + 'A';
        } else if (s[i] >= 97 && s[i] <= 122) {
            answer += (s[i] - 'a' + n) % 26 + 'a';
        } else {
            answer += s[i];
        }
    }
    
    return answer;
}