#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double triArea = 0.0;
    triArea = abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) * 0.5;

    double Cx = (x1 + x2 + x3) / 3.0; // 무게중심 x좌표
    double Cy = (y1 + y2 + y3) / 3.0; // 무게중심 y좌표

    double resX = 2 * PI * triArea * Cy;
    double resY = 2 * PI * triArea * Cx;

    cout << fixed;
    cout.precision(10);
    cout << resX << " " << resY << '\n';
    return 0;
}