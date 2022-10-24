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

#define H 5*H2
#define HH 10

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

int cases,N,M,Q; ll K,X,Y;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << -1 << endl;
    exit(0);
}

int A[H][H];
int DP[3*H2][H][H]; // DP[sz][r][c];
vector<pii> potential;

void dfs(pii k) {
    DP[0][k.f-1][k.s-1]=1;
    int R; for (R=1;;R++) {
        bool ok = 1;
        FR0(i,k.f-R,k.f) {ok&=(A[i][k.s-R]==0);}
        FR0(i,k.s-R,k.s) {ok&=(A[k.f-R][i]==0);}
        FR0(i,k.f,k.f+R) {ok&=(A[i][k.s-R]==1);}
        FR0(i,k.s-R,k.s) {ok&=(A[k.f+R-1][i]==1);}
        FR0(i,k.f-R,k.f) {ok&=(A[i][k.s+R-1]==2);}
        FR0(i,k.s,k.s+R) {ok&=(A[k.f-R][i]==2);}
        FR0(i,k.f,k.f+R) {ok&=(A[i][k.s+R-1]==3);}
        FR0(i,k.s,k.s+R) {ok&=(A[k.f+R-1][i]==3);}
        if (ok) DP[R][k.f-1][k.s-1]=1;
        else break;
    }
}

void dp() {
    F0(R,min(N,M)*3/5+1) {
        F1(i,N+1) {
            F1(j,M+1) {
                DP[R][i][j]
                    +=DP[R][i-1][j]
                    + DP[R][i][j-1]
                    - DP[R][i-1][j-1];
                //cout << DP[R][i][j] << " ";
            }
            //cout << endl;
        }
        //cout << endl << endl << endl;
    }
}

void read() {
    N=rd();M=rd();Q=rd();
    F1(i,N) {
        string x; cin >> x;
        F1(j,M) {
            char k = x.at(j-1);
            switch (k) {
            case 'R':
                A[i][j] = 0;
                break;
            case 'Y':
                A[i][j] = 1;
                break;
            case 'G':
                A[i][j] = 2;
                break;
            case 'B':
                A[i][j] = 3;
                break;
            default:
                panic();
            }
            //cout << A[i][j];
        }
        //cout << endl;
    }
    F1(i,N) F1(j,M) {
        if ((A[i][j]==0)&&(A[i][j+1]==2)&&(A[i+1][j]==1)&&(A[i+1][j+1]==3))
            potential.pb(mp(i+1,j+1));
    }
    for (pii x : potential) dfs(x);
    dp();
    F0(i,Q) {
        int x1=rd();int y1=rd();int x2=rd();int y2=rd();
        x1--;y1--;
        int lb = 0;
        int rb = (min(x2-x1,y2-y1)+1)>>1;
        while (lb<rb) {
            int mb = (lb+rb+1)>>1;
            //cout << lb << " " << mb << " " << rb << endl;
            bool chk = 0;
            if (mb==0) chk=1;
            else if (x2-mb<0) chk=0;
            else if (y2-mb<0) chk=0;
            else if (x1+mb-1>N) chk=0;
            else if (y1+mb-1>M) chk=0;
            else {
                    //cout << x2-mb << " " << y2 -mb << endl;
            //cout << x1+mb << " " << y1+mb << endl;
                chk =DP[mb][x2-mb][y2-mb]
                    -DP[mb][x2-mb][y1+mb-1]
                    -DP[mb][x1+mb-1][y2-mb]
                    +DP[mb][x1+mb-1][y1+mb-1];
            }
            if (chk) lb=mb;
            else rb=mb-1;
        }
        cout << 4*lb*lb << endl;
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
