#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    cin >> N;
    if (N == 2) {
        cout << "NO\n";
    }
    else {
        for (int i = 4; i <= N; i++) {
            v.push_back(i);
        }

        cout << "YES\n";
        for (int i = 0; i < N; i++) {
            cout << v[i] << " ";
        }
    }
}