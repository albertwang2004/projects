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
#define HH 43

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 1e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
#define FR0(x,L,R) for(int x = L; x < R; ++x)
#define R0(x,n) for(int x = n-1; x >= 0; --x)
#define F1(x,n) for(int x = 1; x <= n; ++x)
#define FR1(x,L,R) for(int x = L; x <= R; ++x)
#define R1(x,n) for(int x = n; x >= 1; --x)


using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
struct LL {

    static const ll m = MOD; // set to LNF for nomod
    long long int val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(ll x, ll md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator!=(const LL& b) { return val!=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const ll& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const ll& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const ll& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const ll& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const ll& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const ll& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const ll& y){
        ll z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(ll y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const ll& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const ll& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<pll,ll> tri;
typedef pair<LL,pLL> TRI;
using namespace std;

int cases,N,M,Q,K; ll X,Y;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic(ll out) {
    cout << out << endl;
    exit(0);
}

int A[H][H];
struct FFA {
    const static int n=5*H5;
    map<pii,int> cap;
    vector<int> adj[n];

    void addEdge(int u, int v, int c) {
        cap[{u,v}]=c;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pii> q;
        q.p({s, INF});
        while (!q.empty()) {
            int cur = q.fr().f;
            int flow = q.fr().s;
            q.pop();
            for (int next : adj[cur]) {
                if ((parent[next] == -1) && (cap[mp(cur,next)]>0)) {
                    parent[next] = cur;
                    int new_flow = min(flow, cap[mp(cur,next)]);
                    if (next == t) return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while (new_flow = bfs(s, t, parent)) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                cap[mp(prev,cur)] -= new_flow;
                cap[mp(cur,prev)] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};

void read() {
    N=rd(); M=rd();
    int src; int snk;
    int k=0; F0(i,N) {
        string S; cin>>S;
        F0(j,M) {
            char l = S.at(j);
            A[i][j]=(l=='#')?0:++k;
        }
    }
    int a = rd();
    int b = rd();
    int c = rd();
    int d = rd();
    src=A[a][b];
    snk=A[c][d];
    k+=2;
    src+=k;
    FFA calc;
    F0(i,N) {
        F0(j,M) {
            if (A[i][j]) {
                calc.addEdge(A[i][j],A[i][j]+k,1);
                if (i>0) {
                    if (A[i-1][j]) {
                        calc.addEdge(A[i][j]+k,A[i-1][j],1);
                    }
                }
                if (i<N-1) {
                    if (A[i+1][j]) {
                        calc.addEdge(A[i][j]+k,A[i+1][j],1);
                    }
                }
                if (j>0) {
                    if (A[i][j-1]) {
                        calc.addEdge(A[i][j]+k,A[i][j-1],1);
                    }
                }
                if (j<M-1) {
                    if (A[i][j+1]) {
                        calc.addEdge(A[i][j]+k,A[i][j+1],1);
                    }
                }
            }
        }
    }
    cout << calc.maxflow(src,snk) << endl;
}

int main() {
    bool trials = 0;
    bool interactive = 0;

    if (!interactive) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {
        read();
    }

}
*/
