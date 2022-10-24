/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ins insert
#define p push
#define fr front
#define H 400100
#define INF 5000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> frac;

int N;

LL gcd(LL a, LL b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

frac simp(frac x) {
    return mp(x.f/gcd(x.f,x.s),x.s/gcd(x.f,x.s));
}

frac slope(frac x, frac y) {
    return simp(mp(y.f*x.s,x.f*y.s));
}


map<frac,int> G1; // this is so illegal but i literally do not care
vector<pii> adj[H];
int V[H];
vector<pii> ret;

// dsu

int P[H];
int S[H];
int SE[H];

int pp(int x) {
	if (P[x]==x) return x;
    return (P[x] = pp(P[x]));
}

void un(int a, int b) {
	a = pp(a);
	b = pp(b);
	if (a == b) {
        SE[a]++;
        return;
	}
	if (S[a] > S[b]) swap(a,b);
	S[b] += S[a];
	SE[b] += SE[a] + 1;
	P[a] = b;
}


int dfs(int v) { // return the available edge
    V[v]=1;
    int re = 0;
    for (pii k : adj[v]) {
        int id = k.s;
        bool flag = false;
        if (V[k.f]==1) continue;
        if (V[k.f]==0) {
            int R = dfs(k.f);
            if (R) {
                cout << R << " " << id << endl; // path
                flag = true;
            }
        }
        if (flag) continue;
        if (re) cout << re << " " << id << endl; // cherry
        re = re?0:id;
    }
    V[v]=2;
    return re;
}


int main() {

    for (int i = 0; i < H; i++) {
        adj[i] = vector<pii>();
        V[i] = -1;
        P[i]=i; S[i]=1;
    }
    scanf("%d",&N);
    int cs = 1;

    for (int i = 1; i <= N; i++) {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        frac xs = simp(mp(a,b));
        frac ys = simp(mp(c,d));
        xs.f+=xs.s;
        if (G1.find(slope(xs,ys))==G1.end()) {
            G1[slope(xs,ys)]=cs; cs++;
        }
        int v1 = G1[slope(xs,ys)];
        xs.f-=xs.s;
        ys.f+=ys.s;
        if (G1.find(slope(xs,ys))==G1.end()) {
            G1[slope(xs,ys)]=cs; cs++;
        }
        int v2 = G1[slope(xs,ys)];
        adj[v1].pb(mp(v2,i));
        adj[v2].pb(mp(v1,i));
        un(v1,v2);
    }

    int RETS = 0;
    for (int i = 1; i < cs; i++) {
        if (V[pp(i)]==-1) {
            V[pp(i)]=0;
            RETS+=SE[pp(i)]/2;
        }
    }

    for (int i = 1; i < cs; i++) V[i]=0;

    //for (int i = 1; i < cs; i++) {
    //    cout << "Vertex " << i << endl;
    //    for (pii j : adj[i]) {
    //        cout << j.f << " ID = " << j.s << endl;
    //    }
    //}

    cout << RETS << endl;
    for (int i = 1; i < cs; i++) {
        if (!V[i]) dfs(i);
    }
}

*/
