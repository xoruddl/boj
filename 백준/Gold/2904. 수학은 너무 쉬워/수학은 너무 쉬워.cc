#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;

bool isPrime[MAX + 1];
int visited[MAX + 1];

void makePrime() {
    for (int i = 2; i <= MAX; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2 == 1) {
            res = res * x;
        }
        y /= 2;
        x = x * x;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    makePrime();

    int n;
    cin >> n;
    vector<int> plist;
    for (int i = 1; i <= MAX; i++) {
        if (isPrime[i]) plist.push_back(i);
    }
    vector<vector<int>> v(n, vector<int>(plist.size(), 0));

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        for (int j = 0; j < plist.size(); j++) {
            if (score == 1) break;
            while (score % plist[j] == 0) {
                score /= plist[j];
                visited[plist[j]]++;
                v[i][j]++;
            }
        }
    }

    int gcd = 1;
    int cnt = 0;
    for (int i = 0; i < plist.size(); i++) {
        int d = visited[plist[i]] / n;
        for (int j = 0; j < n; j++) {
            if (v[j][i] < d) {
                cnt += d - v[j][i];
            }
        }
        gcd *= power(plist[i], d);
    }
    cout << gcd << " " << cnt;
    return 0;
}