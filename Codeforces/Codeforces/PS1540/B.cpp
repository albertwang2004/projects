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

#define H 201

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M;
vector<int> adj[H];
LL dist[H][H];


void bfs(int v) {
    bool visit[H];
    for (int i = 0; i < H; i++) visit[i] = false;
    queue<pii> next;
    next.p(mp(v,0));
    while (next.size()) {
        pii u = next.fr();
        next.pop();
        visit[u.f] = true;
        dist[v][u.f]=u.s;
        for (int i : adj[u.f]) {
            if (!visit[i]) next.p(mp(i,u.s+1));
        }
    }
}

LL modexp(LL x, LL y){
    LL ret = 1;
    while (y) {
        if (y % 2 == 1) ret = (ret * x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return ret%MOD;
}

LL PROB[H][H];

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {

        scanf("%d",&N);

        for (int i = 1; i < N; i++) {
            int x,y; scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for (int i = 1; i <= N; i++) {
            bfs(i);
        }
        for (int i = 0; i < H; i++) {
            PROB[i][0]=0;
            PROB[0][i]=1;
        }
        for (int i = 1; i < H; i++) {
            for (int j = 1; j < H; j++) {
                PROB[i][j]=((PROB[i-1][j]+PROB[i][j-1])*modexp(2,MOD-2))%MOD;
            }
        }
        //for (int i = 0; i <= H; i++) {
        //    for (int j = 0; j <= H; j++) {
        //        PROB[i][j]=((PROB[i-1][j]+PROB[i][j-1])*modexp(2,MOD-2))%MOD;
        //    }
        //}
        LL ANS = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                for (int k = 1; k <= N; k++) {
                    LL ss = dist[k][j] + dist[i][j] + dist[i][k];
                    LL toi = (ss-2*dist[k][j])/2;
                    LL toj = (ss-2*dist[k][i])/2;
                    //cout << i << " " << j << " " << k << " " << toi << " " << toj << endl;
                    ANS = (ANS+PROB[toi][toj])%MOD;
                    //cout << toj << " " <<(toi+toj) << endl;
                }
            }
        }
        cout << (ANS*modexp(N,MOD-2))%MOD << endl;
    }
}*/
