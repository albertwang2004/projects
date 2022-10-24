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

#define H 2*H5

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;

int D[H];
int C[H];
int tot[H];

unordered_set<int> adj[H];
stack<pii> comp;
vector<int> F;
int lp = 0;
int rp = 0;
vector<pii> edges;
bool V[H];
pii temp;


void sever(pii e, int sz) {
    int u = e.f; int v = e.s;
    //cout << "Cutting " << u << " " << v << " size " << F[sz] << endl;
    adj[u].erase(v);
    adj[v].erase(u);
    comp.p(mp(u,--sz));
    comp.p(mp(v,--sz));
}

int dfs(int v, int c) {
    V[v]=1;
    D[v]=c++;
    int ret = 1;
    for (int u : adj[v]) {
        //if (used[mp(u,v)]) continue;
        if (V[u]) continue;
        ret += dfs(u,c);
        edges.pb(mp(u,v));
        ++rp;
    }
    C[v]=ret;
    V[v]=0;
    return ret;
}

bool locate(int v, int sz) {
    dfs(v,1);
    for (lp; lp<rp; lp++) {
        pii e = edges[lp];
        int u = e.f; int v = e.s;
        //cout << u << " " << v << " " << D[u] << " " << D[v] << " " << C[u] << " " << C[v] << endl;
        if (D[u]>D[v]) swap(u,v);
        if (F[sz]==C[v]) {
            temp.f=v;
            temp.s=u;
            lp=rp;
            return 1;
        } else if (F[sz-1]==C[v]) {
            temp.f=u;
            temp.s=v;
            lp=rp;
            return 1;
        }
    }
    return 0;
}

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);
       // N=196418;
        for (int i = 1; i <= N; i++) { D[i] = 0; V[i] = 0; }

        int c = 1;
        F.pb(1);
        F.pb(1);
        while (N>F[c]) {
            F.pb(F[c]+F[c++-1]);
        }
        if (N!=F[c]) { cout << "NO" << endl; return 0; }

        for (int i = 1; i < N; i++) {
            int x,y; scanf("%d%d",&x,&y);
            //x=1; y=i+1;
            adj[x].ins(y);
            adj[y].ins(x);
            //used[mp(x,y)]=0;
            //used[mp(y,x)]=0;
        }

        comp.p(mp(1,c));
        while (comp.size()) {
            int v = comp.t().f;
            int sz = comp.t().s; comp.pop();
            //cout << v << " " << sz << endl;
            //cout << "Looking at " << v << " " << sz << endl;
            if (sz<=1) continue;
            bool fl = locate(v,sz-1);
            if (fl) sever(temp,sz);
            else {
                cout << "NO" << endl; return 0;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}
*/
