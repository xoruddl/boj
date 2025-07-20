#include <iostream>
#include <vector>

using namespace std;

int checkArr[4];
int myArr[4];
int checkSecret;
int S, P;
string A;
int ans;

void Add(char c);
void Remove(char c);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> S >> P;
    cin >> A;
    for (int i = 0; i < 4; i++) {
        cin >> checkArr[i];
        if (checkArr[i] == 0) {
            checkSecret++;
        }
    }

    for (int i = 0; i < P; i++) {
        Add(A[i]);
    }
    if (checkSecret == 4) {
        ans++;
    }

    for (int i = P; i < S; i++) {
        int j = i - P;
        Add(A[i]);
        Remove(A[j]);

        if (checkSecret == 4) {
            ans++;
        }
    }
    cout << ans;
}

void Add(char c) {
    switch (c) {
        case 'A':
            myArr[0]++;
            if (myArr[0] == checkArr[0]) {
                checkSecret++;
            }
            break;
        case 'C':
            myArr[1]++;
            if (myArr[1] == checkArr[1]) {
                checkSecret++;
            }
            break;
        case 'G':
            myArr[2]++;
            if (myArr[2] == checkArr[2]) {
                checkSecret++;
            }
            break;
        case 'T':
            myArr[3]++;
            if (myArr[3] == checkArr[3]) {
                checkSecret++;
            }
            break;
    }
}

void Remove(char c) {
    switch (c) {
        case 'A':
            if (myArr[0] == checkArr[0]) {
                checkSecret--;
            }
            myArr[0]--;
            break;
        case 'C':
            if (myArr[1] == checkArr[1]) {
                checkSecret--;
            }
            myArr[1]--;
            break;
        case 'G':
            if (myArr[2] == checkArr[2]) {
                checkSecret--;
            }
            myArr[2]--;
            break;
        case 'T':
            if (myArr[3] == checkArr[3]) {
                checkSecret--;
            }
            myArr[3]--;
            break;
    }
}