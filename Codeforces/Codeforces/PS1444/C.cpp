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

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;

int C[5*H5];

vector<int> V[5*H5];
vector<int> adj[5*H5];

set<int> VP[5*H5];
set<int> ADJ[5*H5];
set<pii> cheq;

int color[5*H5];
bool bip[5*H5];

int COLOR[5*H5];

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
} D;

bool color2(int v, int c, int k) {
    if (color[v]) {
        if (color[v]!=c) return false;
        else return true;
    } else {
        color[v]=c;
        bool ret = 1;
        for (int x : adj[v]) {
            if (C[x]==k)
                ret = ret && color2(x,3-c);
        }
        return ret;
    }
}

bool COLOR2(int v, int c, pii k) {
    if (COLOR[v]) {
        if (COLOR[v]!=c) return false;
        else return true;
    } else {
        COLOR[v]=c;
        bool ret = 1;
        for (int x : ADJ[v]) {
            if ((C[x]==k.f)||(C[x]==k.s))
                ret = ret && COLOR2(x,3-c);
        }
        return ret;
    }
}

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {

        scanf("%d%d%d",&N,&M,&K);
        D.start();

        for (int i = 1; i <= N; i++) {
            scanf("%d",C+i);
            V[C[i]].pb(i);
            color[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int x,y; scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for (int i = 1; i <= K; i++) {
            bip[i] = 1;
            int v1 = 0;
            int v2 = 0;
            for (int v : V[i]) {
                if (color[v]) {}
                else bip &&= color2(v,1);
            }
            if (bip[i]) {
                for (int v : V[i]) {
                    if (color[v]==1) {
                        if (v1) D.un(v1,v);
                        v1=v;
                    } else {
                        if (v2) D.un(v2,v);
                        v2=v;
                    }
                }
            }
        }

        for (int u = 1; u <= N; u++) {
            VP[C[u]].ins(D.pp(u));
            for (int v : adj[u]) {
                if (C[u]!=C[v]) {
                    cheq.ins(mp(min(C[u],C[v]),max(C[u],C[v])));
                }
                ADJ[D.pp(u)].ins(D.pp(v));
                ADJ[D.pp(v)].ins(D.pp(u));
            }
        }

        for (pii x : cheq) {
            int c1 = x.f;
            int c2 = x.s;
        }
    }
}
*/
