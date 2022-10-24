/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 1000000069

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pll;

int N;

bool fp(const pll& x, const pll& y) {
    return (H*x.f+x.s < H*y.f+y.s);
}

vector<pll> A;
vector<pll> B;
vector<LL> T;
int a=0,b=0;
int lp=0,rp=0;
LL ret=0,sub=0,temp=0;

int main() {

    scanf("%d",&N);

    for (int i = 0; i < N; i++) {
        int x; scanf("%d",&x);
        T.pb(x);
    }

    for (int i = 0; i < N; i++) {
        int y; scanf("%d",&y);
        ret+=abs(T[i]-y);
        if (T[i]<y) {
            a++;
            A.pb(mp(T[i],y));
        } else if (T[i]>y) {
            b++;
            B.pb(mp(y,T[i]));
        }
    }

    sort(A.begin(),A.end(),fp);
    sort(B.begin(),B.end(),fp);

    rp=0; temp=0;

    for (lp = 0; lp < a; lp++) {
        while ((rp<b) && (B[rp].f<=A[lp].f)) {
            temp=max(temp,B[rp].s);
            rp++;
        }
        sub = max(sub, min(temp,A[lp].s)-A[lp].f);
    }

    lp=0; temp=0;

    for (rp = 0; rp < b; rp++) {
        while ((lp<a) && (A[lp].f<=B[rp].f)) {
            temp=max(temp,A[lp].s);
            lp++;
        }
        sub = max(sub, min(temp,B[rp].s)-B[rp].f);
    }

    assert(ret-2*sub>=0);
    cout << ret-2*sub << endl;

}
*/
