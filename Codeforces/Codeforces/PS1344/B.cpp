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

#define H H3
#define HH 10

#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 1e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
#define R0(x,n) for(int x = n-1; x >= 0; --x)
#define F1(x,n) for(int x = 1; x <= n; ++x)


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

int cases,N,M,K,Q; ll X,Y;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << 0 << endl;
    exit(0);
}

// dsu

struct DSU {
    vector<int> P;
    vector<int> S;
    int NC;

    void start(int N) {
        for (int i = 0; i <= N; i++) {
            P.pb(i); S.pb(1);
        }
        NC = N;
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
        NC--;
        S[b] += S[a];
        P[a] = b;
        return 1;
    }
};


int gr[H][H];
void read() {
    N=rd(); M=rd();
    int sz = 0;
    F0(i,N) {
        string S; cin >> S;
        F0(j,M) {
            gr[i][j]=(S[j]=='#');
            if (gr[i][j]) gr[i][j]=++sz;
        }
    }

    int badrows = 0;
    // check rows
    F0(i,N) {
        int segf = -1;
        int segs = 999999;
        F0(j,M) {
            if (gr[i][j]) {
                if (segf==-1) {
                    segf = j;
                    segs = j+1;
                } else if (segs == j) {
                    segs++;
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        if (segf==-1) {
            badrows++;
        }
    }

    int badcolumns = 0;
    // check columns
    F0(j,M) {
        int segf = -1;
        int segs = 999999;
        F0(i,N) {
            if (gr[i][j]) {
                if (segf==-1) {
                    segf = i;
                    segs = i+1;
                } else if (segs == i) {
                    segs++;
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        if (segf==-1) {
            badcolumns++;
        }
    }
    if (sz) {
        if (badrows*badcolumns==0) {
            if (badrows+badcolumns>0) {
            cout << -1 << endl;
            return;
            }
        }
    }

    // dsu
    DSU st; st.start(sz);
    F0(i,N) {
        F0(j,M) {
            if (gr[i][j]) {
                if (i-1>=0) {
                    if (gr[i-1][j]) {
                        st.un(gr[i][j],gr[i-1][j]);
                    }
                }
                if (i+1<N) {
                    if (gr[i+1][j]) {
                        st.un(gr[i][j],gr[i+1][j]);
                    }
                }
                if (j-1>=0) {
                    if (gr[i][j-1]) {
                        st.un(gr[i][j],gr[i][j-1]);
                    }
                }
                if (j+1<M) {
                    if (gr[i][j+1]) {
                        st.un(gr[i][j],gr[i][j+1]);
                    }
                }
            }
        }
    }

    cout << st.NC << endl;
}

int main() {
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool trials = 0;

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {

        read();


    }

}
*/
