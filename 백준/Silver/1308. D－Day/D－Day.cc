#include <iostream>

using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYoonYear(int year) {
    bool flag = false;
    if (year % 4 == 0) {
        flag = true;
        if (year % 100 == 0) flag = false;
        if (year % 400 == 0) flag = true;
    }
    return flag;
}

int days(int y, int m) {
    int count = 0;
    for (int i = 1; i <= y; i++) {
        for (int j = 0; j < (i == y ? m - 1 : 12); j++) {
            count += month[j];
        }
        if (isYoonYear(i)) count++;
    }
    if (isYoonYear(y) && m < 3) --count;
    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int y1, m1, d1, y2, m2, d2, result;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    if ((y2 - y1) == 1000) {
        if (m2 > m1) {
            cout << "gg";
            return 0;
        }
        if (m2 == m1) {
            if (d2 >= d1) {
                cout << "gg";
                return 0;
            }
        }
    }
    else if ((y2 - y1) > 1000) {
        cout << "gg";
        return 0;
    }
    
    result = (days(y2, m2) + d2) - (days(y1, m1) + d1);
    cout << "D-" << result;
}