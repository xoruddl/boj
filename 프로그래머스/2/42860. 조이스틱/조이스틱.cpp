#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count(char c) {
    if (c <= 'N') {
        return c - 'A';
    } else {
        return 91 - c;
    }
}

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int move = n - 1;
    
    for (int i = 0; i < n; i++) {
        answer += count(name[i]);
        int next = i + 1;
        
        while (next < n && name[next] == 'A') {
            next++;
        }
        
        move = min(move, min(2 * i + n - next, (n - next) * 2 + i));
    }
    return answer + move;
}