#include <bits/stdc++.h>
using namespace std;

int H, W, grid[3005][3005], orb[3005][3005], ing[3005][3005];

char c;
long long ans;

int main() {
    scanf("%d %d", &H, &W);
    c = getchar();

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            c = getchar();
            if (c == 'J') {
                grid[i][j] = 1;
            } else if (c == 'O') {
                grid[i][j] = 2;
                orb[i][j]++;
            } else {
                grid[i][j] = 3;
                ing[i][j]++;
            }
        }
        c = getchar();
    }
    
    // cumSum array for orb
    for (int i=1; i<=H; i++) {
        for (int j=W; j>=1; j--) {
            orb[i][j] += orb[i][j+1];
        }
    }

    // cumSum array for ing
    for (int j=1; j<=W; j++) {
        for (int i=H; i>=1; i--) {
            ing[i][j] += ing[i+1][j];
        }
    }

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            if (grid[i][j] == 1) {
                ans += orb[i][j] * ing[i][j];
            }
        }
    }

    printf("%lld\n", ans);
}
