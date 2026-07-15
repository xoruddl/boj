#include <string>
#include <vector>

using namespace std;

int getCount(int x) {
    int cnt = 0;
    
    for (int i = 1; i * i < x + 1; i++) {
        if (x % i == 0) {
            if (i == x / i) {
                cnt += 1;
            } else {
                cnt += 2;
            }
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++) {
        int c = getCount(i);
        answer += (c > limit) ? power : c;
    }
    return answer;
}