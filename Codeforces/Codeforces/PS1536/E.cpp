/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define UH 2000000000
#define LH -2000000000
#define MOD 1000000007
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
LL modexp(LL x, LL y){
    LL ret = 1;
    while (y) {
        if (y % 2 == 1) ret = (ret * x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return ret%MOD;
}

int T,N,M;
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&N,&M);
        int c = 0;
        for (int i = 0; i < N; i++) {
            char buf[2004];
            scanf("%s",buf);
            for (int i = 0; i < M; i++) {
                if (buf[i]=='#') c++;
            }
        }
        if (c==0) cout << 1 << endl;
        else if (c==M*N) cout << (modexp(2,c)+(MOD-1))%MOD << endl;
        else {
            cout << (modexp(2,c))%MOD << endl;
        }
    }
}*/
