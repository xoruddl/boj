#include <iostream>
#include <string>

using namespace std;

int N, x, y, area;
int a[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    while (N--) {
        cin >> x >> y;
        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                if (!a[i][j]) {
                    area++;
                    a[i][j] = 1;
                }
            }
        }
    }
    cout << area << '\n';
    return 0;
}