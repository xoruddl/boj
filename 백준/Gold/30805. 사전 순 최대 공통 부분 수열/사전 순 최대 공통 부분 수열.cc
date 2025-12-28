#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<pair<int, int>> A, B;
vector<int> ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back({a, i});
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        B.push_back({a, i});
    }

    sort(A.begin(), A.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            return true;
        }
        else if (a.first == b.first) {
            return a.second < b.second;
        }
        return false;
    });

    sort(B.begin(), B.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            return true;
        }
        else if (a.first == b.first) {
            return a.second < b.second;
        }
        return false;
    });

//    for (int i = 0; i < A.size(); i++) {
//        cout << "(" << A[i].first << " " << A[i].second << ") ";
//    }
//    cout << '\n';
//    for (int i = 0; i < B.size(); i++) {
//        cout << "(" << B[i].first << " " << B[i].second << ") ";
//    }

    int idxA = 0, idxB = 0;
    int limitA = -1, limitB = -1;

    while (1) {

        if (idxA >= A.size() || idxB >= B.size()) {
            break;
        }

        if (A[idxA].first == B[idxB].first) {
            if (A[idxA].second > limitA && B[idxB].second > limitB) {
                ans.push_back(A[idxA].first);
                limitA = A[idxA].second;
                limitB = B[idxB].second;
                idxA++;
                idxB++;
            }
            else if (A[idxA].second > limitA) {
                idxB++;
            }
            else if (B[idxB].second > limitB) {
                idxA++;
            }
            else {
                idxA++;
                idxB++;
            }
        }
        else if (A[idxA].first > B[idxB].first) {
            idxA++;
        }
        else {
            idxB++;
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}