#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dl, sl;
int answer;

void dfs(ll cSplit, ll cParent, ll restDist, ll cLeaf) {
    if (answer < cLeaf) {
        answer = cLeaf;
    }
    
    if (cParent == 0 || restDist == 0) {
        return;
    }
    
    // * 3 으로 분배
    if (cSplit * 3 <= sl){
        ll t = min(cParent, restDist);
        dfs(cSplit * 3, t * 3, restDist - t, cLeaf + t * 2);
    }
    
    // * 2 로 분배
    if (cSplit * 2 <= sl) {
        ll t = min(cParent, restDist);
        dfs(cSplit * 2, t * 2, restDist - t, cLeaf + t * 1);
    }
}

int solution(int dist_limit, int split_limit) {

    dl = dist_limit;
    sl = split_limit;
    
    dfs(1, 1, dist_limit, 1);
    
    return answer;
}