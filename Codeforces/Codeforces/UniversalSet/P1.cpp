/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 1010
#define MOD 1000000007
#define INF 9999999999

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;
typedef std::chrono::high_resolution_clock Clock;


// gcd
LL gcd(LL a, LL b) {
   return b?gcd(b, a % b):a;
}
// fraction simplification
pii simp(pii x) {
    return mp(x.f/gcd(x.f,x.s),x.s/gcd(x.f,x.s));
}
// ceil(x/y)
LL upDiv(LL x, LL y) {
    return (x+y-1)/y;
}

LL solve(pair<pii,pii> in) {

    LL ax = in.f.f;
    LL ay = in.f.s;
    LL bx = in.s.f;
    LL by = in.s.s;

    LL ret = 0; // our running total

    for (LL p = 1; p <= H; p++) {
        for (LL q = 1; q <= H; q++) {
            if (simp(mp(p,q))==mp(p,q)) { // our slope q/p is simplified
                // all answers are of the form
                // (kp(p+q),kq(p+q)), for p,q <= 10^3
                LL kL = 0; // least acceptable k
                LL kU = INF; // highest acceptable k

                LL mx = p*(p+q);
                LL my = q*(p+q);

                kL = max(kL, upDiv(ax,mx));
                kL = max(kL, upDiv(ay,my));

                kU = min(kU, bx/mx);
                kU = min(kU, by/my);

                ret += max(0LL,kU-kL+1);
            }
        }
    }

    return ret;

}

LL DP[H][H];

int main() {

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i*j==0) DP[i][j]=0;
            else {
                DP[i][j]=(LL)((i*j)%(i+j)==0LL)+DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1];
            }
            //cout << DP[i][j] << " ";
        }
        //cout << endl;
    }
    vector<pair<pii,pii>> TCS;

    TCS.pb(mp(mp(5,10),mp(12,16)));
    TCS.pb(mp(mp(4,12),mp(5,13)));

    TCS.pb(mp(mp(1,1),mp(1,1)));
    TCS.pb(mp(mp(20,670),mp(70,948)));
    TCS.pb(mp(mp(35,140),mp(60,180)));
    TCS.pb(mp(mp(35,140),mp(59,179)));
    TCS.pb(mp(mp(36,141),mp(59,179)));
    TCS.pb(mp(mp(1,1),mp(1000,1000)));

    TCS.pb(mp(mp(180245,366989),mp(501259,876494)));
    TCS.pb(mp(mp(200,201),mp(268500,501591)));
    TCS.pb(mp(mp(101,103),mp(13407,111709)));

    TCS.pb(mp(mp(105211,104663),mp(790217,151882)));
    TCS.pb(mp(mp(20,675990),mp(961827,985448)));
    TCS.pb(mp(mp(134617,123851),mp(883644,586782)));
    TCS.pb(mp(mp(45693,175411),mp(636757,743688)));
    TCS.pb(mp(mp(259,182),mp(429518,675874)));
    TCS.pb(mp(mp(696969,696969),mp(888888,888888)));
    TCS.pb(mp(mp(1,1),mp(2000,1000000)));
    TCS.pb(mp(mp(1,1),mp(1000000,2000)));
    TCS.pb(mp(mp(1,1),mp(1000000,1000000)));

    int num = 1;
    for (pair<pii,pii> tc : TCS) {
        LL i = tc.f.f;
        LL j = tc.f.s;
        LL k = tc.s.f;
        LL l = tc.s.s;
        LL jury;
        if (max(i,max(j,max(k,l)))<=H-10) jury = (DP[k][l]-DP[i-1][l]-DP[k][j-1]+DP[i-1][j-1]);

        auto t1 = Clock::now();
        LL ans = solve(mp(mp(i,j),mp(k,l)));
        auto t2 = Clock::now();
        int duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()/1000000;

        if (max(i,max(j,max(k,l)))>H-10) jury = ans; // naive is too slow
        if (jury != ans) {
            cout << "Wrong answer on " << i << " " << j << " " << k << " " << l << endl;
            cout << "Received " << ans << " but answer is " << jury << endl;
            return -1;
        }
        printf("Test %d ok, t=%d ms, ans=%lld\n", num, duration, ans);
        num++;
    }
    cout << "Accepted" << endl;
    return 0;
}
*/
