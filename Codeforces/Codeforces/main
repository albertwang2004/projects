#include <bits/stdc++.h>
#include <bitset>
#include <cstdint>
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

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 2e18

#define tc(T) template <class T>
#define tcc(S, T) template <class S, class T>
#define tccc(S, T, U) template <class S, class T, class U>

using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
typedef string str;
typedef long double dbl;
struct LL {

    static ll m; // set to LNF for nomod
    ll val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static void setMod(ll m) { assert(m); LL::m = m; }

    static ll reduce(ll x, ll md = m) {
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
ll LL::m = MOD;

typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<dbl,dbl> pdd;
using namespace std;
// sacrilege

#define bts(a,x,b) ((a<x)&&(x<b))
#define btw(a,x,b) ((a<=x)&&(x<=b))

#define F0(x,n) for(ll x = 0; x < n; ++x)
#define Fr(x,L,R) for(ll x = L; x < R; ++x)
#define R0(x,n) for(ll x = n-1; x >= 0; --x)
#define F1(x,n) for(ll x = 1; x <= n; ++x)
#define FR(x,L,R) for(ll x = L; x <= R; ++x)
#define R1(x,n) for(ll x = n; x >= 1; --x)
#define RR(x,L,R) for(ll x = R; x >= L; --x)
#define Rr(x,L,R) for(ll x = R-1; x >= L; --x)
#define FE(x,ls) for(auto x : ls)
#define FER(x,ls) for(auto &x : ls)

#define srt(x) sort(x.begin(),x.end())
#define srtc(x,c) sort(x.begin(),x.end(),c)
#define rev(x) reverse(x.begin(),x.end())

#define UB upper_bound
#define LB lower_bound
#define ub(x,v) upper_bound(x.begin(),x.end(),v)
#define lb(x,v) lower_bound(x.begin(),x.end(),v)
#define bs(x,v) binary_search(x.begin(),x.end(),v)
#define dst(x,y) (ll)distance(x,y)
#define nlt(x,v) (ll)dst(x.begin(),lb(x,v))
#define nle(x,v) (ll)dst(x.begin(),ub(x,v))

ll cases,N,M,Q,K,X,Y;

//ifstream fin("read.in");
//ofstream fout("exercise.out");
ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
tc(T) void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
tc(T) void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
    if (E == -18852946) E = sz-1;
    adj.clear();
    F0(i,sz+1) adj.pb(vector<T>());
    F0(i,E) {
        T a = rd(); T b = rd();
        adj[a].pb(b); adj[b].pb(a);
    }
}
tcc(S,T) void rdv(vector<S>& vec, T* sz, bool flag = 1) {
    if (flag) *sz = rd();
    F0(i,*sz) vec.pb(rd());
}

void fl() {cout.flush();}
void ds(int v) { cout << v << " "; }
void ds(ll v) { cout << v << " "; }
void ds(LL v) { cout << v << " "; }
void ds(dbl v) { cout << v << " "; }
void ds(char v) { cout << v << " "; }
void ds(str v) { cout << v << " "; }
void ds(char* v) { cout << v << " "; }
tc(T) void ds(T* v, int t) {
    auto x = v;
    F0(i,t) ds(*(x++)); cout << endl;
}
tcc(S,T) void ds(pair<S,T> v) {cout << "( "; ds(v.f); cout << ", "; ds(v.s); cout << ") ";}
tc(T) void ds(vector<T> v) { FE(x,v) ds(x); cout << endl; }
tc(T) void panic(T out) { ds(out); exit(0); }

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

ll mulmod(ll a, ll b, ll m) {
    ll ret = 0;
    //cout << "mulmod " << a << " " << b << " " << m << endl;
    while (b > 0) {
        if (b % 2 == 1) ret += a;
        ret = ret%m;
        b /= 2;
        a += a;
        a = a%m;
    //cout << " " << a << " " << b << " " << m << endl;
    }
    //cout << ret << endl;
    return ret;
}

ll power(ll a, ll n, ll m) {
    ll cur = a;
    ll result = 1ll;
        //cout << "power " << result << " " << cur << " " << n << endl;
    while (n > 0) {
        if (n % 2 == 1) result = mulmod(result,cur,m);
        cur = mulmod(cur,cur,m);
        n /= 2;
        //cout << "powering " << result << " " << cur << " " << n << endl;
    }
    //cout << result << endl;
    return result;
}

bool witness(ll n, ll s, ll d, ll a) {
    //cout << n << " " << s << " " << d << " " << a << endl;
    ll x = power(a, d, n);
    //cout << x << endl;
    if (x==1 || x==n-1) return true;
    F0(i,s-1) {
        x = power(x,x,n);
        //cout << i << " " << x << endl;
        if (x == n-1) return true;
    }
    return false;
}

bool isPrime(ll n) {
    if (((!(n % 2 == 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3ll)
        return true;

    ll d = n / 2;
    ll s = 1;
    while (d % 2 == 0) {
        d /= 2;
        ++s;
    }
    //cout << n << " = 2^" << s << " * " << d << " + 1" << endl;

    if (n < 1373653ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 3ll);
    if (n < 9080191ll)
        return witness(n, s, d, 31ll) && witness(n, s, d, 73ll);
    if (n < 4759123141ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 7ll) && witness(n, s, d, 61ll);
    if (n < 1122004669633ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 13ll) && witness(n, s, d, 23ll) && witness(n, s, d, 1662803ll);
    if (n < 2152302898747ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 3ll) && witness(n, s, d, 5ll) && witness(n, s, d, 7ll) && witness(n, s, d, 11ll);
    if (n < 3474749660383ll)
        return witness(n, s, d, 2ll) && witness(n, s, d, 3ll) && witness(n, s, d, 5ll) && witness(n, s, d, 7ll) && witness(n, s, d, 11ll) && witness(n, s, d, 13ll);
    return witness(n, s, d, 2ll) && witness(n, s, d, 3ll) && witness(n, s, d, 5ll) && witness(n, s, d, 7ll) && witness(n, s, d, 11ll) && witness(n, s, d, 13ll) && witness(n, s, d, 17ll)
     && witness(n, s, d, 19ll) && witness(n, s, d, 23ll) && witness(n, s, d, 29ll) && witness(n, s, d, 31ll) && witness(n, s, d, 37ll);
}

ll gcd(ll a, ll b) {
    return b?gcd(b, a%b):a;
}

ll PollardRho(ll n, ll attempt = 7) {
    if (attempt == 0) return n;
    if (n==1) return n;
    if (n % 2 == 0) return 2;
    ll x = (mr()%(n-2))+2;
    ll y = x;
    ll c = (mr()%(n-1))+1;
    ll d = 1;
    int failure = 40000; // adjust to desired degree of accuracy
    while (d==1) {
        if (failure == 0) return n;
        failure--;
        x = (power(x, 2, n) + c + n)%n;
        y = (power(y, 2, n) + c + n)%n;
        y = (power(y, 2, n) + c + n)%n;
        d = gcd(abs(x-y), n);
        if (d==n) return PollardRho(n,attempt-1);
    }
    return d;
}

map<ll,int> pf;

void factorize(ll n) {
    if (n==1) return;
    else if (isPrime(n)) pf[n]++;
    else if (n < 1e12) {
        for (ll i = 2; i*i<=n; i++) {
            if (n%i==0) {
                pf[i]++;
                factorize(n/i);
                return;
            }
        }
        pf[n]++;
    } else {
        ll d = PollardRho(n);
        if (d==n) {
            pf[d]++;
            return;
        }
        factorize(d);
        factorize(n/d);
    }
}

#define H H3
#define HH 43

//bool cmp(pii a, pii b) {
//    return 1;
//}

pii pl(pii a, pii b) {
    return {a.f+b.f,a.s+b.s};
}
bool inrange(pii a, int K) {
    return (a.f>=0)&&(a.f<=K)&&(a.s>=0)&&(a.s<=K);
}

int query(int k) {
    cout << "? " << k << endl; fl();
    return rd();
}

bool debug = 0;

struct WIP {

struct Splay {

    int val;
    Splay *L,*R,*P,*PP;

    Splay() { L=R=P=PP=nullptr; }
    Splay(int _val) : val(_val) { L=R=P=PP=nullptr; }

    bool isR() {
        return P->R==this;
    }

    void setL(Splay* const C) {
        if (C!=nullptr) C->P=this;
        L=C;
    }

    void setR(Splay* const C) {
        if (C!=nullptr) C->P=this;
        R=C;
    }

	void rotate() {
		const auto p = P;
		const bool i = isR();

		if (p->P != nullptr) {
			if (p->isR()) p->P->setR(this);
			else p->P->setL(this);
		} else P = nullptr;

		if (i) {
            p->setR(L);
            setL(p);
		} else {
		    p->setL(R);
		    setR(p);
		}

		PP=p->PP;
	}

	void yeet() {
	    for (;P!=nullptr;rotate()) {
            if (P->P!=nullptr) {
                if (isR() == P->isR()) P->rotate();
                else this->rotate();
            }
            if(debug) {this->print(); cout << endl;}
	    }
	}

	void print() {
	    cout << val << "[";
	    if (L) cout << L->val; cout << ",";
	    if (R) cout << R->val; cout << "]" << endl;
	    if (L) L->print();
	    if (R) R->print();
	}

};

Splay* access(Splay* V) {
    V->yeet();
    if (V->R != nullptr){
        V->R->PP = V;
        V->R->P = nullptr;
    }
    V->R = nullptr;
    Splay* P = V;
    while (V->PP != nullptr) {
        P = V->PP;
        P->yeet();
        if (P->R != nullptr){
            P->R->PP = P;
            P->R->P = nullptr;
        }
        P->setR(V);
        V->PP = nullptr;
        V->yeet();
    }
    return P;
}

Splay* root(Splay* V) {
    access(V);
    for (;V->L != nullptr; V=V->L);
    access(V);
    return V;
}

void cut(Splay* V) {
    access(V);
    if (V->L == nullptr) return;
    V->L->P=nullptr;
    V->L=nullptr;
}

Splay* lca(Splay* U, Splay* V) {
    if (root(U) != root(V)) return nullptr;
    access(U);
    return access(V);
}

void link(Splay* U, Splay* V) {
    if (lca(U,V)==V) link(V,U);
    else {
        access(V);
        access(U);
        V->setL(U);
    }
}

void cut(Splay* U, Splay* V) {
    if (lca(U,V)==U) cut(V);
    else cut(U);
}

bool conn(Splay* U, Splay* V) {
    return (root(U) == root(V));
}

};


struct Edge{
    long long v, flow, C, rev;
};
struct Dinic {
    long long level [2050], start [2050], cache [2050];
    vector<Edge> adj [2050];
    void addEdge(int u, int v, long long C){
        Edge a{v, 0, C, (long long)adj[v].size()};
        Edge b{u, 0, 0, (long long)adj[u].size()};
        adj[u].pb(a); adj[v].pb(b);
    }
    bool BFS(int s, int t){
        for(int i = 0; i < 2050; i++) level[i] = -1;
        queue<int> q; level[s] = 0; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto e: adj[u])
                if(level[e.v] < 0  && e.flow < e.C){
                    level[e.v] = level[u]+1;
                    q.push(e.v);
                }
        }
        return level[t] != -1;
    }
    long long sendFlow(int u, long long flow, int t){
        if(u == t) return flow;
        for(  ; start[u] < adj[u].size(); start[u] ++){
            Edge &e = adj[u][start[u]];
            if(level[e.v] == level[u]+1 && e.flow < e.C){
                long long curr_flow = min(flow, e.C-e.flow);
                long long temp_flow = sendFlow(e.v, curr_flow, t);
                if(temp_flow > 0){
                    e.flow += temp_flow;
                    adj[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }
    long long flowIt(int s, int t){
        if(s == t) return -1;
        long long total = 0;
        while(BFS(s, t)){
            for(int i = 0; i < 2050; i++) start[i] = 0;
            while (long long flow = sendFlow(s, INF, t)) total += flow;
        }
        return total;
    }
};


pair<pll,ll> F(pair<pll,ll> a, pair<pll,ll> b) {
    return {{max(a.f.f,b.f.f),max(a.f.s,b.f.s)},max(max(a.s,b.s),a.f.f+b.f.s)};
}
ll F(ll a, ll b) {
    return max(a,b);
}

template<typename T>
struct ST {

	int sz;
	vector<T> st;
	T def; // may need to change

	ST(int n, T def) {
	    st = vector<T>();
	    this->def = def;
	    start(n);
    }
	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++)
            st.pb(def);
    }

	void lift(int idx) {
	    st[idx] = F(st[2*idx],st[2*idx+1]);
    }

	void update(int idx, T x) {
		idx += sz;
		st[idx] = x;
		idx >>= 1;
		while (idx) {
            lift(idx); idx >>= 1;
		}
	}

	T query(int lp, int rp) {
		T a = def;
		T b = def;
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F(a,st[lp++]);
			if (rp&1) b = F(st[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F(a,b);
	}

};


LL fac[H5];

void precalc() {
    debug=0;
    fac[0]=1;
    F1(i,H5-1) {
        fac[i] = fac[i-1]*i;
    }
}

vector<int> adj[H5];
vector<int> cringe;
int bruh[H5];

pair<int,LL> dp(int k = N+1) {
    int sz = 1;
    LL curr = 1;
    FE(v,adj[k]) {
        auto x = dp(v);
        sz += x.f;
        curr *= LL(x.s)/fac[x.f];
    }
    curr *= fac[sz-1];
    return {sz,curr};
}

/*void read() {
    N = rd(); K = rd();
    if ((K%2 == 0) && (K >= N-1) && (K <= N*N-1)) {
        int cut = N*N-1-K;
        vector<int> nums(4,0);
        int j = 0;
        for (int i = 2; i < 9999999; i+=2, j++) {
            nums[j%4] += i;
            if (nums[j%4] >= cut) break;
        }
            int overshoot = (nums[j%4]-cut)/2;
            vector<int> output;
            int curr = N*N;
            output.pb(curr);
            int bruh = 0;
            //cout << j%4 << endl;
            if (j%4==3) output.pb(curr -= 1);
            for (int i = 2*(j%4 + 1);; i += 8) {
                //    cout << i << endl;
                curr -= i+1; bruh += i;
                output.pb(curr);
                //cout << bruh << " " << curr << " " << i << endl;
                if (bruh == nums[j%4]) break;
            }
            vector<pii> ret;
            for (int i = output.size()-1; i > 0; i--) {
                if ((i + ((j%4==3)?-1:0)) > overshoot) {
                        if (output[i-1] - output[i] > 1) {
                            ret.pb({output[i]+overshoot,output[i-1]+overshoot});
                        }
                    //cout << output[i]+overshoot << " " << output[i-1]+overshoot  << endl;
                }
            }
            //cout << "STEP" << endl;
            vector<int> output2;
            curr = N*N;
            output2.pb(curr);
            bruh = 0;
            for (int i = 2*(j%4);bruh < overshoot; i += 8, bruh++) {
                curr -= i+1; //bruh += i;
                //cout << curr << " " << bruh << " " << i << endl;
                output2.pb(curr);
                //if (bruh == nums[j%4]) break;
            }
            for (int i = output2.size()-1; i > 0; i--) {
                if (output2[i-1] - output2[i] > 1)
                ret.pb({output2[i],output2[i-1]});
                    //cout << output2[i] << " " << output2[i-1] << endl;
            }
            cout << ret.size() << endl;
            FE(x,ret) {
                cout << x.f << " " << x.s << endl;
            }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}*/

/*
draw_circle_perimeter(R):
  for x between -R and R, inclusive {
    y = round(sqrt(R * R - x * x))   # round to nearest integer, breaking ties towards zero
    set_pixel_to_black(x, y)
    set_pixel_to_black(x, -y)
    set_pixel_to_black(y, x)
    set_pixel_to_black(-y, x)
  }
*/

bool grid[220][220];
int R = 100;
void draw_circle_perimeter(int r) {
    for(int x = -r; x <= r; x++) {
        int y = round(sqrt(r*r-x*x));
        //cout << x << y << endl;
        grid[x+R][y+R] = 1;
        grid[x+R][-y+R] = 1;
        grid[y+R][x+R] = 1;
        grid[-y+R][x+R] = 1;
    }
}
void read() {
    R = rd();
    int ans = 0;
    F0(i,220)F0(j,220) grid[i][j]=0;
    F0(i,R+1) draw_circle_perimeter(i);
    F0(i,2*R+1) { F0(j,2*R+1) {
        if ((i-R)*(i-R)+(j-R)*(j-R) <= R*(R+1))
            //if (i>R) if(j>R)
            if (!grid[i][j]){
                    ans ++;
        //ds(mp(i-R,j-R));
        //cout << ",";
        }
//        cout << (grid[i][j]?' ':'*');
    } //cout << endl;
    }
    cout << ans << endl;
}

int main() {

    precalc();

    bool trials = 1;
    bool interactive = 0;

    if (!interactive) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    if (trials) cases=rd();
    else cases=1;
    int T = cases;
    while (cases--) {
        cout << "Case #" << T-cases << ": ";
        read();
    }

    return 0;
}
