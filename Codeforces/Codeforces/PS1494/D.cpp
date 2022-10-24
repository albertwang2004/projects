/*#include <bits/stdc++.h>
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

#define H 5*H2

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;
int A[H][H];
int ans[2*H];
int lp = 0; int rp = 0;
vector<int> comp[2*H];
vector<pii> ret;
vector<int> B[2*H][H];

// dsu

struct DSU {
    int P[H];
    int S[H];

    void start() {
        for (int i = 0; i < H; i++) {
            P[i]=i; S[i]=1;
        }
    }

    int SZ(int x) {return S[pp(x)];}

    int pp(int x) {
        if (P[x]==x) return x;
        return (P[x] = pp(P[x]));
    }

    bool un(int a, int b) {
        a = pp(a);
        b = pp(b);
        if (a == b) return 0;
        if (S[a] > S[b]) swap(a,b);
        S[b] += S[a];
        P[a] = b;
        return 1;
    }
} D[2*H];

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);
        for (int i = 0; i < 2*H; i++) {
            ans[i] = -69;
            D[i].start();
            for (int j = 0; j < H; j++) B[i][j] = vector<int>();
        }
        for (int i = 1; i <= N; i++) {
            comp[rp].pb(i);
            for (int j = 1; j <= N; j++) {
                scanf("%d",A[i]+j);
            }
            ans[i]=A[i][i];
        }
        rp++;
        while (lp < rp) {
            //cout << lp << " " << rp << endl;
            //for (int i : comp[lp]) cout << i << " ";
            //cout << endl;
            int mx = 0;
            for (int i : comp[lp]) {
                mx=max(mx,A[i][comp[lp][0]]);
            }
            ans[N+lp+1]=mx;
            for (int i : comp[lp]) {
                for (int j : comp[lp]) {
                    if (A[i][j]!=mx) {
                        D[lp].un(i,j);
                    }
                }
            }
            for (int i : comp[lp]) {
                B[lp][D[lp].pp(i)].pb(i);
            }
            for (int i : comp[lp]) {
                if (B[lp][i].size()==1) {
                    ans[i]=A[i][i];
                    ret.pb(mp(lp+N+1,i));
                } else if (B[lp][i].size()) {
                    for (int j : B[lp][i]) {
                        comp[rp].pb(j);
                    }
                    ret.pb(mp(lp+N+1,rp+N+1));
                    rp++;
                }
            }
            lp++;
        }
    }
    cout << lp+N << endl;
    for (int i = 1; i <= lp+N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl << N+1 << endl;
    for (pii x : ret) {
        cout << x.s << " " << x.f << endl;
    }
}
*/
