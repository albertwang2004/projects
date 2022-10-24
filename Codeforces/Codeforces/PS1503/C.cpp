/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 100010
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

int N;
vector<pii> C;
int main() {
    scanf("%d",&N);
    LL ret = 0;
    for (int i = 1; i <= N; i++) {
        LL x; LL y;
        scanf("%lld%lld",&x,&y);
        C.pb(mp(x,y));
        ret+=y;
    }
    sort(C.begin(),C.end());
    LL worst = C[0].f+C[0].s;
    for (int i = 1; i < N; i++) {
        ret+=max(0LL,C[i].f-worst);
        worst=max(worst,C[i].f+C[i].s);
    }
    cout << ret << endl;
}*/
