/*
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front

#define T1 10
#define T2 100
#define T3 1000
#define T4 10000
#define T5 100000
#define T6 1000000

#define H1 11
#define H2 105
#define H3 1010
#define H4 10010
#define H5 100010
#define H6 1000010

#define H 201

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,Q;

vector<LL> C,B;
vector<LL> shift;
vector<LL> shiftL;

LL DP[H2][H4]; // after c_i how many sequences have sum whatever

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {

        scanf("%d",&N);

        C.pb(-69420); // just make things convenient
        for (int i = 0; i < N; i++) {
            LL x; scanf("%lld",&x);
            C.pb(x);
        }
        shift.pb(0);
        shiftL.pb(0);
        for (int i = 1; i < N; i++) {
            LL x; scanf("%lld",&x);
            B.pb(x);
            shift.pb(shift[i-1]+x);
            shiftL.pb(shiftL[i-1]+shift[i]);
        }
        scanf("%d",&Q);

        for (int j = 1; j < H4; j++) DP[0][j]=0;
        DP[0][0]=1;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < H4; j++) {
                DP[i][j]=0;
                for (int k = 0; k <= C[i]; k++) {
                    if (j-k>=0) {
                        DP[i][j]=(DP[i][j]+DP[i-1][j-k])%MOD;
                    }
                }
            }
        }

        //for (int i = 1; i <= N; i++) {
        //    cout << i << ": ";
        //    for (int j = 0; j < 10; j++) {
        //        cout << DP[i][j] << " ";
        //    }
        //    cout << endl;
        //}

        LL X;
        while ( Q-- ) {
            scanf("%lld",&X);
            LL allowedsum = X*N+shiftL[N-1];
            for (int i = allowedsum; i < H4; i++) {
                ret = (ret+DP[N][i])%MOD;
            }
            cout << ret << endl;
        }
    }
}
*/
