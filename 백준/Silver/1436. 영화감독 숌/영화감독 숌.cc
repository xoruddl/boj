#include <iostream>

using namespace std;

int fc(int n) {
    string target = "";
    int cnt = 0;

    int i = 666;
    while (1) {
        target = to_string(i);
        for (int j = 0; j < target.size() - 2; j++) {
            if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6') {
                cnt++;
                if (cnt == n) {
                    return i;
                }
                break;
            }
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    cout << fc(N);
}
