/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 400100
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int M,N;
vector<vector<bool>> grid; // each subvec is a column
vector<vector<int>> G; // this is probably easier
int req[H];

set<int> adj[H];
set<int> rev[H];
set<int> revret[H];

int hp(pii x) {
    return N*x.f+x.s;
}

pii hi(int x) {
    return mp(x/N,x%N);
}

void edge(int x, int y) {
    adj[x].ins(y);
    rev[y].ins(x);
}


int nc=0;
bool U[H];
int par[H];
vector<set<int>> comp;
stack<int> ord;
// Detect all connected pieces
void dfs1(int v) {
    U[v] = false;
    for (int u : adj[v]) {
        if (U[u]) dfs1(u);
    }
    ord.p(v);
}

void dfs2(int v) {
    U[v] = false;
    comp[nc].ins(v);
    for (int u : rev[v]) {
        if (U[u]) dfs2(u);
    }
}

set<int> REQ;
set<pii> ans;

void del(int node) {
    REQ.erase(node);
    for (int v : adj[node]) {
        rev[v].erase(node);
    }
    for (int v : rev[node]) {
        adj[v].erase(node);
    }
    adj[node]=set<int>();
    rev[node]=set<int>();
}

int main() {

    // init

    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; i++) {
        grid.pb(vector<bool>());
        G.pb(vector<int>());
        adj[i]=set<int>();
        rev[i]=set<int>();
        revret[i]=set<int>();
    }

    // make digraph

    for (int i = 0; i < N; i++) {
        char buf[M]; scanf("%s",buf);
        for (int j = 0; j < M; j++) {
            grid[j].pb(buf[j]=='#');
            if (buf[j]=='#') {
                if (G[j].size()) {
                    if (i==1+G[j][G[j].size()-1]) {
                        edge(hp(mp(j,i)),hp(mp(j,i-1)));
                    }
                    edge(hp(mp(j,G[j][G[j].size()-1])),hp(mp(j,i)));
                }
                G[j].pb(i);
            }
        }
    }
    for (int j = 1; j < M; j++) {
        for (int i : G[j]) {
            vector<int>::iterator it = lower_bound(G[j-1].begin(),G[j-1].end(),i);
            if (it != G[j-1].end()) {
                edge(hp(mp(j,i)),hp(mp(j-1,*it)));
            }
        }
        for (int i : G[j-1]) {
            vector<int>::iterator it = lower_bound(G[j].begin(),G[j].end(),i);
            if (it != G[j].end()) {
                edge(hp(mp(j-1,i)),hp(mp(j,*it)));
            }
        }
    }

    // find required sand

    for (int j = 0; j < M; j++) {
        scanf("%d",req+j);
        if (req[j]!=0) {
            REQ.ins(hp(mp(j,G[j][G[j].size()-req[j]])));
        }
    }



    // make SCC

    for (int i = 0; i < M*N; i++) if (grid[hi(i).f][hi(i).s]) U[i]=true;
    for (int i = 0; i < M*N; i++) if (U[i]) dfs1(i);
    for (int i = 0; i < M*N; i++) {if (grid[hi(i).f][hi(i).s]) U[i]=true;
    par[i]=INF;}
    while (ord.size()) {
        int v = ord.t(); ord.pop();
        if (U[v]) {
            comp.pb(set<int>()); dfs2(v); nc++;
        }
    }
    for (set<int> S : comp) {
        for (int i : S) {
            par[i]=*(S.begin());
        }
    }


    for (int i = 0; i < M*N; i++) {
        for (int x : adj[i]) {
            if (par[x]!=par[i]) revret[par[x]].ins(par[i]);
        }
    }

    int c = 0;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (grid[j][i]) {
                if (revret[par[hp(mp(j,i))]].size()==0)
                    ans.ins(hi(par[hp(mp(j,i))]));
            }
        }
    }

    cout << ans.size() << endl;
}

*/
