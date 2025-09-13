#include <iostream>
#include <algorithm>
using namespace std;
class Skyline {
public:
    int Xr;
    int Xl;
    int H;
};

int main() {
    int n;
    cout << "Enter no. of buildings: ";
    cin >> n;

    Skyline p[n];
    cout << "Enter each building (l r h):\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i].Xl >> p[i].Xr >> p[i].H;
    }

    int arr[2 * n];
    for (int i = 0; i < n; i++) arr[i] = p[i].Xl;
    for (int i = 0; i < n; i++) arr[n + i] = p[i].Xr;

    sort(arr, arr + 2 * n);

    cout << "\nSkyline points:\n";
    int prevHeight = 0;

    for (int i = 0; i < 2 * n; i++) {
        int x = arr[i];
        int maxH = 0;

        for (int j = 0; j < n; j++) {
            if (p[j].Xl <= x && x < p[j].Xr) {
                if (p[j].H > maxH) maxH = p[j].H;
            }
        }
        
        if (maxH != prevHeight) {
            cout << x << " " << maxH << "\n";
            prevHeight = maxH;
        }
    }
    return 0;
}

