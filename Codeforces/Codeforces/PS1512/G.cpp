/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 10000000

using namespace std;
typedef long long int LL;

int T,C;
int D[H+1];
int ret[10*H+1];
int main() {
    for (int i = 1; i <= H; i++) {
        D[i] = 0;
        ret[i] = -1;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = i; j <= H; j+=i) {
            D[j]+=i;
        }
    }
    for (int i = 1; i <= H; i++) {
        ret[D[i]] = min((ret[D[i]]==-1)?999999999:ret[D[i]],i);
    }
    cin >> T;
    while (T--) {
        cin >> C;
        cout << ret[C] << endl;
    }
    return 0;
}*/
