/*#include <bits/stdc++.h>

#define f first
#define s second

#define p push
#define t top
#define mp make_pair
#define pb push_back

#define MOD 998244353
#define LNF 1e18

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

#define tc(T) template <class T>
#define tcc(S, T) template <class S, class T>
tc(T) vector<T> readVector(int sz) {
    vector<T> ret;
    for (int i = 0; i < sz; i++) {
        T x; cin >> x;
        ret.pb(x);
    }
    return ret;
}
tcc(S,T) bool updmin(S &a, T b) {
    S B = (S)b;
    if (B < a) {a = B; return 1;}
    return 0;
}
tcc(S,T) bool updmax(S &a, T b) {
    S B = (S)b;
    if (B > a) {a = B; return 1;}
    return 0;
}
tcc(S,T) S min(S a, T b) {
    S c = a; updmin(c, b); return c;
}
tcc(S,T) S max(S a, T b) {
    S c = a; updmax(c, b); return c;
}



void solve() {
    int N; cin >> N;
    vector<int> A = readVector<int>(N);
    vector<int> I(N);
    vector<bool> M(N,0);
    for (int i = 0; i < N; i++) {
        I[A[i]] = i;
    }
    ll ans = 1;
    int L = I[0];
    int R = I[0];
    M[0] = 1;
    int X = 1;
    int currSeek = 1;
    while (currSeek < N) {
        int p = I[currSeek];
        if (p < L) {
            ans += max(0, min(N - 1, L + 2*X - 1) - R + 1);
            M[A[L-1]] = 1;
            while (M[X]) ++X;
        //cout << L << " " << R << " " << ans << endl;
            --L;
        } else if (p > R) {
            ans += max(0, L - max(0, R - 2*X + 1) + 1);
            M[A[R+1]] = 1;
            while (M[X]) ++X;
        //cout << L << " " << R << " " << ans << endl;
            ++R;
        }
        if (p >= L && p <= R) ++currSeek;
    }

    cout << ans << endl;
}

int main() {
    if (1) { // set for cases
        int T; cin >> T;
        while (T--) solve();
    } else solve();
}
*/
