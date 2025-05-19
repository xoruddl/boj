#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

int N, M;
int MAZE[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int,int> > q;

void bfs(int x, int y){
    visited[x][y] = 1;
    q.push(make_pair(x, y));
    dist[x][y]++;
    
    while (!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i){
            int nx = a + dx[i];
            int ny = b + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && MAZE[nx][ny] == 1){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                dist[nx][ny] = dist[a][b] + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    
    for (int i = 0; i < N; i++){
        string row;
        cin >> row;
        
        for (int j = 0; j < M; j++){
            MAZE[i][j] = row[j] - '0';
        }
    }
    
    bfs(0, 0);
    
    cout << dist[N - 1][M - 1];
}