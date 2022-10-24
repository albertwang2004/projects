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

#define H 4*H5
#define HH 43

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


using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
struct LL {

    static const ll m = mod; // set to LNF for nomod
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

void panic() {
    cout << -1 << endl;
    exit(0);
}


// dsu*

struct DSUt {
    vector<int> P;
    vector<int> S;
    vector<int> D;
    vector<int> L;
    vector<vector<pii>> adj;

    DSUt(int N) {start(N);}

    void start(int N) {
        adj.clear();
        for (int i = 0; i <= N; i++) {
            P.pb(i);
            S.pb(1);
            D.pb(1);
            L.pb(0);
            adj.pb(vector<pii>());
        }
    }

    int SZ(int x) {return S[pp(x)];}

    int dt(int a, int b) {
        if (pp(a)!=pp(b)) return -1;
        return L[a]^L[b]; // this only works for XOR. dunno how to LCA efficiently for other query types
    }

    int pp(int x) {
        if (P[x]==x) return x;
        return (P[x] = pp(P[x]));
    }

    void upd(int k, int l) {
        L[k]^=l;
        for (pii u : adj[k]) {
            if (D[u.f]<D[k]) {
                upd(u.f,l);
            }
        }
    }

    bool un(int a, int b, int d) {
        int A = pp(a);
        int B = pp(b);
        if (A == B) {
            if (dt(a,b)==d) return 1;
            else return 0;
        }
        if (S[A] > S[B]) {swap(A,B);}
        d^=L[a]^L[b];
        S[B] += S[A];
        P[A] = B;
        D[B] = max(D[B],D[A]+1);
        adj[A].pb(mp(B,d));
        adj[B].pb(mp(A,d));
        upd(A,d);
        return 1;
    }
};

unordered_map<int,int> hsh;

void read() {
    Q=rd();
    DSUt calc = DSUt(H);
    int last = 0;
    int v = 0;
    while (Q--) {
            //last=0;
        int t=rd();
        if (t==1) {
            int L = ((int)(rd()))^last;
            int R = ((int)(rd()))^last;
            int X = ((int)(rd()))^last;
            if (L>R) swap(L,R);
            R++;
            if (hsh.find(L)==hsh.end()) {
                v++;
                hsh[L]=v;
            }
            if (hsh.find(R)==hsh.end()) {
                v++;
                hsh[R]=v;
            }
            calc.un(hsh[L],hsh[R],X);
        } else {
            int L = ((int)(rd()))^last;
            int R = ((int)(rd()))^last;
            if (L>R) swap(L,R);
            R++;
            if (hsh.find(L)==hsh.end()) {
                v++;
                hsh[L]=v;
            }
            if (hsh.find(R)==hsh.end()) {
                v++;
                hsh[R]=v;
            }
            last = calc.dt(hsh[L],hsh[R]);
            cout << last << endl;
            if(last==-1)last=1;
        }
    }
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
