/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010
#define MOD 1000000007

using namespace std;
typedef long long int LL;

int T;
int N,K;

LL modexp(LL x, LL y){
    LL ret = 1;
    while (y) {
        if (y % 2 == 1) ret = (ret * x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return ret%MOD;
}

LL F[H];
LL IF[H];

LL inv(LL x) {
    return modexp(x,MOD-2);
}

LL mult(LL x, LL y) {
    LL ret = (x*y)%MOD;
    if (ret<MOD) ret+=MOD;
    return ret;
}

LL binom(LL x, LL y) {
    if (y<0 || y>x) return 0;
    if (y==0) return 1;
    return mult(mult(F[x],IF[x-y]),IF[y]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);

    F[0]=1;
    IF[0]=1;
    for (int i = 1; i < H; i++) {
        F[i]=(F[i-1]*i)%MOD;
        IF[i]=inv(F[i]);
    }

    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&N,&K);
        LL ret = 0;
        for (int i = 0; i <= N; i++) {
            if ((K-1)*(i-1)>N) break;
            ret=(ret+
                mult(
                    inv(binom(N,i)),
                    binom(
                        N-(K-1)*(i-1),
                        i
                    )
                )
            )%MOD;
        }
        cout << ret << endl;
    }
}*/
