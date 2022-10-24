/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 200100
#define MOD 998244353

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N,K;
int A[H];
int P[H];
LL modexp(LL x, LL y){
    LL ret = 1;
    while (y) {
        if (y % 2 == 1) ret = (ret * x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return ret%MOD;
}
int main() {
    scanf("%d%d",&N,&K);
    LL ret = 1;
    LL T = N+K;
    for (int i = 0; i < N; i++) {
        scanf("%Ld",A+i);
        P[A[i]]=i;
    }
    P[N]=-999999999;
    for (LL i = 0; i < N-1; i++) {
        if (P[A[i+1]+1]<P[A[i]+1]) T--;
    }
    for (LL i = 1; i <= N; i++) {
        ret=(ret*(T-i))%MOD;
        ret=(ret*modexp(i,MOD-2))%MOD;
    }
    cout << ret << endl;
}
*/
