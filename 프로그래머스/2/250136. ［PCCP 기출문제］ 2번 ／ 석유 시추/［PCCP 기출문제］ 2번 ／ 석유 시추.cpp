#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 987654321

vector<int> wides; // 구역별 너비
vector<bool> isVArea; // 구역별로 방문을 했는지
vector<vector<int>> visited; // 너비 계산할 때 사용할 방문여부 배열
int n, m;
vector<vector<int>> table; // 각 좌표에 해당하는 구역 번호 할당
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q;
int areaIdx = 0; // 구역 번호

int bfs(int y, int x, vector<vector<int>>& land){
    // 구역 별 너비 구하기
    int area = 0;
    visited[y][x] = true;
    q.push({y, x});
    table[y][x] = areaIdx;
    
    while (!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        int curCost = land[cy][cx];
        table[cy][cx] = areaIdx;
        visited[cy][cx] = true;
        q.pop();
        area += 1;
        
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m){
                continue;
            }
            if (visited[ny][nx] || land[ny][nx] == MAX) continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    
    // for (int i = 0;i<n;i++){
    //     for(int j = 0;j < m;j++){
    //         cout << land[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    return area;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    visited.assign(n, vector<int>(m, 0));
    table.assign(n, vector<int>(m, 0));
    
    // 1을 제일 큰수로 변환하고 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < m;j++) {
            if (land[i][j] == 0){
                land[i][j] = MAX;
                table[i][j] = MAX;
            }
        }
    }
    

    
    // 구역별 너비 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == MAX) continue;
            if (visited[i][j]) continue;
            wides.push_back(bfs(i, j, land));
            areaIdx += 1;
        }
    }
//     for (auto& c: wides){
//         cout << c << " ";
//     }
//     cout << '\n';
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0;j < m; j++ ){
//             cout <<  table[i][j] << " ";
//         }
//         cout << '\n';
//     }
    
    
    // 각 열 별 값 구하기
    isVArea.resize(wides.size(), false);
    
    for (int j = 0; j < m; j++) {
        int temp = 0;
        
        for (int i = 0; i < wides.size(); i++) {
            isVArea[i] = false;
        }
        for (int i = 0; i < n; i++) {
            int ai = table[i][j];
            if (ai == MAX) continue;
            if (!isVArea[ai]) {
                temp += wides[ai];
                isVArea[ai] = true;
            }
        }
        
        if (temp > answer) {
            answer = temp;
        }
    }
    
    return answer;
}