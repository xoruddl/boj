#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll N, M, K;
vector<ll> tree;
vector<ll> arr;

// 세그먼트 트리 초기화 함수
// node: 현재 노드의 인덱스
// start: 현재 노드가 담당하는 구간의 시작 인덱스
// end: 현재 노드가 담당하는 구간의 끝 인덱스
ll init(int node, int start, int end) {
    if (start == end) {
        // 리프 노드에 도달하면 배열의 값을 저장
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// 구간 합 질의 함수
// node: 현재 노드의 인덱스
// start, end: 현재 노드가 담당하는 구간
// left, right: 구하고자 하는 합의 구간
ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

// 값 업데이트 함수
// node: 현재 노드의 인덱스
// start, end: 현재 노드가 담당하는 구간
// index: 업데이트할 배열의 인덱스
// diff: 변경된 값
void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) {
        return;
    }
    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;
    tree.resize(N * 4);

    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        arr.push_back(a);
    }
    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ll tmp = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, 0, N - 1, b - 1, tmp);
        }
        else {
            cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}