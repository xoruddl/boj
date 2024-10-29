#include <iostream>

#define MAX 1000000003

using namespace std;

long long N;
bool check[1000000003]; //소수면 0, 합성수면 1

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while (1) {
        if (!isPrime(N)) {
            cout << N;
            break;
        }
        N++;
    }
}
