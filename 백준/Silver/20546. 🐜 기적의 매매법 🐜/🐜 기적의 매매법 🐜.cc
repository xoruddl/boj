#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> v(14);
    for (auto& i : v) {
        cin >> i;
    }

    int j_money = n, s_money = n, j_stock = 0, s_stock = 0;
    for (int i = 0; i < 14; i++) {
        // 준현
        while (j_money >= v[i]) {
            j_stock++;
            j_money -= v[i];
        }

        // 성민
        if (2 < i) {
            if (v[i - 3] < v[i - 2] && v[i - 2] < v[i - 1]) {
                while (s_stock > 0) {
                    s_stock--;
                    s_money += v[i];
                }
            }
            else if (v[i - 3] > v[i - 2] && v[i - 2] > v[i - 1]) {
                while (s_money >= v[i]) {
                    s_stock++;
                    s_money -= v[i];
                }
            }
        }
    }
    int j_result = j_money + j_stock * v[13];
    int s_result = s_money + s_stock * v[13];

    if (j_result > s_result) {
        cout << "BNP";
    }
    else if (j_result < s_result) {
        cout << "TIMING";
    }
    else {
        cout << "SAMESAME";
    }
    return 0;
}



