/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define MOD 1000000007
#define H 1000010
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
int N;
LL F[H];
LL IF[H];
int main() {
    F[0]=1;
    IF[0]=1;
    for (int i = 1; i < H; i++) {
        F[i]=(F[i-1]*i)%MOD;
        IF[i]=modexp(F[i],MOD-2);
    }
    scanf("%d",&N);
    LL ret = 0;
    for (int i = N; i >= 0; i-=2) {
        if (i>N/2) continue;
        int x1 = N-i+1;
        int x2 = N-i-1;
        int y1 = i;
        int y2 = i-2;
        LL B1 = (((F[x1]*IF[y1])%MOD)*IF[x1-y1])%MOD;
        LL B2;
        if (y2<0) B2 = 0;
        else B2 = (((F[x2]*IF[y2])%MOD)*IF[x2-y2])%MOD;
        LL D = B1-B2;
        if (D<0) D+=MOD;
        ret=(ret+(((2*(F[N-i])%MOD))*D)%MOD)%MOD;
        if (ret<0) ret+=MOD;
    }
    cout << ret << endl;
}
*/
