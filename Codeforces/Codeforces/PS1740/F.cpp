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
//int N, M;
//ll P, Q;
//int encode(pii x) {
//    return M*x.f+x.s;
//}

//pii decode(int x) {
//    return mp(x/M,x%M);
//}

vector<int> cnt(2001);
vector<int> inv(2001);
vector<int> ps;


// DP[L][N][T] as defined, T ranging in 1...floor(N/L)
vector<LL> DP[2001][2001];


// SDP[L][N] is the sum across t of DP[L][N][t]
LL SDP[2001][4001];

void solve() {
    // compute transpose
    int A; cin >> A;
    for (int i = 0; i < A; i++) {
        int x; cin >> x;
        ++cnt[x-1];
    }
    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());
    for (int i = 1; i <= cnt[0];i++) {
        inv[i] = 0;
        while (cnt[inv[i]] >= i) ++inv[i];
    }
    ps.pb(0);
    for (int i = 0; i < A; i++) {
        ps.pb(ps[i]+inv[i+1]);
    }

    // make DP array
    for (int L = 0; L <= 2000; L++) {
        for (int N = 0; N <= 2000; N++) {
            if (L == 0) {
                DP[L][N] = vector<LL>(A+1,0);
            } else {
                DP[L][N] = vector<LL>(N/L+1,0);
            }
        }
    }

    for (int L = 0; L <= 2000; L++) {
        for (int X = 0; X <= 4000; X++) {
            SDP[L][X] = 0;
        }
    }

    // do DP
    SDP[0][0] = 1;
    for (int T = A; T >= 1; T--) {
        for (int L = 1; L <= A; L++) {
            for (int N = T*L; N <= ps[L]; N++) {
                if (ps[L] >= N) {
                    DP[L][N][T] += SDP[L-1][N-T];
                    SDP[L][N] += SDP[L-1][N-T];
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i <= A; i++) {
        for (LL x : DP[i][A]) ans += x;
    }
    cout << ans << endl;
}

int main() {
    if (0) { // set for cases
        int T; cin >> T;
        while (T--) solve();
    } else solve();
}
*/
