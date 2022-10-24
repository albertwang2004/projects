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

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 5000000000000000000

using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
struct LL {

    static const ll m = mod; // set to LNF for nomod
    long long int val;

    LL(ll v) {val=reduce(v);};
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

int T,N,M,K,Q;

int rd() {int x; scanf("%d",&x); return x;}
void fl() {cout.flush();}

bool compx(pll a, pll b) {return a.f<b.f;}
bool compy(pll a, pll b) {return a.s<b.s;}

map<pll,int> idx;
vector<pll> ptsx;
vector<pll> ptsy;
vector<pll> adj[H];

ll dist[H];

void dijk(int v) {
    dist[0] = 0;
    for (int i = 1; i < H; ++i) {
        dist[i] = LNF;
    }
    bool flag[100005] = { false };
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pll p = pq.top();
        pq.pop();
        if (flag[p.second]) continue;
        flag[p.second] = true;
        for (pll edge : adj[p.second]) {
            ll node = edge.first;
            ll cost = edge.second;
            if (!flag[node] && dist[node] > dist[p.second] + cost) {
                dist[node] = dist[p.second] + cost;
                pq.push(make_pair(dist[node], node));
            }
        }
    }
}

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        for (int i = 0; i < H; i++) {
            adj[i] = vector<pll>();
        }

        M=rd(); N=rd();

        ll sx=rd(),sy=rd(),fx=rd(),fy=rd();
        ll Sx=sx,Sy=sy,Fx=fx,Fy=fy;

        if (N==0) {
            cout << abs(Sx-Fx)+abs(Sy-Fy) << endl; return 0;
        }
        idx[mp(sx,sy)]=0;
        idx[mp(fx,fy)]=1;
        int ctr = 2;

        for (int i = 0; i < N; i++) {
            sx=rd();sy=rd();
            idx[mp(sx,sy)]=ctr++;
            ptsx.pb(mp(sx,sy));
            ptsy.pb(mp(sx,sy));
        }

        //for (auto it = idx.begin(); it != idx.end(); it++) {
        //    cout << (it->f.f) << " " << (it->f.s) << " " << (it->s) << endl;
        //}

        sort(ptsx.begin(),ptsx.end(),compx);
        sort(ptsy.begin(),ptsy.end(),compy);

        for (int i = 0; i < N+1; i++) {

            int l = idx[ptsx[i]];
            int r = idx[ptsx[i+1]];

            ll d = min(abs(ptsx[i].f-ptsx[i+1].f),
                        abs(ptsx[i].s-ptsx[i+1].s));

            //cout << "x " << l << " " << r << " " << d << endl;

            if ((l>=2) && (r>=2)) {
                adj[l].pb(mp(r,d));
                adj[r].pb(mp(l,d));
            }

        }

        for (int i = 0; i < N+1; i++) {

            int l = idx[ptsy[i]];
            int r = idx[ptsy[i+1]];

            ll d = min(abs(ptsy[i].f-ptsy[i+1].f),
                        abs(ptsy[i].s-ptsy[i+1].s));

            //cout << "y " << l << " " << r << " " << d << endl;

            if ((l>=2) && (r>=2)) {
                adj[l].pb(mp(r,d));
                adj[r].pb(mp(l,d));
            }

        }

        for (int i = 0; i < N+2; i++) {

            int ii = idx[ptsx[i]]; if (ii<2) continue;

            ll d0 = min(abs(ptsx[i].f-Sx),abs(ptsx[i].s-Sy));
            ll d1 = abs(ptsx[i].f-Fx)+abs(ptsx[i].s-Fy);
                adj[0].pb(mp(ii,d0));
                adj[ii].pb(mp(0,d0));
                adj[1].pb(mp(ii,d1));
                adj[ii].pb(mp(1,d1));

        }


        ll d = abs(Fx-Sx)+abs(Fy-Sy);
        adj[0].pb(mp(1,d));
        adj[1].pb(mp(0,d));

        //for (int i = 0; i < N+2; i++) {
        //    cout << i << ": ";
        //    for (pii a : adj[i]) {
        //        cout << "(" << a.f << "," << a.s <<") ";
        //    }
        //cout << endl;
        //}

        dijk(0); cout << dist[1] << endl;

    }
}
*/
