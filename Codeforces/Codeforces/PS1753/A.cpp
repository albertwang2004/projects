/*#include <bits/stdc++.h>

#define f first
#define s second

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

void solve() {
    int N;
    cin >> N;
    vector<int> A = readVector<int>(N);
    int s = 0;
    for (int i : A) s+=i;
    if (s%2 == 1) {
        cout << -1 << endl;
        return;
    }
    vector<pii> ret;
    int prev = 0;
    int f1 = -1;
    int f2 = -1;
    for (int i = 0; i < N; i++) {
        if (f1 == -1 && A[i] != 0) {
            f1 = i;
        } else if (f1 != -1 && f2 == -1 && A[i] != 0) {
            f2 = i;
        }
        if (f2 != -1) {

        }
        while (prev < f1) {
            ret.pb({prev,prev});
            ++prev;
        }
        if (A[f1]==A[f2]) {
            if (f2 - f1 == 1) {
                ret.pb(mp(f1,f2));
            } else {
                ret.pb(mp(f1,f2-2));
                ret.pb(mp(f2-1,f2));
            }
        } else {
            ret.pb(mp(f1,f1));
            if (f2 - f1 != 1) ret.pb(mp(f1+1,f2-1));
            ret.pb(mp(f2,f2));
        }
        prev = i+1;
    }
    if (prev != N) ret.pb(mp(prev,N-1));
    cout << ret.size() << endl;
    for (auto x : ret) {
        cout << x.f+1 << " " << x.s+1 << endl;
    }
}

int main() {
    if (1) { // set for cases
        int T; cin >> T;
        while (T--) solve();
    } else solve();
}*/
