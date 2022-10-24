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

#define H 5*H5
#define HH 10

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 1e16

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

int T,N,M,K,Q,X,Y;

int rd() {int x;cin>>x; return x;}
void fl() {cout.flush();}

LL ret = 1;
LL DP[H];
LL S[H];
int P[H];
vector<pair<pii,int>> ps;

void panic() {
    cout << 0 << endl;
    exit(0);
}

int segtree[4*H];

int range(int a, int b) {
    a += H;
    b += H;
    int ans = 0;
    while (a <= b) {
        if (a % 2 == 1) ans +=segtree[a++];
        if (b % 2 == 0) ans +=segtree[b--];
        a /= 2;
        b /= 2;
    }
    return ans;
}

void update(int k, int x) {
    k += H;
    segtree[k] += x;
    for (k /= 2; k >= 1; k /= 2) segtree[k] =
        segtree[2 * k]+segtree[2 * k + 1];
}

LL pfx(int l, int r) {
    return S[r]-S[l]+DP[l];
}

LL solve() {
    //cout << "--------" << endl;
    S[0] = 1;
    DP[0] = 1;
    int pr = 0;
    for (int i = 1; i <= N+1; i++) {
        if (range(0,i)>0) DP[i] = 0;
        else DP[i] = pfx(pr,i-1);
        S[i]=S[i-1]+DP[i];
        pr = max(pr,P[i]);
        //cout << range(0,i) << " " << i << " "
        //<< pr << " " << DP[i] << " " << S[i] << endl;
    }
    return DP[N+1];
}

void read() {
    N=rd();K=rd();M=rd();
    for (int i = 0; i < M; i++) {
        int l = rd(); int r = rd(); int x = rd();
        ps.pb(mp(mp(l,r),x));
    }
    for (int ii = 0, j = 1; ii < K; ii++, j<<=1) {
        for (int i = 0; i < 4*H; i++) {segtree[i] = 0;}
        for (int i = 1; i <= N+1; i++) P[i]=0;
        for (int i = 0; i < M; i++) {
            int l = ps[i].f.f; int r = ps[i].f.s; int x = ps[i].s;
            if (x&j) {update(l,1);update(r+1,-1);}
            else P[r]=max(P[r],l);
        }
        P[N+1] = N+1;
        ret *= solve();
    }
        cout << ret << endl;
}

int main() {
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        read();

        //for (int i = 0, j = 1; i < K; i++, j<<=1) {
        //    cout << "Read in forced 0s for " << i << " " << j << endl;
        //    for (pii x : P[i]) {
        //        cout << x.f << " " << x.s << endl;
        //    }
        //    cout << "Forcing ";
        //    for (int x = 1; x <= N; x++) cout << force[x][i]; cout<< endl;
        //}


    }

}
*/
