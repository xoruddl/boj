#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
double result;
int parent[1010];
vector<pair<int, int>> point;
vector<pair<int, int>> connect;
vector<pair<double, pair<int, int>>> Edge;

void Input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;

    // 점들 좌표 입력
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        point.push_back({x, y});
    }

    // 연결 간선 입력
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        connect.push_back({a, b});
    }
}

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}

double getDist(int x, int y, int xx, int yy) {
    double dx = pow(x - xx, 2);
    double dy = pow(y - yy, 2);
    double d = sqrt(dx + dy);
    return d;
}

void fc() {
    // 기존 통로 연결
    for (int i = 0; i < M; i++) {
        int n1 = connect[i].first;
        int n2 = connect[i].second;
        if (sameparent(n1, n2) == false) uni(n1, n2);
    }

    for (int i = 0; i < N - 1; i++) {
        int x = point[i].first;
        int y = point[i].second;

        for (int j = i + 1; j < N; j++) {
            int xx = point[j].first;
            int yy = point[j].second;

            double dist = getDist(x, y, xx, yy);
            Edge.push_back({dist, {i + 1, j + 1}});
        }
    }
    sort(Edge.begin(), Edge.end());

    for (int i = 0; i < Edge.size(); i++) {
        int n1 = Edge[i].second.first;
        int n2 = Edge[i].second.second;
        double dist = Edge[i].first;

        if (sameparent(n1, n2) == false) {
            uni(n1, n2);
            result = result + dist;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    fc();

    cout << fixed;
    cout.precision(2);
    cout << result << '\n';
    return 0;
}