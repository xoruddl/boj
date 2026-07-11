#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> table;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); i++) {
        char cur = s[i];
        if (table.find(cur) == table.end()) {
            table[cur] = i;
            answer.push_back(-1);
        } else {
            answer.push_back(i - table[cur]);
            table[cur] = i;
        }
    }
    
    return answer;
}