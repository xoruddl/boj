#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;

int solution(int n) {
    int answer = 0;
    
    while (n) {
        v.push_back(n % 3);
        n = n / 3;
    }
    
    reverse(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        answer += v[i] * pow(3, i);
    }
    
    return answer;
}