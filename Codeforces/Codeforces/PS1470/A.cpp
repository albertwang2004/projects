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

#define H H5
#define HH 10

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 1e18

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
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<pll,ll> tri;

ll T,N,M,K,Q,X,Y;

ll rd() {ll x; scanf("%lld",&x); return x;}
void fl() {cout.flush();}

int seg[H];
int lazy[H];
bool mark[H];


struct Cheese {

    ll F(ll a, ll b) {
        return a+b;
    }

    int n;

    Cheese(int n){start(n);}

    void start(int n) {
        this->n = n;
        for (int i = 0; i < 4*n+5; i++) { seg[i]=0;lazy[i]=0;mark[i]=0; }
    }

    void push(int v, int tl, int tr) {
        if (mark[v]) {
            lazy[2 * v] = lazy[v];
            lazy[2 * v + 1] = lazy[v];
            mark[2 * v] = true;
            mark[2 * v + 1] = true;
            int tm = (tl + tr) / 2;
            seg[2 * v] = lazy[2 * v] * (tm - tl + 1);
            seg[2 * v + 1] = lazy[2 * v + 1] * (tr - tm);
            mark[v] = false;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int rep) {
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] = rep;
            mark[v] = true;
            seg[v] = rep * (tr - tl + 1);
        }
        else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), rep);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, rep);
            seg[v] = seg[2 * v + 1] + seg[2 * v];
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        push(v, tl, tr);
        if (l <= tl && r >= tr) return seg[v];
        int tm = (tl + tr) / 2;
        return (query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int l, int r, int rep) { update(1, 0, n-1, l, r, rep); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }


};


// fft

ll gcd(ll a, ll b) {
   return b?gcd(b, a % b):a;
}

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

vector<int> exp(vector<int> const& a, int b) {
    vector<int> atemp = a;
    vector<int> ret = vector<int>(); ret.pb(1);
    while (b) {
        if (b&1) ret = multiply(atemp,ret);
        b >>= 1; atemp = multiply(atemp,atemp);
    }
    return ret;
}

vector<vector<int>> adj;

stack<int> color2;

int color[H];


struct DSU {

    int n;
    vector<int> P;
    vector<int> S;

    void start(int n) {
        for (int i = 0; i <= n+5; i++) {
            P.pb(i); S.pb(1);
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
};

int temp[H];

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;


    while (T--) {

        N = rd(); K = rd();

        int sqr = 1;
        while (sqr*sqr<N) sqr++;

        for (int i = 0; i <= N; i++) temp[i] = K;
        for (int i = 0; i < sqr; i++) {
            cout << "? 1" << endl; fl(); rd();
        }


    if (N>18) {
        int ft = H;
        int best = 0;
        for (int i = 1; i <= N; i+=sqr) {
            cout << "? " << i << endl; fl(); int l = rd();
            temp[i] = l;
            if (abs(l-K)>abs(best)) {
                ft=i;
                best=l-K;
            }
        }


            int L = ft-sqr+N;
            int R = ft+sqr+N;
            if (best<0) {L+=sqr; R+=sqr;}
            if (best>0) {L-=sqr; R-=sqr;}
            vector<pii> intttt;
            while (L<=R) {
                intttt.pb(mp(L,R));
                int M = (L+R)/2;
                int disp = ((M+N-1)%N+1);
                cout << "? " << disp << endl; fl(); int l = rd();
                if (l<K) {
                    L = M+1;
                } else if (l>K) {
                    R = M;
                } else {
                    cout << "? " << (disp+N-2)%N+1 << endl; fl(); int asdf = rd();
                    assert(asdf<K);
                    cout << "! " << disp << endl; return 0;
                }
            }
            cout << intttt[0].f << "|" << intttt[0].s << endl;
            for (pii x : intttt) cout << x.f<<":"<<x.s<<"|";
            int kill[5]; // cause crash
            fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();fl();
            for (int i = 0; i < 9999999; i++) kill[i] /= 0;fl();
            return -69;

    } else {
        cout << "? 1" << endl; fl(); int t1 = rd();
        cout << "? 2" << endl; fl(); int t2 = rd();
        for (int i = 3; i <= N+100; i++) {
            cout << "? " << ((i-1)%N+1) << endl; fl(); int t3 = rd();
            if ((t1 < t2) && (t2 < t3)) {
                cout << "! " << ((i+N-2)%N+1) << endl; return 0;
            }
            t1=t2; t2=t3;
        }
    }
    }


    return 0;

}
*/
