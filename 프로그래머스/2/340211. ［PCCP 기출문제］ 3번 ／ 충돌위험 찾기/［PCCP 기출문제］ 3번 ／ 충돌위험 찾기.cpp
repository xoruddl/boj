#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<pair<int, pair<int, int>>, int> M;
int m;

void update(pair<int, pair<int, int>> p) {
    if (M.find(p) != M.end()) {
        M[p] += 1;
    } else {
        M[p] = 1;
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    m = routes[0].size();
    
    for (auto& route: routes){
        int time = 0;
        for (int j = 0; j < m - 1; j++) {
            int start = route[j] - 1;
            int end = route[j + 1] - 1;
            
            int y = points[start][0];
            int x = points[start][1];
            
            int ny = points[end][0];
            int nx = points[end][1];
            
            int dy = ny - y > 0 ? 1 : -1;
            int dx = nx - x > 0 ? 1 : -1;
            
            if (j == 0) {
                update({time++, {y, x}});
            }
            
            while (y != ny) {
                y += dy;
                update({time++, {y, x}});
            }
            while (x != nx) {
                x += dx;
                update({time++, {y, x}});
            }
        }
    }
    
    int answer = 0;
    for (auto& pM: M){
        if (pM.second > 1){
            answer += 1;
        }
    }
    return answer;
}