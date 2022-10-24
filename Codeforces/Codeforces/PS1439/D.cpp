/*// Slope trick practice

#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 3100
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N;
priority_queue<LL,vector<LL>,less<LL>> F;

int main() {
    scanf("%d",&N);
    LL ret = 0;
    LL k = 0;
    for (LL i = 1; i <= N; i++) {
        scanf("%d",&k);
        LL n = k;//-i;
        F.p(n);F.p(n);
        LL x = F.top(); F.pop();
        cout << x<< " " << n << endl;
        ret+=x-n;
    }
    cout << ret << endl;
}
*/
