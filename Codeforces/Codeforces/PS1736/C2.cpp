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

template<typename T> vector<T> readVector(int sz) {
    vector<T> ret;
    for (int i = 0; i < sz; i++) {
        T x; cin >> x;
        ret.pb(x);
    }
    return ret;
}

vector<int> A;

struct SegTree {

    ll F(ll a, ll b) {
        return min(a,b);
    }

	int sz;
	vector<ll> ST;

	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++)
            ST.pb(LNF); // i may have to change this value
    }

	void lift(int idx) {
	    ST[idx] = F(ST[2*idx],ST[2*idx+1]);
    }

	void update(int idx, ll x) {
		idx += sz;
		ST[idx] = x;
		idx >>= 1;
		while (idx) {
            lift(idx); idx >>= 1;
		}
	}

	ll query(int lp, int rp) {
		ll a = LNF; // i may have to change this value
		ll b = LNF; // i may have to change this value
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F(a,ST[lp++]);
			if (rp&1) b = F(ST[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F(a,b);
	}

} ST;

vector<int> DP;
vector<ll> RP(200020,0);
vector<ll> SP;


void solve() {
    int N; cin >> N;
    A.pb(0);
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        A.pb(x);
    }

    DP.pb(0);
    SP.pb(0);
    for (int i = 1; i <= N; i++) {
        DP.pb(min(DP[i-1]+1,A[i]));
        SP.pb(SP[i-1]+DP[i]);
    }

    ST.start(N+20);
    for (int i = 1; i <= N; i++) {
        ST.update(i,A[i]-i);
    }
    ST.update(N+1,-69696969);


    for (int i = N; i >= 1; i--) {
        int L = i+1;
        int R = N+1;
        while (L < R) {
            int M = (L+R)/2;
            if (ST.query(L,M) < A[i]-i) {
                R = M;
            } else {
                L = M+1;
            }
        }
        RP[i] = RP[L] + ((ll)(L-1-i))*(L-i)/2 + (ll)(L-i)*(ll)A[i];
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int p, x; cin >> p >> x;
        int nDP = min(DP[p-1]+1,x);
        int L = p+1;
        int R = N+1;
        while (L < R) {
            int M = (L+R)/2;
            if (ST.query(L,M)<nDP-p) {
                R = M;
            } else {
                L = M+1;
            }
        }
        cout << SP[p-1] + (ll)RP[L] + (ll)nDP*(L-p) + ((ll)(L-p-1))*(L-p)/2 << endl;
    }
}

int main() {
    if (0) { // set for cases
        int T; cin >> T;
        while (T--) solve();
    } else solve();
}
*/
