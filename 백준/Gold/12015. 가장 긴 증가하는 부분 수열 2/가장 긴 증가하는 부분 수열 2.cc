#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[1000001];
vector<int> LIS;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        if (LIS.size() == 0 || LIS[LIS.size() - 1] < A[i]) {
            LIS.push_back(A[i]);
        }
        else {
            int left = 0;
            int right = LIS.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (LIS[mid] >= A[i]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            LIS[left] = A[i];
        }
    }
    cout << LIS.size() << '\n';
    return 0;
}
