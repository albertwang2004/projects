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

#define H 3*H2
#define HH 43

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

int cases,N,M,Q,K; ll X,Y;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << -1 << endl;
    exit(0);
}

// mergesort inversion


int seats[H][H];
int order[H][H];
vector<int> nums;
vector<int> num;
unordered_map<int,int> start;

void read() {
    N=rd();M=rd(); nums.clear(); start=unordered_map<int,int>(); num.clear();
    F0(i,N*M) {nums.pb(rd());num.pb(nums[i]); start[nums[i]]=9999999;}
    sort(nums.begin(),nums.end());
    int idx = 0;
    F0(i,N) F0(j,M) {
        order[i][j]=0;
        seats[i][j] = nums[idx++];
        start[seats[i][j]]=min(start[seats[i][j]],i*M+j);
    }
    for (auto it = start.begin(); it != start.end(); ++it) {
        //cout << it->f << " : " << it->s << endl;
        int pos = it->s/M;
        int col = M-1;
        while (seats[pos][col]!=it->f) col--;
        it->s=M*pos+col;
        //cout << it->f << " : " << it->s << endl;
    }
    F0(i,N*M) {
        int pos = start[num[i]];
        //cout << "Placing " << num[i] << " " << pos << endl;
        int r = pos/M;
        int c = pos%M;
        //cout << r << " " << c << endl;
        order[r][c]=i+1;
    //F0(i,N) {F0(j,M) cout << order[i][j] << " " ; cout << endl; }
        c = pos%M - 1;
        start[num[i]] = r*M+c;
        //cout << seats[r][c] << " " << r << " " << c << endl;
        if (c==-1) {
            int col = M-1;
        while (seats[r+1][col]!=num[i]) col--;
            start[num[i]]=M*(r+1)+col;
            //cout << "upd " << num[i] << " "  << start[num[i]] << endl;
        } else if (seats[r][c]!=num[i]) {
            int col = M-1;
        while (seats[r+1][col]!=num[i]) col--;
            start[num[i]]=M*(r+1)+col;
        } else {
        }
    }
    //F0(i,N) {F0(j,M) cout << order[i][j] << " " ; cout << endl; }
    ll ret = 0;
    F0(i,N) {
        set<int> temp;
        temp.ins(order[i][0]);
        set<int>::iterator it;
        for (int j = 1; j < M; j++) {
            temp.ins(order[i][j]);
            it=temp.upper_bound(order[i][j]);
            ret+=distance(it,temp.end());
        }
    }
    ret = N*(M*(M-1)/2)-ret;
    cout << ret << endl;
}

int main() {
    bool trials = 1;
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
