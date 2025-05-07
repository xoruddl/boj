#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;

int binSearch(int n) {
    int low = 0;
    int high = A.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (n == A[mid]) {
            return 1;
        }
        else if (n < A[mid]) {
            high = mid - 1;
        }
        else if (n > A[mid]) {
            low = mid + 1;
        }
    }

    return 0;
}

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

        cout << binSearch(num) << '\n';
    }
}