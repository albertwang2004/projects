/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 300010

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N,M;
LL X,tot,curr;

LL A[H];
LL AA[H];
int D[H];
bool E[H];
vector<int> adj[H];
int P[H];
queue<int> PROCESS;
queue<int> retf;
stack<int> rets;

//struct Asphalt {
//    bool operator()(pii const& c1, pii const& c2) {
//        return AA[c1.f]+AA[c1.s]<AA[c2.f]+AA[c2.s];
//    }
//};


struct Asphalt {
    bool operator()(int const& c1, int const& c2) {
        return AA[c1]<AA[c2];
    }
};

struct Leaf {
    bool operator()(int const& c1, int const& c2) {
        return adj[c1].size()>adj[c2].size();
    }
};

priority_queue<int,vector<int>,Leaf> C;
map<LL,int> ans;

int pp(int x) {
	if (P[x]==x) return x;
    return (P[x] = pp(P[x]));
}

void un(int a, int b,int i) {
    int x=a; int y=b;
	a = pp(a);
	b = pp(b);
	if (a == b) return;
	adj[x].pb(y);
	adj[y].pb(x);
    ans[(LL)H*(LL)x+(LL)y] = i;
    ans[(LL)H*(LL)y+(LL)x] = i;
	//C.p(mp(x,y));
	if (A[a] > A[b]) swap(a,b);
	A[b] += A[a];
	P[a] = b;
}

bool UN(int a, int b) {
	a = pp(a);
	b = pp(b);
	if (AA[a]+AA[b]<X) return false;
	//if (a == b) return false;
	if (adj[a].size() > adj[b].size()) swap(a,b);
	for (LL i : adj[a]) {
        ans[H*(LL)b+(LL)i] = ans[H*(LL)a+(LL)i];
        ans[H*(LL)i+(LL)b] = ans[H*(LL)i+(LL)a];
	}
	AA[b] += AA[a] - X;
	cout << ans[H*a+b] << endl;
	P[a] = b;
	return true;
}

bool MG(int a, int b) {
    if (adj[a].size() < adj[b].size()) swap(a,b);
    for (int i : adj[b]) {
        adj[a].pb(i);
        adj[i].pb(a);
    }
}

int main() {
    //ifstream fin("tc.in");
    std::cout.sync_with_stdio(false);
    for (int i = 0; i < H; i++) {
        adj[i]=vector<int>();
    }

    scanf("%d %d %d",&N,&M,&X);
    //fin >> N >> M >> X;
    //cout << N << " " << M << " " << X << endl;

    for (int i = 1; i <= N; i++) {
        scanf("%d",&curr);
        //fin >> curr;
        tot+=curr;
        A[i]=1;
        AA[i]=curr;
        P[i] = i;
        E[i] = true;
        //cout << curr << endl;
    }
    //cout << "hi" << endl;
    if (tot/X < N-1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    // cout << "working" << endl;
    for (int i = 1; i <= M; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        //fin >> x >> y;
        //cout << x << " " << y << endl;
        un(x,y,i);
    }

    for (int i = 1; i <= N; i++) {
        P[i] = i;
        D[i] = adj[i].size();
    }
    for (int i = 1; i <= N; i++) {
        if (D[i]==1) PROCESS.p(i);
    }


    //for (int i = 1; i <= N; i++) {
    //    cout << i << " " << D[i] << " : ";
    //    for (int j : adj[i]) {
    //        cout << j << " ";
    //    }
    //    cout << endl;
    //}

    //vector<int> ret;
    //while (C.size()!=0) {
    //    if (ret.size() == N-1) break;
     //   int V = C.top();
    //    //cout << V << endl;
     //   C.pop();
      //  if (!E[V]) continue;
       // for (int U : adj[V]) {
   //         if (E[U]) {
      //          if (adj[U].size() > adj[V].size()) swap(U,V);
     //           E[V] = true;
      //          E[U] = false;
    //            //if (adj[U].size()>5) cout << adj[U].size() << endl;
    //            for (int x : adj[U]) {
     //               if (E[x] && (x != V)) {
      //                  ans[H*V+x]=ans[H*U+x]; // this is fine
     //                   ans[H*x+V]=ans[H*x+U]; // 2.2 some seconds
  //                      adj[V].pb(x);
        //                adj[x].pb(V);
   //                 }
      //          }
     //           AA[V]+=AA[U]-X;
     //           ret.pb(ans[H*V+U]);
     //           C.p(V);
    //            break;
    //        }
    //    }
  //  }
    //while (C.size() != 0) {
    //    pii e = C.top();
    //    C.pop();
    //    int u = e.f;
    //    int v = e.s;
    //    if (!UN(u,v)) C.p(mp(u,v));
    //}
    //for (int i : ret) {
   //     cout << i << endl;
   // }
    while (PROCESS.size() != 0) {
        int x = PROCESS.fr();
        //if (!E[x]) continue;
        //cout << x << endl;
        PROCESS.pop();
        if (!E[x]) continue;
        if (D[x]!=1) continue;
        int v;
        for (int i = 0; i < adj[x].size(); i++) {
            int u = adj[x][i];
            if (E[u]) v=u;
            if (E[u] && (D[u]==2)) PROCESS.p(u);
        }
        LL asph = AA[x]+AA[v];
        int a = ans[(LL)H*(LL)x+(LL)v];
        if (asph>=X) {
            cout << a << endl;
            AA[v]+=AA[x]-X;
        } else {
            rets.p(a);
        }
        E[x] = false;
        D[x]--;
        D[v]--;
    }
    while (rets.size()>0) {
        int x = rets.top();
        cout << x << endl;
        rets.pop();
    }

}
*/
