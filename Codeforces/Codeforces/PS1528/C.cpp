/*
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 300100
#define INF 5000000000000000

using namespace std;
typedef pair<int,int> pii;

int T,N;
int P[H];
int V[H];
pii KT[H];
stack<int> DFS;
stack<pii> prevv;
vector<int> adj1[H];
vector<int> adj2[H];

bool comp(int a, int b) {
    return KT[a].f < KT[b].f;
}

set<int,decltype(comp)*> ans(comp);

int solve() {
    DFS = stack<int>();
    DFS.p(1);
    int i;
    for (i=0; DFS.size(); i++) {
        int v = DFS.top();
        //cout << "DFS 2 " << v << endl;
        if (V[v]==0) KT[v].f=i;
        if (V[v]==adj2[v].size()) {
            KT[v].s=i;
            DFS.pop();
            V[v]=0;
        } else {
            DFS.p(adj2[v][V[v]++]);
        }
    }
    DFS.p(1);
    ans=set<int,decltype(comp)*>(comp);
    int ret = 0;
    while (DFS.size()) {
        int v = DFS.top();
        //cout << "Reading " << v << endl;
        while (prevv.size()) {
            pii k = prevv.top();
            if (v==k.f) {
                ans.insert(k.s);
            } else break;
            prevv.pop();
        }
        if (V[v]==0) {
            ans.insert(v);
            set<int,decltype(comp)*>::iterator it = ans.find(v);
            if (it != ans.begin()) {
                it--;
                if (KT[v].s <= KT[*it].s) {
                    prevv.p(mp(P[v],*it));
                    ans.erase(it);
                }
            }
        }
        //cout << "ANS ";
        //for (int i : ans) {
        //    cout << i << " ";
        //}
        //cout << endl;
        ret=max(ret,(int)ans.size());
        if (V[v]==adj1[v].size()) {
            ans.erase(v);
            DFS.pop();
        } else {
            DFS.p(adj1[v][V[v]++]);
        }
    }
    return ret;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        DFS=stack<int>();
        prevv=stack<pii>();
        ans.clear();
        for (int i = 1; i <= N; i++) {
            adj1[i]=vector<int>();
            adj2[i]=vector<int>();
            V[i]=0;
            KT[i]=mp(-1,-1);
        }
        for (int i = 2; i <= N; i++) {
            int x; scanf("%d",&x);
            adj1[x].pb(i);
            P[i]=x;
            //adj1[x].pb(i);
        }
        for (int i = 2; i <= N; i++) {
            int x; scanf("%d",&x);
            adj2[x].pb(i);
            //adj2[x].pb(i);
        }
        cout << solve() << endl;
    }
}
*/
