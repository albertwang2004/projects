/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 800010
#define MOD 1000000007

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

LL S(pii P) {
    return P.f+P.s;
}

bool diag(pii a, pii b) {
    return S(a)<S(b);
}

int N;
multiset<LL> FL;
multiset<LL> FR;
vector<pii> PQ;
int main() {
    FL.ins(0);
    FR.ins(0);
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        int x,y; scanf("%d%d",&x,&y);
        PQ.pb(mp(x,y));
    }
    sort(PQ.begin(),PQ.end(),diag);
    LL curr = 0;
    LL shift = 0;
    LL ret = 0;
    for (int i = 0; i < N; i++) {
        pii P = PQ[i]; ret += P.f;
        LL d = S(P)-curr; shift += d;
        LL L = *FL.rbegin();
        LL R = *FR.begin()+shift;
        if (P.f<L) {
            FL.erase(--FL.end());
            FL.ins(P.f);FL.ins(P.f);
            FR.ins(L-shift);
        } else if (P.f>R) {
            FR.erase(FR.begin());
            FR.ins(P.f-shift);FR.ins(P.f-shift);
            FL.ins(R);
        } else {
            FL.ins(P.f);
            FR.ins(P.f-shift);
        }
        curr=S(P);
    }
    multiset<LL>::iterator it = FL.begin();
    for (int i = 0; i <= N; i++, it++) {
        ret -= *it;
    }
    cout << ret << endl;
}
*/
