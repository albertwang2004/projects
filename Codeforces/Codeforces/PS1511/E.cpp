/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 300010
#define MOD 998244353

using namespace std;
typedef long long int LL;

int N,M;
LL pow2[H];
LL inv2[H];
LL i2=499122176; // -2^-1 mod MOD
vector<string> pogger;

LL inv(LL a){
    LL x = MOD - 2;
    if (a==1)
        return 1;
    LL r = 1;
    while (x) {
        if (x & 1)
            r = (r * a) % MOD;
        x >>= 1;
        a = (a * a) % MOD;
    }
    return r;
}
vector<LL> spree;

char B[H];

int main() {
    pow2[0]=1;
    inv2[0]=1;
    for (int i = 1; i < H; i++) {
        pow2[i] = (pow2[i-1]*2)%MOD;
        inv2[i] = (inv2[i-1]*i2)%MOD;
    }
    spree.pb(0);
    spree.pb(0);
    for (int i = 2; i < H; i++) {
        spree.pb((spree[i-1]+inv2[i])%MOD);
    }
    scanf("%d %d",&N,&M);
    LL P2 = 1;
    LL RET = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s",B);
        pogger.pb(B);
    }
    // rows
    int c = 0;
    for (int i = 0; i < N; i++) {
    int spr = 0;
        for (int j = 0; j < M; j++) {
            if (pogger[i][j]=='o') {
                spr++; c++;
                RET=(RET+spree[spr])%MOD;
            } else {
                spr=0;
            }
        }
    }
    P2 = pow2[c];
    for (int j = 0; j < M; j++) {
        int spr = 0;
        for (int i = 0; i < N; i++) {
            if (pogger[i][j]=='o') {
                spr++;
                RET=(RET+spree[spr])%MOD;
            } else {
                spr=0;
            }
        }
    }
    cout << (RET*P2)%MOD;
}
*/
