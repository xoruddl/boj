#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m;
    for (auto a: participant) {
        if (m.end() == m.find(a)) {
            m.insert(make_pair(a, 1));
        }
        else {
            m[a]++;
        }
    }
    
    for (auto a : completion) {
        m[a]--;
    }
    
    for (auto a : participant) {
        if (m[a] > 0) {
            answer = a;
            break;
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    vector<string> p = {"leo", "kiki", "eden"};
    vector<string> c = {"eden", "kiki"};
    
    cout << solution(p, c);
    return 0;
}