/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define H 200100
#define INF 5000000000000000

using namespace std;
typedef long long int LL;
typedef pair<LL,pair<int,int>> edge;

int N,M,Q;
vector<edge> G;

bool comp(edge a, edge b) {
    return a.f < b.f;
}

LL na;
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
}
A,B;

// A including unassigned
// B excluding unassigned

set<int> unt;
set<int> adj[H];
bool V[H];

void dfs(int v) {
    //cout << "dfs(" << v << ")\n";
    unt.erase(v);
    V[v]=1;
    int u=0;
    while (u <= N) {
        set<int>::iterator it = unt.lower_bound(u);
        if (it == unt.end()) break;
        u = *it;
        //cout << u << endl;
        if (adj[v].find(u)==adj[v].end()) {
            --na;
            if (A.un(u,v)) //cout << " Connected " << u << " " << v <<endl;
            // A now has all components of unassigned edges
            dfs(u);
        }
        ++u;
    }
}

int main() {
    scanf("%d%d",&N,&M);
    LL vw = 0;
    A.start(); B.start();
    for (int i = 0; i < M; i++) {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        LL ww = (LL)w;
        G.pb(mp(ww,mp(u,v)));
        adj[u].ins(v);
        adj[v].ins(u);
        vw^=ww;
    }
    for (int i = 1; i <= N; i++) {
        unt.ins(i); V[i]=0;
    }
    na = (1LL*N*(N-1)/2)-(1LL*M);
    //cout << "A\n";
    sort(G.begin(),G.end(),comp);
    for (int i = 1; i <= N; i++) {
        //cout << "DFS " << i << " ?\n";
        if (!V[i]) dfs(i);
    }
    //cout << "B\n";
    LL tot = 0;
    for (int i = 0; i < M; i++) {
        // cout << G[i].f << " " << G[i].s.f << " " << G[i].s.s << endl;
        if (A.un(G[i].s.f,G[i].s.s)) {
            // case 1 - ass edge connects two unassigned pieces
            tot+=G[i].f;
            B.un(G[i].s.f,G[i].s.s);
        } else if (B.un(G[i].s.f,G[i].s.s)) vw=min(G[i].f,vw);
            // case 2 - ass edge already covered by unassigned piece
            // but it may be the case that this edge beats vw
    }
    if (na==0) cout << tot+vw << endl;
    else cout << tot << endl;
}
*/
