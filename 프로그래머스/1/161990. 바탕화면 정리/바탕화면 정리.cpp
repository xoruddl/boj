#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int n = wallpaper.size();
    int m = wallpaper[0].size();
    
    // #의 좌표를 다 구하고 맨 왼쪽 위의 값과 맨 오른쪽 아래 값을 구한다.
    int rdx = -1, rdy = -1, lux = 999, luy = 999;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (wallpaper[i][j] == '#') {
                if (lux > i) {
                    lux = i;
                }
                if (luy > j) {
                    luy = j;
                }
                if (rdx < i + 1) {
                    rdx = i + 1;
                }
                if (rdy < j + 1){
                    rdy = j + 1;
                }
            }
        }
    }
    
    answer = {lux, luy, rdx, rdy};
    
    return answer;
}