#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        cout << binary_search(A.begin(), A.end(), num) << '\n';
    }
}