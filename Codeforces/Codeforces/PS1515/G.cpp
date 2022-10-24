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
typedef pair<int,LL> edge;

int N,M,Q;
bool V[H];
bool U[H];
set<edge> adj[H];
set<edge> rev[H];
vector<set<int>> comp;
int par[H];
LL ret[H];
LL ans[H];
int cv; bool fin; int nc=0;

LL gcd(LL a, LL b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

stack<int> ord;
// Detect all connected pieces
void dfs1(int v) {
    U[v] = false;
    for (edge u : adj[v]) {
        if (U[u.f]) dfs1(u.f);
    }
    ord.p(v);
}

void dfs2(int v) {
    U[v] = false;
    comp[nc].ins(v);
    for (edge u : rev[v]) {
        if (U[u.f]) dfs2(u.f);
    }
}

void tr(int v) {
    if (V[v]) {
        //cout << "penis" << v << endl;
        V[v]=false;
        for (edge e : adj[v]) {
            if (V[e.f]) {
                ret[e.f]=ret[v]+e.s;
                tr(e.f);
            }
        }
    }
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; i++) {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        LL ww = (LL)w;
        adj[u].ins(mp(v,ww));
        rev[v].ins(mp(u,ww));
    }
    for (int i = 1; i <= N; i++) {
        V[i]=false;
        U[i]=true;
        ans[i]=0;
    }
    for (int i = 1; i <= N; i++) {
        if (U[i]) {
            dfs1(i);
        }
        //V[i] = false; // oh no
    }
    //cout << "HI\n";
    for (int i = 1; i <= N; i++) U[i]=true;
    // the constant factor is stupid
    //cout << ord.size() << endl;
    while (ord.size()) {
        int v = ord.t(); ord.pop();
        //cout << v << endl;
        if (U[v]) { comp.pb(set<int>()); dfs2(v); nc++;
        }
    }
    //cout << "A" << endl;
    for (set<int> st : comp) {
        set<int>::iterator it = st.begin();
        for (int i : st) {
            V[i] = true; par[i]=*it;
            //cout << i << " ";
        }
        //cout << endl;
        ret[*it]=0;
        tr(*it);
        //cout << ret[*it] << endl;
        for (int i : st) V[i] = false;
    }
    for (int u = 1; u <= N; u++) {
        for (edge e : adj[u]) {
            if (par[e.f]==par[u]) {
                LL d = abs(ret[u]+e.s-ret[e.f]);
                ans[par[u]]=gcd(ans[par[u]],d);
            }
        }
    }
    scanf("%d",&Q);
    while (Q--) {
        int v,s,t;
        LL S,T;
        scanf("%d%d%d",&v,&s,&t);
        S=(LL)s;T=(LL)t;
        LL z = ans[par[v]];
        z = gcd(z,t);
        if (s%z==0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
*/
