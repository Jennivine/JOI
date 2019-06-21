#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
pair <int, int> pictures[100005];
int frames[100005];


int main() {
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) {
        int size, value;
        scanf("%d %d", &size, &value);
        pictures[i] = make_pair(value, size);
    }
    sort(pictures, pictures+N, greater<pair<int, int> >());

    for (int i=0; i<M; i++) {
        scanf("%d", frames+i);
    }
    sort(frames, frames+M, greater<int>());

	int f=0, p=0;
    while (f < M && p < N){
        if (pictures[p].second <= frames[f]) {
            p++; f++; ans++;
        } else {
            p++;
        }
    }

	printf("%d\n", ans);
}
