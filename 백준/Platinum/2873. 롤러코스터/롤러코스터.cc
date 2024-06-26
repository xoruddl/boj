#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;

    int v[R][C];
    int min = 1001;
    pair <int, int> blank;
    string move;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> v[i][j];
            if (min > v[i][j] && (i + j) % 2 == 1){
                min = v[i][j];
                blank.first = i;
                blank.second = j;
            }
        }
    }

    // 행이 홀수개일때 그냥 다 합쳐서 가면 된다.
    if (R % 2 == 1) {
        while (R) {
            if (R % 2 == 1) {
                for (int i = 1; i <= C - 1; i++) {
                    cout << "R";
                }
                if (R != 1) {
                    cout << "D";
                }
            }
            else {
                for (int i = 1; i <= C - 1; i++) {
                    cout << "L";
                }
                cout << "D";
            }
            R--;
        }
    }
    //행이 짝수이더라도 열이 홀수일때도 다 합쳐서 간다.
    else if (C % 2 == 1){
        while (C){
            if (C % 2 == 1){
                for (int i = 1; i <= R - 1; i++){
                    cout << "D";
                }
                if (C != 1){
                    cout << "R";
                }
            }
            else{
                for (int i = 1; i <= R - 1; i++){
                    cout << "U";
                }
                cout << "R";
            }
            C--;
        }
    }
    // 행과 열 둘다 짝수일때
    else if (R % 2 == 0 && C % 2 == 0){
        int r, c;
        if (blank.first % 2 == 1)
            r = blank.first - 1; //blank가 있는 윗줄까지
        else
            r = blank.first; //blank가 있는 줄까지

        //blank가 있는 줄 전까지
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    move += 'R';
                else
                    move += 'L';
            }
            move += 'D';
        }


        //blank 전
        c = blank.second;

        for (int i = 0; i < c; i++) {
            if (i % 2 == 0)
                move += "DR";
            else
                move += "UR";
        }

        //blank 후
        for (int i = c; i < C - 1; i++) {
            if (i % 2 == 0)
                move += "RD";
            else
                move += "RU";
        }

        for (int i = r + 2; i < R; i++) {
            move += 'D';
            for (int j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    move += 'L';
                else
                    move += 'R';
            }
        }

        cout << move << "\n";
    }
    return 0;
}