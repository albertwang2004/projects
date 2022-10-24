/*
// hooray for math
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 4500
#define MOD 998244353
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

LL N,M;
LL binom[H][H];
int main() {
    scanf("%lld%lld",&N,&M);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i*j==0) binom[i][j]=(j==0);
            else binom[i][j]=(binom[i-1][j-1]+binom[i-1][j])%MOD;
        }
    }
    LL ret = 0;
    for (int r = 1; r < N; r++) {
        LL dp = 0;
        for (int c = M-1; c > 0; c--) {
            dp = (dp+(binom[(N-r-1)+c][N-r-1] // down and left
                      *binom[(N-r)+(M-c-1)][N-r] // down and right
                      )%MOD)%MOD;
            ret = (ret+(dp // pick second half
                        *((binom[(M-c)+(r-1)][r-1] // up and right
                           *binom[r+(c-1)][r])%MOD))%MOD)%MOD;
        }
    }
    for (int r = 1; r < M; r++) {
        LL dp = 0;
        LL prev = 0;
        for (int c = N-1; c > 0; c--) {
            dp = (dp+(binom[(M-r-1)+c][M-r-1] // down and left
                      *binom[(M-r)+(N-c-1)][M-r] // down and right
                      )%MOD)%MOD;
            ret = (ret+(prev // pick second half
                        *((binom[(N-c)+(r-1)][r-1] // up and right
                           *binom[r+(c-1)][r])%MOD))%MOD)%MOD;
            prev = dp; // delay second half
        }
    }
    ret=(ret*2)%MOD;
    cout << ret << endl;
}*/
