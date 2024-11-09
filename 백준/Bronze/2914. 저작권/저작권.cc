#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int A, I;
    cin >> A >> I;
    
    cout << A * (I - 1) + 1;
}