/*
this is fucking gross lmao
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

#define H 3*H3

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;

vector<int> adj[H];
int deg[H] = {0};
int numodd = 0;
vector<int> odds;

vector<int> G[H];
int DEG[H];
bool U[H][H];
int NUMODD = 0;

void COPY(int v) {
    for (int i = 1; i <= N; i++) ADJ[i].clear();
    for (int i = 1; i <= N; i++) DEG[i]=deg[i];
    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            U[i][j] = 0;
            if ((j!=v) && (i!=v)) ADJ[i].pb(j);
        }
    }
    NUMODD = numodd;
}

vector<int> ret;

void check(int v) {
    while (ADJ[v].size()) {
        int u = *(ADJ[v].begin());
        if (U[v][u]) continue;
        U[v][u] = 1;
        U[u][v] = 1;
        check(u);
    }
    ret.pb(v);
}

bool euler(int v) {
    COPY(v);
    for (int u : adj[v]) {
        if (DEG[u]%2) {
            ADJ[u].pb(v);
            ADJ[v].pb(u);
        }
    }
    check(v);
}

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            U[i][j]=1;
        }
    }
    while (T--) {
        scanf("%d%d",&N,&M);
        D.start();
        for (int i = 1; i <= N; i++) deg[i] = 0;

        // check for connectivity and degrees
        for (int i = 0; i < M; i++) {
            int x,y; scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
            deg[x]++;
            deg[y]++;
            D.un(x,y);
        }
        for (int i = 1; i <= N; i++) {
            numodd += deg[i]%2;
            if (deg[i]%2) odds.pb(i);
        }

        // iterate over stars
        bool flag = 1;
        for (int i = 1; i <= N; i++) {
            if euler(i) { flag = 0; break; } // good!
        }

        // also bad!
        if (flag) cout << 0 << endl;
    }
}
*/
