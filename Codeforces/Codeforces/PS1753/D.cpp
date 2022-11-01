/*#include <bits/stdc++.h>

#define f first
#define s second

#define p push
#define t top
#define mp make_pair
#define pb push_back

#define MOD 998244353

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct LL {

    static const long long int m = MOD; // set to LNF for nomod
    long long int val;

    LL(long long int v) {val=reduce(v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(long long int l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(long long int x, long long int md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const long long int& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const long long int& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const long long int& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const long long int& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const long long int& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const long long int& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const long long int& y){
        long long int z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(long long int y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const long long int& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const long long int& b) { return (*this=*this/LL(b)); }

    static vector<LL> F; // factorials
    static vector<LL> I; // inverse factorials
    static void loadFactorials(int n) {
        while (F.size() <= n) {
            int k = F.size();
            F.pb(F.back()*k);
            I.pb(I.back()/k);
        }
    }

    static LL binom(long long int top, long long int bot) {
        assert(top > 0);
        assert(bot > 0);
        if (top < bot) return 0;
        loadFactorials(top);
        return F[top]*I[bot]*I[top-bot];
    }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
vector<LL> LL::F = vector<LL>(1,1);
vector<LL> LL::I = vector<LL>(1,1);

template<typename T> vector<T> readVector(int sz) {
    vector<T> ret;
    for (int i = 0; i < sz; i++) {
        T x; cin >> x;
        ret.pb(x);
    }
    return ret;
}
int N, M;
ll P, Q;
int encode(pii x) {
    return M*x.f+x.s;
}

pii decode(int x) {
    return mp(x/M,x%M);
}

vector<vector<pll>> adj(300010);

priority_queue<pll,vector<pll>,greater<pll>> PQ;

vector<ll> D(300010,0);

void solve() {
    cin >> N >> M;
    cin >> P >> Q;
    char arr[N][M];
    for (int i = 0; i < N*M; i++) {
        D[i]=1ll<<60;
    }
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        for (int j = 0; j < M; j++) {
            arr[i][j]=S.at(j);
            if (arr[i][j]=='.') {
                D[encode({i,j})]=0;
                PQ.p(mp(0,encode({i,j})));
            }
        }
    }


    // R
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M-1; j++) {
            int from = encode({i,j});
            if (arr[i][j] != '#') {
                if (arr[i][j+1] == 'L') adj[from].pb({encode({i,j+2}),Q});
                if (arr[i][j+1] == 'U') adj[from].pb({encode({i+1,j+1}),P});
                if (arr[i][j+1] == 'D') adj[from].pb({encode({i-1,j+1}),P});
            }
        }
    }
    // L
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            int from = encode({i,j});
            if (arr[i][j] != '#') {
                if (arr[i][j-1] == 'R') adj[from].pb({encode({i,j-2}),Q});
                if (arr[i][j-1] == 'U') adj[from].pb({encode({i+1,j-1}),P});
                if (arr[i][j-1] == 'D') adj[from].pb({encode({i-1,j-1}),P});
            }
        }
    }
    // D
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M; j++) {
            int from = encode({i,j});
            if (arr[i][j] != '#') {
                if (arr[i+1][j] == 'U') adj[from].pb({encode({i+2,j}),Q});
                if (arr[i+1][j] == 'L') adj[from].pb({encode({i+1,j+1}),P});
                if (arr[i+1][j] == 'R') adj[from].pb({encode({i+1,j-1}),P});
            }
        }
    }
    // U
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int from = encode({i,j});
            if (arr[i][j] != '#') {
                if (arr[i-1][j] == 'D') adj[from].pb({encode({i-2,j}),Q});
                if (arr[i-1][j] == 'L') adj[from].pb({encode({i-1,j+1}),P});
                if (arr[i-1][j] == 'R') adj[from].pb({encode({i-1,j-1}),P});
            }
        }
    }

    while (PQ.size()) {
        ll d = PQ.t().f; ll u = PQ.t().s; PQ.pop();
        if (d!=D[u]) continue;
        // some weird two-level dijkstra
        for (pii e : adj[u]) {
            if (D[e.f]>D[u]+e.s) {
                PQ.p(mp(D[e.f]=D[u]+e.s,e.f));
            }
        }
    }
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (D[encode({i,j})] > 99999) cout << "x ";
            else cout << D[encode({i,j})] << " ";
        }
        cout << endl;
    }*/
    ll ans = 1ll<<60;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M-1; j++) {
            if (arr[i][j] != '#' && arr[i][j+1] != '#')
                ans = min(ans,D[encode({i,j})]+D[encode({i,j+1})]);
        }
    }
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] != '#' && arr[i+1][j] != '#')
                ans = min(ans,D[encode({i,j})]+D[encode({i+1,j})]);
        }
    }
    if (ans > 1ll<<59) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    if (0) { // set for cases
        int T; cin >> T;
        while (T--) solve();
    } else solve();
}
*/
