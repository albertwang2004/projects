/*

// arithmetic

struct LL {

    static const long long int m = MOD; // set to LNF for nomod
    long long int val;

    LL(long long int v) {val=reduce(v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(long long int l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(long long int x, long long int md = m) {
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
    LL operator+(const long long int& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const long long int& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const long long int& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const long long int& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const long long int& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const long long int& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const long long int& y){
        long long int z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(long long int y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const long long int& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const long long int& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }


// bicolor

int color[H];

bool color2(int v, int c) {
    if (color[v]) {
        if (color[v]!=c) return false;
        else return true;
    } else {
        color[v]=c;
        bool ret = 1;
        for (int x : adj[v]) {
            ret = ret && color2(x,3-c);
        }
        return ret;
    }
}


// child count

int dfs(int v, int c) {
    V[v]=1;
    D[v]=c++;
    int ret = 1;
    for (int u : adj[v]) {
        //if (used[mp(u,v)]) continue;
        if (V[u]) continue;
        ret += dfs(u,c);
        edges.pb(mp(u,v));
        ++rp;
    }
    C[v]=ret;
    V[v]=0;
    return ret;
}


// convex hull - monotone chain
// thank you penguin

vector<Point> ch(vector<Point>& points) {
    vector<Point> hull;
    sort(points.begin(), points.end());
    for (int rep=0; rep<2; ++rep) {
        vector<Point> cur;
        for (Point& p : points) {
            while(cur.size()>=2&&(cur.back()-cur.end()[-2])*(p-cur.back())>0) cur.pop_back();
            cur.push_back(p);
        }
        cur.pop_back();
        for (Point p : cur) hull.push_back(p);
        reverse(points.begin(), points.end());
    }
    return hull;
}


// delete vertex

void del(int u) {
    adj[u].erase(k);
    adj[k].erase(u);
}


// dfs

void dfs(int v) {
    if (!V[v]) {
        V[v]=true;
        LL ret = 1;
        for (int u : adj[v]) {
            if (!V[u]) {
                P[u]=v;
                dfs(u);
                ret+=C[u];
            }
        }
        C[v]=ret;
    }
}


// dijkstra n log n

priority_queue<pii,vector<pii>,greater<pii>> PQ;
void dijk(int v) {
    for (int i = 0; i < N; i++) {
        D[i]=MOD;
    }
    D[v]=0;
    PQ.p(mp(0,v));
    while (PQ.size()) {
        int d = PQ.t().f; int u = PQ.t().s; PQ.pop();
        if (d!=D[u]) continue;
        for (pii e : adj[u]) {
            if (D[e.f]>D[u]+e.s) {
                PQ.p(mp(D[e.f]=D[u]+e.s,e.f));
            }
        }
    }
}


// dijkstra n^2

vector<int> D;
void dijk(int c) {
    D.assign(N+5,LNF);
    vector<bool> U(N+5,0);
    for (tri i : que[c]) {
        D[i.f.f] = -i.f.s;
    }
    for (int i = 1; i <= N; i++) {
        int v = -1;
        for (int j = 1; j <= N; j++)
        if (!U[j] && (v == -1 || D[j] < D[v])) v = j;
        if (D[v] == LNF) break;
        U[v] = 1;
        for (auto e : adj[v]) {
            int u = e.f;
            int d = e.s;
            if (D[v] + d < D[u]) {
                D[u] = D[v] + d;
            }
        }
    }
}


// dsu

struct DSU {
    vector<int> P;
    vector<int> S;
    vector<int> U;
    int NC;

    DSUt(int N) {start(N);}

    void start(int N) {
        NC=N;
        U.clear();
        for (int i = 0; i <= N; i++) {
            P.pb(i);
            S.pb(1);
        }
    }

    int SZ(int x) {return S[pp(x)];}

    int pp(int x) {
        if (P[x]==x) return x;
        return (P[x] = pp(P[x]));
    }

    bool un(int a, int b) {
        int A = pp(a);
        int B = pp(b);
        if (A == B) {
            return 0;
        }
        if (S[A] > S[B]) {swap(A,B);}
        S[B] += S[A];
        P[A] = B;
        NC--;
        return 1;
    }
};


// dsu*

struct DSUt {
    vector<int> P;
    vector<int> S;
    vector<int> D;
    vector<int> L;
    vector<vector<pii>> adj;

    DSUt(int N) {start(N);}

    void start(int N) {
        adj.clear();
        for (int i = 0; i <= N; i++) {
            P.pb(i);
            S.pb(1);
            D.pb(1);
            L.pb(0);
            adj.pb(vector<pii>());
        }
    }

    int SZ(int x) {return S[pp(x)];}

    int dt(int a, int b) {
        if (pp(a)!=pp(b)) return -1;
        return L[a]^L[b]; // this only works for XOR. dunno how to LCA efficiently for other query types
    }

    int pp(int x) {
        if (P[x]==x) return x;
        return (P[x] = pp(P[x]));
    }

    void upd(int k, int l) {
        L[k]^=l;
        for (pii u : adj[k]) {
            if (D[u.f]<D[k]) {
                upd(u.f,l);
            }
        }
    }

    bool un(int a, int b, int d) {
        int A = pp(a);
        int B = pp(b);
        if (A == B) {
            if (dt(a,b)==d) return 1;
            else return 0;
        }
        if (S[A] > S[B]) {swap(A,B);}
        d^=L[a]^L[b];
        S[B] += S[A];
        P[A] = B;
        D[B] = max(D[B],D[A]+1);
        adj[A].pb(mp(B,d));
        adj[B].pb(mp(A,d));
        upd(A,d);
        return 1;
    }
};


// fenwick tree

ll BT[H];
ll A[H];

void update(ll idx, ll x) {
   ll d = x - A[idx];
   A[idx] = x;
   while (idx <= N) {
       BT[idx] += d;
       idx += (idx & -idx);
   }
}

ll sum(ll idx) {
   ll s = 0;
   while (idx >= 1) {
       s += BT[idx];
       idx -= (idx & -idx);
   }
   return s;
}

ll subSeq(ll a, ll b) {
   return sum(b) - sum(a-1);
}

// fft

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}


// fft - polynomial multiplication

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


// flow O(EF)

struct FFA {
    const static int n=5*H5;
    map<pii,int> cap;
    vector<int> adj[n];

    void addEdge(int u, int v, int c) {
        cap[{u,v}]=c;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pii> q;
        q.p({s, INF});
        while (!q.empty()) {
            int cur = q.fr().f;
            int flow = q.fr().s;
            q.pop();
            for (int next : adj[cur]) {
                if ((parent[next] == -1) && (cap[mp(cur,next)]>0)) {
                    parent[next] = cur;
                    int new_flow = min(flow, cap[mp(cur,next)]);
                    if (next == t) return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while (new_flow = bfs(s, t, parent)) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                cap[mp(prev,cur)] -= new_flow;
                cap[mp(cur,prev)] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};


// flow <<E^2V

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


// floyd-warshall

ll dist[H][H];
void fw() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = LNF;
        }
        for (pll e : adj[i]) {
            adjj[i][e.f] = e.s;
            dist[i][e.f] = e.s;
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

// flush and read

int rd() {int x; scanf("%d",&x); return x;}
void fl() {cout.flush();}


// fraction simplification

pii simp(pii x) {
    return mp(x.f/gcd(x.f,x.s),x.s/gcd(x.f,x.s));
}


// gcd

int gcd(int a, int b) {
   return b?gcd(b, a % b):a;
}


// hash a pair

int hp(pii x) {
    return N*x.f+x.s;
}

pii hi(int x) {
    return mp(x/N,x%N);
}


// indexed set

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; ++i) {
		int n; cin >> n;
		Tree<int> TS; long long numInv = 0;
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			numInv += j-TS.order_of_key(x); // gives # elements before it > x
			TS.insert(x);
		}
		cout << numInv << "\n";
	}
}


// inversion count N log N


ll ret = 0;
multiset<int> temp;
temp.ins(C[0]);
multiset<int>::iterator it;
Fr(i,1,N+M) {
    temp.ins(C[i]);
    it=temp.upper_bound(C[i]);
    ret+=distance(it,temp.end());
}

// LCA & binary lifting & paths on a tree
struct LCA {
    // segment tree
    int sz,rt,lg;
    vector<int> depth;
    vector<vector<int>> up;
    vector<pii> bruh;
    //vector<vector<ll>> adj;
    LCA(int _sz, const vector<vector<int>>& _adj, int _rt = 1) :
        sz(_sz), rt(_rt) {lg=ceil(log2(_sz)); build(_rt,_adj);}
    vector<bool> V;
    void dfs(int& t, int v, int x, int p, const vector<vector<int>>& adj) {
        V[v]=1;
        depth[v]=x;
        bruh[v].f=t++;
        up[v].pb(p);
        F1(i,lg) up[v].pb(up[up[v][i-1]][i-1]);
        FE(u,adj[v]) if (!V[u]) {
            dfs(t,u,x+1,v,adj);
        }
        bruh[v].s=t++;
    }
    void build(int rt, const vector<vector<int>>& adj) {
        V.clear(); depth.clear(); bruh.clear(); up.clear();
        F0(i,sz+1) { V.pb(0); bruh.pb({-1,-1}); up.pb(vector<int>()); depth.pb(0);}
        int t = 0; dfs(t,rt,0,rt,adj);
    }
    bool is_ancestor(int u, int v) { return bruh[u].f <= bruh[v].f && bruh[u].s >= bruh[v].s; }
    int query(int v, int u) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = lg; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int v, int u) { return depth[v]+depth[u]-(depth[query(v,u)]<<1); }
    int walk(int v, int u, int d) {
        int dv = depth[v];
        int da = depth[query(v,u)];
        int du = depth[u];
        int lt = dv+du-(da<<1);
        if (lt<=d) return u;
        if (d<dv-da) {
            R0(x,lg+1) if (d&(1<<x)) {
                d^=1<<x; v=up[v][x];
            }
        } else {
            d=lt-d; v=u; R0(x,lg+1) if (d&(1<<x)) {
                d^=1<<x; v=up[v][x];
            }
        }
        return v;
    }
};



// mergesort inversion

LL mergeInv(int L, int M, int R) {
    int i=L,j=M;
    LL ret = 0;
    for (int idx = L; idx < R; idx++) {
        if (idx<=M) B[idx]=A[idx];
        else B[idx]=A[idx];
    }
    while ((i < M) && (j < R)) {
        if (B[i] <= B[j]) {
            A[i+j] = B[i];
            i++;
        } else {
            A[i+j] = B[j];
            j++;
            ret+=M-i;
        }
    }
    for (;i<M;i++) A[i] = B[i];
    for (;j<R;j++) A[j] = B[j];
    return ret;
}

LL mergeSort(int L, int R) {
    if (R-L>1) {
        int M = (L+R)/2;
        return mergeSort(L, M) + mergeSort(M, R) + mergeInv(L,M,R);
    } else {
        return 0;
    }
}


// minkowski sum

vector<Point> minkowskiSum(vector<Point>& P, vector<Point>& Q) {
    int idx;
    idx = 0;
    for (int i = 1; i < P.size(); i++) {
        if (P[i].y<P[idx].y
            || (P[i].y==P[idx].y
                && P[i].x<P[idx].x))
            idx = i;
    }
    rotate(P.begin(),P.begin()+idx,P.end());
    P.pb(P[0]);
    P.pb(P[1]);
    idx = 0;
    for (int i = 1; i < Q.size(); i++) {
        if (Q[i].y<Q[idx].y
            || (Q[i].y==Q[idx].y
                && Q[i].x<Q[idx].x))
            idx = i;
    }
    rotate(Q.begin(),Q.begin()+idx,Q.end());
    Q.pb(Q[0]);
    Q.pb(Q[1]);
    vector<Point> ret;
    int i = 0, j = 0;
    while (i+2<P.size() || j+2<Q.size()){
        ret.pb(P[i]+Q[j]);
        ll cp = (P[i+1]-P[i])*(Q[j+1]-Q[j]);
        if (cp >= 0) i++;
        if (cp <= 0) j++;
    }
    return ret;
}



// modular exponentiation

LL modexp(LL x, LL y){
    LL ret = 1;
    while (y) {
        if (y % 2 == 1) ret = (ret * x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return ret%MOD;
}


// ordered indexed set (AVL + node size dp)
class oset {
public:
    struct Node {                                                               /// STRUCT FOR AVL NODES

        int id;
        Node* left;                                                             // left child
        Node* right;                                                            // right child

        int height;                                                             // height of node
        int nodeCount;                                                          // number of nodes in this subtree

        int leftHeight() {                                                      /// Height of left child
            if (left == nullptr) return 0;
            else return left->height;
        }

        int rightHeight() {                                                     /// Height of right child
            if (right == nullptr) return 0;
            else return right->height;
        }

        int leftNodeCount() {                                                   /// Node count of left child
            if (left == nullptr) return 0;
            else return left->nodeCount;
        }

        int rightNodeCount() {                                                  /// Node count of right child
            if (right == nullptr) return 0;
            else return right->nodeCount;
        }


        void update() {                                                         /// Update the height and nodeCount for this node
            height = 1 + max(leftHeight(), rightHeight());
            nodeCount = 1 + leftNodeCount() + rightNodeCount();
        }


        Node(int ID = 0,                                   /// NODE CONSTRUCTOR
                Node* LEFT = nullptr, Node* RIGHT = nullptr) {                  /// DEFAULTS TO LEAF
            id = ID;
            left = LEFT;
            right = RIGHT;
            update();
        }




    };

    Node* tree;
    oset() {
        tree = nullptr;
    }




    ///////////
    // DEBUG //
    ///////////

    void printTree() { printTree(tree); }
    void printTree(Node* node, int depth = 0) {                                 /// DEBUG ONLY
        for (int d = 0; d < depth; d++) cout << "    ";
        if (node == nullptr) cout << "nullptr" << endl;
        else {
            ++depth;
            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "Left child {" << endl;
            printTree(node->left,depth);

            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "} Right Child {" << endl;
            printTree(node->right,depth);

            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "}" << endl;
        }
    }

    int sz() { return (tree==nullptr)?0:(tree->nodeCount); }
    int NLE(int a) { return NLE(a,tree); }
    int NLE(int a, Node* node) {
        if (node == nullptr) return 0;
        if (node->id>a) return NLE(a,node->left);
        else return NLE(a,node->right) + 1+((node->left==nullptr)?0:node->left->nodeCount);
    }
    int NLT(int a) {return NLE(a-1);}


    ///////////////////
    // NODE ROTATION //
    ///////////////////

    Node* rotateLeft(Node *node) {                                              /// ROTATE node LEFT (requirement: has right child)
                                                                                /// returns new root

        if (node == nullptr) return node;                                       // unsuccessful rotation.
        if (node->right == nullptr) return node;                                // unsuccessful rotation.

        Node* ret = node->right;                                                // this will be the returned node
        node->right = ret->left;                                                // move the new root
        ret->left = node;                                                       // link the past root to the new root

        ret->left->update();                                                    // update height of new left node
        ret->update();                                                          // update height of new root

        return ret;
    }


    Node* rotateRight(Node* node) {                                             /// ROTATE node RIGHT (requirement: has left child)
                                                                                /// returns new root

        if (node == nullptr) return node;                                       // unsuccessful rotation.
        if (node->left == nullptr) return node;                                 // unsuccessful rotation.

        Node* ret = node->left;                                                 // this will be the returned node
        node->left = ret->right;                                                // move the new root
        ret->right = node;                                                      // link the past root to the new root

        ret->right->update();                                                   // update height of new right node
        ret->update();                                                          // update height of new root

        return ret;
    }




    ///////////////////////
    // HELPFUL FUNCTIONS //
    ///////////////////////


    pair<Node*,Node*> searchAndBalanceHelper(int id, Node* node) {              /// HELPER: SIMULTANEOUSLY SEARCH AND BALANCE A TREE FOR UFID id FROM node
                                                                                /// returns a pair {the desired node or nullptr if not found, the root}

        pair<Node*,Node*> ret = make_pair(nullptr, nullptr);                    // this will be the returned value

        if (node == nullptr) return ret;                                        // if there is nothing to search
        else if (id == node->id) ret.first = node;                              // if the desired node is found
        else if (id < node->id) {                                               // if we need to look on the left
            ret = searchAndBalanceHelper(id, node->left);                       //     recurse
            node->left = ret.second;                                            //     update node's left child
        } else {                                                                // if we need to look on the right
            ret = searchAndBalanceHelper(id, node->right);                      //     recurse
            node->right = ret.second;                                           //     update node's right child
        }

        node->update();

        while (node->leftHeight() - node->rightHeight() >= 2) {                 // while this node is skewed, rotate it
            if (node->left->id < id)                                        // R-L rotation case
                node->left = rotateLeft(node->left);
            node = rotateRight(node);
            return make_pair(ret.first, node);
        }

        while (node->rightHeight() - node->leftHeight() >= 2) {                 // repeat for other direction
            if (node->right->id > id)                                            // L-R rotation case
                node->right = rotateRight(node->right);
            node = rotateLeft(node);
            return make_pair(ret.first, node);
        }

        return make_pair(ret.first, node);
    }


    pair<Node*,Node*> searchAndBalanceHelper(Node* key, Node* node) {           /// Overloads the above function, searching for a Node* instead
        return searchAndBalanceHelper(key->id, node);
    }


    Node* findParent(Node* key, Node* node) {                                   /// HELPER: FINDS PARENT NODE OF key IN node
                                                                                /// returns desired node, or the node if it's the root, or nullptr if fail
        if (node == nullptr) return nullptr;                                    // fail
        if (key->id == node->id) return key;                                    // found key

        else if (key->id < node->id) {                                          // look left

            Node* ret = findParent(key, node->left);                            //     recurse
            if (ret == key) return node;                                        //     found the parent node
            else return ret;                                                    //     carry result

        } else {                                                                // look right

            Node* ret = findParent(key, node->right);                           //     recurse
            if (ret == key) return node;                                        //     found the parent node
            else return ret;                                                    //     carry result

        }
    }


    Node* findParent(int id, Node* node) {                                      /// Overloads the above function with a slightly different return result
                                                                                /// returns desired node, or nullptr if fail
        Node* key = new Node(id);                                               // dummy node
        Node* ret = findParent(key, node);                                      // call helper

        if (ret == key) ret = nullptr;                                          // adjust result
        return ret;
    }


    Node* findInorder(int num, Node* node) {                                    /// HELPER: FINDS numTH NODE IN INORDER, 0-INDEXED
                                                                                /// returns desired Node* if found, nullptr if out of range
        if (node == nullptr) return nullptr;                                    // bad
        else if (num < 0) return nullptr;                                       // negative is bad
        else if (num >= node->nodeCount) return nullptr;                        // too big, also bad

        else if (num == node->leftNodeCount()) return node;                     // we found it!
        else if (num > node->leftNodeCount())                                   // we want to look in the right tree
            return findInorder(num-node->leftNodeCount()-1, node->right);       // adjust index accordingly
        else return findInorder(num, node->left);                               // we want to look in left tree
    }




    /////////////////////////
    // INSERTION FUNCTIONS //
    /////////////////////////


    Node* insertNodeHelp(Node* key, Node* node) {                               /// HELPER FUNCTION FOR insertNode(), INSERTS key INTO node != nullptr
                                                                                /// returns the inserted node, or nullptr if it fails

        if (node->id == key->id) return nullptr;                                // insertion failure (duplicate)
        else if (node->id > key->id) {                                          // look on the left

            if (node->left == nullptr) return node->left = key;                 //     we're done!
            else return insertNodeHelp(key, node->left);                        //     recurse left

        } else {                                                                // look on the right

            if (node->right == nullptr) return node->right = key;               //     we're done!
            else return insertNodeHelp(key, node->right);                       //     recurse right

        }
    }


    pair<bool,Node*> insertNode(Node* key, Node* node) {                        /// INSERTS key INTO node AND BALANCES & UPDATES AFFECTED HEIGHTS
                                                                                /// returns a pair (1 if successful or 0 if not, the root)

        Node* ret;                                                              // returned Node* from helper, or the root if tree is initially empty
        if (node == nullptr) ret = (node = key);                                // tree is empty, put node at the root
        else ret = insertNodeHelp(key, node);                                   // tree is not empty, call helper function

        if (ret == nullptr) return make_pair(0,node);
        else {

            pair<Node*,Node*> found = searchAndBalanceHelper(key,node);         // finds the newly inserted node, while balancing and updating heights
            Node* chk = found.first;
            node = found.second;
            assert(chk == ret);                                                 // if this assertion fails, then at least one of the search or insertion functions broke
            return make_pair(1,node);

        }
    }


    pair<bool,Node*> insertNode(int id, Node* node) {              /// Overloads the above function, input node by values instead
        return insertNode(new Node(id), node);
    }

    void ins(int id) {
        tree = insertNode(id, tree).second;
    }



    ///////////////////////
    // REMOVAL FUNCTIONS //
    ///////////////////////


    pair<bool,Node*> removeNodeHelper(Node* found, Node* node) {                /// Helper TRIES TO REMOVE key FROM node
                                                                                /// returns a pair (successful?, new root)

        if (found==nullptr) return make_pair(0,node);                           // failure

        int deg = 0 + ((found->left != nullptr)?1:0)                            // count the children (outdegree) of found
                    + ((found->right != nullptr)?2:0);
                                                                                // hashed as follows: 0 - leaf,
                                                                                // 1 - left only, 2 - right only, 3 - both

        int id = found->id;                                                     // get ids for comparisons later on
        int parentId;
        Node* parent = findParent(id, node);                                    // find the parent
        if (parent == nullptr) parentId = -69;                                  // gotta check for nullptr too
        else parentId = parent->id;

        pair<bool,Node*> ret;                                                   // the output value

        if (deg == 0) {                                                         // this is a leaf

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = nullptr;                        // key is parent's left child
                else parent->right = nullptr;                                   // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,nullptr);                                     // there is no parent and the tree is empty
            }

        }

        if (deg == 1) {

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = found->left;                    // key is parent's left child
                else parent->right = found->left;                               // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,node->left);                                  // there is no parent, return left child as root
            }

        }

        if (deg == 2) {

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = found->right;                   // key is parent's left child
                else parent->right = found->right;                              // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,node->right);                                 // there is no parent, return left child as root
            }

        }

        if (deg == 3) {


            Node* successor = found->right;                                     // look for the inorder successor
            Node* parentOfSuccessor = found;                                    // we will have to disconnect the successor from its parent

            while (successor->left != nullptr) {                                // dig left until we can't go further

                parentOfSuccessor = successor;
                successor = successor->left;

            }

            if (successor != found->right) {                                    // cut from parent if necessary

                parentOfSuccessor->left = successor->right;
                successor->right = found->right;                                // link right part of tree to successor

            }

            successor->left = found->left;                                      // link left part of tree to successor

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = successor;                      // key is parent's left child
                else parent->right = successor;                                 // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,successor);                                   // there is no parent, return successor as root
            }

        }

        ret.second = searchAndBalanceHelper(id+1,ret.second).second;

        return ret;

    }


    pair<bool,Node*> removeNode(Node* key, Node* node) {                        /// TRIES TO REMOVE key ID FROM node
                                                                                /// returns same as above
        pair<Node*,Node*> ret = searchAndBalanceHelper(key, node);              // look for node
        Node* found = ret.first;                                                // update values
        node = ret.second;
        return removeNodeHelper(found, node);
    }


    pair<bool,Node*> removeNode(int idx, Node* node) {                          /// TRIES TO REMOVE nth INDEX FROM node INORDER, 0-INDEXED
                                                                                /// returns same as above
        Node* key = findInorder(idx,node);                                      // call helper
        if (key == nullptr) return make_pair(false,node);                       // key doesn't exist
        else return removeNodeHelper(key,node);                                 // found it, keep removing
    }




    ////////////////
    // TRAVERSALS //
    ////////////////


    void printInorderHelperL(Node* node) {                                      /// Helper for inorder that prints commas after names

        if (node!=nullptr) {

            printInorderHelperL(node->left);
            cout << node->id << ", ";
            printInorderHelperL(node->right);

        }

    }


    void printInorderHelperR(Node* node) {                                      /// Helper for inorder that prints commas before names

        if (node!=nullptr) {

            printInorderHelperR(node->left);
            cout << ", " << node->id;
            printInorderHelperR(node->right);

        }

    }


    void printInorder(Node* node) {                                             /// Prints a ,-delimited inorder traversal

        if (node!=nullptr) {

            printInorderHelperL(node->left);
            cout << node->id;
            printInorderHelperR(node->right);

        }

        cout << endl;

    }

};

// piecewise

#include <bits/stdc++.h>
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


// prime checker
// witness
bool witness(LL a, ll d, ll m) {
    LL x = LL::exp(a,m);
    if (x==LL(1)) return 1;
    F0(r,d) {
        if (x==LL(-1)) return 1;
        x = x*x;
    }
    return 0;
}

// O(log^3 n) test
bool isPrime(ll x) {
    if (x < T6) {
        int j = 2;
        while (j*j <= x) {
            if (x%j==0) return 0;
            ++j;
        }
        return 1;
    }
    ll d = 0;
    ll m = 0;
    ll y = x;
    ll cur = LL::m;
    LL::m = x;
    bool ret = 1;
    while (y>>=1) {
        ++d; if (y&1) break;
    }
    m = y;
    if (x < 1e12) {
        ret = witness(2,d,m)
            && witness(13,d,m)
            && witness(23,d,m)
            && witness(1662803,d,m);
    } else {
        ret = witness(2,d,m)
            && witness(3,d,m)
            && witness(5,d,m)
            && witness(7,d,m)
            && witness(11,d,m)
            && witness(13,d,m)
            && witness(17,d,m)
            && witness(19,d,m)
            && witness(23,d,m)
            && witness(29,d,m)
            && witness(31,d,m)
            && witness(37,d,m)
            && witness(41,d,m);
    }
    LL::m = cur;
    return ret;
}


// scc (1515G)

#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define H 200100
#define INF 5000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,LL> edge;

int N,M,Q;
bool V[H];
bool U[H];
set<edge> adj[H];
set<edge> rev[H];
vector<set<int>> comp;
int par[H];
LL ret[H];
LL ans[H];
int cv; bool fin; int nc=0;

LL gcd(LL a, LL b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

stack<int> ord;
// Detect all connected pieces
void dfs1(int v) {
    U[v] = false;
    for (edge u : adj[v]) {
        if (U[u.f]) dfs1(u.f);
    }
    ord.p(v);
}

void dfs2(int v) {
    U[v] = false;
    comp[nc].ins(v);
    for (edge u : rev[v]) {
        if (U[u.f]) dfs2(u.f);
    }
}

void tr(int v) {
    if (V[v]) {
        //cout << "penis" << v << endl;
        V[v]=false;
        for (edge e : adj[v]) {
            if (V[e.f]) {
                ret[e.f]=ret[v]+e.s;
                tr(e.f);
            }
        }
    }
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; i++) {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        LL ww = (LL)w;
        adj[u].ins(mp(v,ww));
        rev[v].ins(mp(u,ww));
    }
    for (int i = 1; i <= N; i++) {
        V[i]=false;
        U[i]=true;
        ans[i]=0;
    }
    for (int i = 1; i <= N; i++) {
        if (U[i]) {
            dfs1(i);
        }
        //V[i] = false; // oh no
    }
    //cout << "HI\n";
    for (int i = 1; i <= N; i++) U[i]=true;
    // the constant factor is stupid
    //cout << ord.size() << endl;
    while (ord.size()) {
        int v = ord.t(); ord.pop();
        //cout << v << endl;
        if (U[v]) { comp.pb(set<int>()); dfs2(v); nc++;
        }
    }
    //cout << "A" << endl;
    for (set<int> st : comp) {
        set<int>::iterator it = st.begin();
        for (int i : st) {
            V[i] = true; par[i]=*it;
            //cout << i << " ";
        }
        //cout << endl;
        ret[*it]=0;
        tr(*it);
        //cout << ret[*it] << endl;
        for (int i : st) V[i] = false;
    }
    for (int u = 1; u <= N; u++) {
        for (edge e : adj[u]) {
            if (par[e.f]==par[u]) {
                LL d = abs(ret[u]+e.s-ret[e.f]);
                ans[par[u]]=gcd(ans[par[u]],d);
            }
        }
    }
    scanf("%d",&Q);
    while (Q--) {
        int v,s,t;
        LL S,T;
        scanf("%d%d%d",&v,&s,&t);
        S=(LL)s;T=(LL)t;
        LL z = ans[par[v]];
        z = gcd(z,t);
        if (s%z==0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}


// segment tree

int P2[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

template <typename T>
struct ST { // implicit 1D segment tree
    T val;
    ST *L, *R;
    int lv;

    ST(int lvv = -1, T vall = 0, ST* le = nullptr, ST* ri = nullptr) : lv(lvv),val(vall),L(le),R(ri) { }

    T push() {
        return val = ((L == nullptr)?0:L->val) + ((R == nullptr)?0:R->val);
    }

    void update(int n, T vall, bool add = 0) { // Point update (boolean add determines behavior: 0 = set, 1 = add)
        if (lv == -1) val = vall + val*add;
        else {
            if (P2[lv]&n) {
                if (R == nullptr) R = new ST<T>(lv-1);
                R->update(n,vall,add);
            }
            else {
                if (L == nullptr) L = new ST<T>(lv-1);
                L->update(n,vall,add);
            }
            push();
        }
    }
    void display() {
        F0(i,lv+1) cout << '\t'; cout << val << endl;
        if (L!=nullptr) L->display();
        if (R!=nullptr) R->display();
    }
    T query(int l, int r, int pos = 0) { // Range query on the interval [l,r)
        if (l > r) return 0;
        int p0, p1, p2;
        if (lv == -1) p0 = pos, p2 = p0+1;
        else p0 = pos,p1 = pos+P2[lv],p2 = p1+P2[lv];
        if (l <= p0 && r >= p2) return val;
        if (l >= p2 || r <= p0) return 0;
        T tot = 0;
        if (l < p1) {
            if (L == nullptr) L = new ST<T>(lv-1);
            else tot += L->query(l,r,p0);
        }
        if (r > p1) {
            if (R == nullptr) R = new ST<T>(lv-1);
            else tot += R->query(l,r,p1);
        }
        return tot;
    }
};

template<typename T>
struct ST2D {
    ST<T>* val;
    ST2D *L, *R;
    int lv, lu;
    ST2D(int lvv = -1, int luu = -1) : lv(lvv),lu(luu) {
        val = new ST<T>(luu);
        L = nullptr; R = nullptr;
    }

    void update(int n, int m, T vall) { // Point update (can only add)
        val->update(m,vall,1);
        if (lv >= 0) {
            if (P2[lv]&n) {
                if (R == nullptr) R = new ST2D<T>(lv-1,lu);
                R->update(n,m,vall);
            }
            else {
                if (L == nullptr) L = new ST2D<T>(lv-1,lu);
                L->update(n,m,vall);
            }
        }
    }

    T query(int vl, int vr, int l, int r, int pos = 0) { // Range query on the interval [lv, vr) x [l, r)
        if (vl > vr) return 0;
        int p0, p1, p2;
        if (lv == -1) p0 = pos, p2 = p0+1;
        else p0 = pos,p1 = pos+P2[lv],p2 = p1+P2[lv];
        if (vl <= p0 && vr >= p2) return val->query(l,r);
        if (vl >= p2 || vr <= p0) return 0;
        T tot = 0;
        if (vl < p1) {
            if (L == nullptr) L = new ST2D<T>(lv-1,lu);
            else tot += L->query(vl,vr,l,r,p0);
        }
        if (vr > p1) {
            if (R == nullptr) R = new ST2D<T>(lv-1,lu);
            else tot += R->query(vl,vr,l,r,p1);
        }
        return tot;
    }
};


template <typename T>
struct SST {
};

struct IST2D {
    struct Hash {
        size_t operator()(pii const& a) const {
            int seed = a.f+a.s*2069;
            return seed;
        }
    };

    unordered_map<pii,int,Hash> tree; // what the fk is this
    int B,N; // biggest interval is from [0,2^B - 1]

    IST2D(int b) {
        B = b; N = 1<<B;
        tree = unordered_map<pii,int,Hash>(); // yes. just yes
    }

    // update (x,y) to value v
    void update(int x, int y, int v) {
        x+=N;y+=N;
        int diff = v-tree[{x,y}];
        for (int cx=x;cx>0;cx>>=1) for(int cy=y;cy>0;cy>>=1)
            tree[{cx,cy}] += diff;
    }

    // compute the sum of [x1, x2] . [y1, y2]
    int query(int x1, int x2, int y1, int y2) {
        vector<int> X,Y;
        x1+=N;x2+=N;y1+=N;y2+=N;
        int ret = 0;
        for (int cx1=x1,cx2=x2;cx1<=cx2;cx1=(cx1+1)>>1,cx2=(cx2-1)>>1) {
            if (cx1&1) for (int cy1=y1,cy2=y2;cy1<=cy2;cy1=(cy1+1)>>1,cy2=(cy2-1)>>1) {
                if (cy1&1) ret += tree[{cx1,cy1}];
                if (!(cy2&1)) ret += tree[{cx1,cy2}];
            }
            if (!(cx2&1)) for (int cy1=y1,cy2=y2;cy1<=cy2;cy1=(cy1+1)>>1,cy2=(cy2-1)>>1) {
                if (cy1&1) ret += tree[{cx2,cy1}];
                if (!(cy2&1)) ret += tree[{cx2,cy2}];
            }
        }
        return ret;
    }
};


struct SegTree {

    ll F(ll a, ll b) {
        return min(a,b);
    }

	int sz;
	vector<ll> ST;

	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++)
            ST.pb(LNF); // i may have to change this value
    }

	void lift(int idx) {
	    ST[idx] = F(ST[2*idx],ST[2*idx+1]);
    }

	void update(int idx, ll x) {
		idx += sz;
		ST[idx] = x;
		idx >>= 1;
		while (idx) {
            lift(idx); idx >>= 1;
		}
	}

	ll query(int lp, int rp) {
		ll a = LNF; // i may have to change this value
		ll b = LNF; // i may have to change this value
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F(a,ST[lp++]);
			if (rp&1) b = F(ST[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F(a,b);
	}

} ST;


// 1D template implicit segtree

int P2[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

template <typename T>
struct ST { // implicit 1D segment tree
    T val;
    ST *L, *R;
    int lv;

    ST(int lvv = -1, T vall = 0, ST* le = nullptr, ST* ri = nullptr) : lv(lvv),val(vall),L(le),R(ri) { }

    T push() {
        return val = ((L == nullptr)?0:L->val) + ((R == nullptr)?0:R->val);
    }

    void update(int n, T vall, bool add = 0) { // Point update (boolean add determines behavior: 0 = set, 1 = add)
        if (lv == -1) val = vall + val*add;
        else {
            if (P2[lv]&n) {
                if (R == nullptr) R = new ST<T>(lv-1);
                R->update(n,vall,add);
            }
            else {
                if (L == nullptr) L = new ST<T>(lv-1);
                L->update(n,vall,add);
            }
            push();
        }
    }
    void display() {
        F0(i,lv+1) cout << '\t'; cout << val << endl;
        if (L!=nullptr) L->display();
        if (R!=nullptr) R->display();
    }
    T query(int l, int r, int pos = 0) { // Range query on the interval [l,r)
        if (l > r) return 0;
        int p0, p1, p2;
        if (lv == -1) p0 = pos, p2 = p0+1;
        else p0 = pos,p1 = pos+P2[lv],p2 = p1+P2[lv];
        if (l <= p0 && r >= p2) return val;
        if (l >= p2 || r <= p0) return 0;
        T tot = 0;
        if (l < p1) {
            if (L == nullptr) L = new ST<T>(lv-1);
            else tot += L->query(l,r,p0);
        }
        if (r > p1) {
            if (R == nullptr) R = new ST<T>(lv-1);
            else tot += R->query(l,r,p1);
        }
        return tot;
    }
};

template<typename T>
struct ST2D {
    ST<T>* val;
    ST2D *L, *R;
    int lv, lu;
    ST2D(int lvv = -1, int luu = -1) : lv(lvv),lu(luu) {
        val = new ST<T>(luu);
        L = nullptr; R = nullptr;
    }

    void update(int n, int m, T vall) { // Point update (can only add)
        val->update(m,vall,1);
        if (lv >= 0) {
            if (P2[lv]&n) {
                if (R == nullptr) R = new ST2D<T>(lv-1,lu);
                R->update(n,m,vall);
            }
            else {
                if (L == nullptr) L = new ST2D<T>(lv-1,lu);
                L->update(n,m,vall);
            }
        }
    }

    T query(int vl, int vr, int l, int r, int pos = 0) { // Range query on the interval [lv, vr) x [l, r)
        if (vl > vr) return 0;
        int p0, p1, p2;
        if (lv == -1) p0 = pos, p2 = p0+1;
        else p0 = pos,p1 = pos+P2[lv],p2 = p1+P2[lv];
        if (vl <= p0 && vr >= p2) return val->query(l,r);
        if (vl >= p2 || vr <= p0) return 0;
        T tot = 0;
        if (vl < p1) {
            if (L == nullptr) L = new ST2D<T>(lv-1,lu);
            else tot += L->query(vl,vr,l,r,p0);
        }
        if (vr > p1) {
            if (R == nullptr) R = new ST2D<T>(lv-1,lu);
            else tot += R->query(vl,vr,l,r,p1);
        }
        return tot;
    }
};




// seg tree but stronger
struct Cheese {

    ll F(ll a, ll b) {
        return a+b;
    }

    int sz;
    vector<ll> ST;
    vector<ll> lazy;
    void start(int n) {
        sz = n;
        for (int i = 0; i < 4*n; i++) { ST.pb(0); lazy.pb(0); }
    }

    void build(ll * A, int idx, int b, int e) {
        lazy[idx]=0;
        if(b == e) {
            ST[idx] = A[b];
        } else {
            int mid = (b + e) / 2;
            build(A, 2*idx, b, mid);
            build(A, 2*idx+1, mid+1, e);
            ST[idx] = F(ST[2*idx],ST[2*idx+1]);
        }
    }
    void build(ll * A) { build(A, 1, 0, sz-1); }

    void update(int idx, int b, int e, int l, int r, ll val) {
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if(b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if ((b > e) || (b > r) || (e < l)) return;
        if ((b >= l) && (e <= r)) {
            ST[idx] += val;
            if (b != e) {
                lazy[idx*2] += val;
                lazy[idx*2+1] += val;
            }
            return;
        }
        int mid = (b + e) / 2;
        update(idx*2, b, mid, l, r, val);
        update(idx*2 + 1, mid + 1, e, l, r, val);
        ST[idx] = F(ST[idx*2],ST[idx*2+1]);
    }
    void update(int l, int r, ll val) { update(1,0,sz-1,l,r,val); }

    ll query(int idx, int b, int e, int l, int r) {
        if ((b > e) || (b > r) || (e < l)) return 0;
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if (b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(b >= l and e <= r) return ST[idx];
        int mid = (b + e) / 2;
        ll p1 = query(idx*2, b, mid, l, r);
        ll p2 = query(idx*2 + 1, mid + 1, e, l, r);
        return F(p1,p2);
    }
    ll query(int l, int r) { return query(1,0,sz-1,l,r); }

} ST;


// seg tree but STRONGERERERERERER

// H should be 8N

int seg[H];
int lazy[H];
bool mark[H];


struct Cheese {

    ll F(ll a, ll b) {
        return a+b;
    }

    vector<int> seg;
    vector<int> lazy;
    vector<int> mark;

    int n;

    Cheese(int n){start(n);}

    void start(int n) {
        this->n = n;
        for (int i = 0; i < 4*n+5; i++) { seg.pb(0);lazy.pb(0);mark.pb(0); }
    }

    void push(int v, int tl, int tr) {
        if (mark[v]) {
            lazy[2 * v] = lazy[v];
            lazy[2 * v + 1] = lazy[v];
            mark[2 * v] = true;
            mark[2 * v + 1] = true;
            int tm = (tl + tr) / 2;
            seg[2 * v] = lazy[2 * v] * (tm - tl + 1);
            seg[2 * v + 1] = lazy[2 * v + 1] * (tr - tm);
            mark[v] = false;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int rep) {
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] = rep;
            mark[v] = true;
            seg[v] = rep * (tr - tl + 1);
        }
        else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), rep);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, rep);
            seg[v] = seg[2 * v + 1] + seg[2 * v];
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        push(v, tl, tr);
        if (l <= tl && r >= tr) return seg[v];
        int tm = (tl + tr) / 2;
        return (query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int l, int r, int rep) { update(1, 0, n-1, l, r, rep); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }


};


// STRONGEST 1-D SEGMENT TREE

ll P2[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

template <typename T>
struct ST { // implicit 1D segment tree
    T val, add, mult;
    ST *L, *R;
    int lv;

    ST(int lvv = 0, T vall = 0, ST* le = nullptr, ST* ri = nullptr) : lv(lvv),val(vall),L(le),R(ri),add(0),mult(1) {}

    void push() {
        if (!(add == 0 && mult == 1)) {
            if (L == nullptr) L = new ST<T>(lv-1);
            if (R == nullptr) R = new ST<T>(lv-1);
            L->val*=mult; L->val+=add*P2[lv-1];
            R->val*=mult; R->val+=add*P2[lv-1];
            L->mult*=mult;
            L->add*=mult; L->add+=add;
            R->mult*=mult;
            R->add*=mult; R->add+=add;
            add=0; mult=1;
        }
    }

    // Apply f(x) = a + mx to all values in range [l,r]
    void update(ll tl, ll tr, ll l, ll r, T a, T m) {
        if (l > r) return;
        if (l == tl && r == tr) {
            val = a * (tr - tl + 1) + val * m;
            mult *= m;
            add *= m; add += a;
        }
        else {
            if (L == nullptr) L = new ST<T>(lv-1);
            if (R == nullptr) R = new ST<T>(lv-1);
            push();
            ll tm = (tl + tr) / 2;
            L->update(tl, tm, l, min(r, tm), a, m);
            R->update(tm + 1, tr, max(l, tm + 1), r, a, m);
            val = L->val + R->val;
        }
    }
    T query(ll tl, ll tr, ll l, ll r) {
        if (l > r) return 0;
        push();
        if (l <= tl && r >= tr) return val;
        ll tm = (tl + tr) / 2;
        if (L == nullptr) L = new ST<T>(lv-1);
        if (R == nullptr) R = new ST<T>(lv-1);
        return L->query(tl, tm, l, min(r, tm))
                +R->query(tm + 1, tr, max(l, tm + 1), r);
    }
    void update(ll l, ll r, T a, T m) { update(0, P2[lv]-1, l, r, a, m); }
    LL query(ll l, ll r) { return query(0, P2[lv]-1, l, r); }

    void display(int pos = 1) {
        cout << pos << ": " << val << " | " << add << " + " << mult << "x" << endl;
        if (L!=nullptr) L->display(2*pos);
        if (R!=nullptr) R->display(2*pos+1);
    }
};



// sod

int red(int x) { if (x) return red(x>>1)+(x&1); return 0; }


// topsort

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int N; // Number of nodes
vector<int> adj[100000], TS; // Assume that this graph is a DAG
bool V[100000];

void dfs(int node) {
	for (int i : adj[node]) {
		if (!V[i]) {
			V[i] = true;
			dfs(i);
		}
	}
	TS.pb(node);
}

void compute() {
	for (int i = 0; i < N; i++) {
		if (!V[i]) {
			V[i] = true;
			dfs(i);
		}
	}
	reverse(begin(TS),end(TS));
	// The vector `TS` is now topologically sorted
}

int main() {
	int M; cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
	}
	compute();
	vector<int> idx(N);
	for (int i = 1; i <= N; i++) idx[TS[i]] = i;
	for (int i = 1; i <= N; i++) for (int j : adj[i]) if (idx[j] <= idx[i]) {
		cout << "IMPOSSIBLE\n"; // topological sort wasn't valid
		return 0;
	}
	for (int i : TS) cout << i + 1 << " ";
	cout << "\n";
}


// topsort 2

vector<int> adj[H];
vector<int> rev[H];
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topsort() {
    visited.assign(H, false);
    ans.clear();
    for (int i = 1; i <= N; ++i) {
        if (!visited[i])
            dfs(i);
    }
    //reverse(ans.begin(), ans.end());
}


// topsort - Kahn (potential PQ implementation)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100000;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> graph[MAX_N];
	int indegree[MAX_N]{};
	queue<int> q;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		indegree[b - 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		// locate the nodes with indegree 0 and push them into the queue
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	vector<int> order;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		// add the current node to the order
		order.push_back(curr);
		for (int next : graph[curr])
		{
			// remove the current node from the graph
			indegree[next]--;
			// push any new nodes with indegree 0 into the queue
			if (indegree[next] == 0)
			{
				q.push(next);
			}
		}
	}
	// if there isn't a valid topological sorting
	if (order.size() != n)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << order[0] + 1;
	for (int i = 1; i < n; i++)
	{
		cout << " " << order[i] + 1;
	}
	cout << endl;
	return 0;
}


// yggdrasil, the world tree

struct Cheese {

    pii F(pii a, pii b) {
        return {a.f+b.f,max(a.s+b.f,b.s)};
    }

    vector<pii> seg;
    vector<int> lazy;

    int n;

    Cheese(int n){start(n);}

    void start(int n) {
        this->n = n;
        for (int i = 0; i < 8*n+3; i++) { seg.pb({-1,-1});lazy.pb(-inf);}
        update(0,n-1,-1);
    }

    void push(int v, int tl, int tr) {
        if (lazy[v] != -inf) {
            lazy[2 * v] = lazy[v];
            lazy[2 * v + 1] = lazy[v];
            int tm = (tl + tr) / 2;
            seg[2 * v] = {(tm-tl+1)*lazy[2 * v],lazy[2 * v]};
            seg[2 * v + 1] = {(tr-tm)*lazy[2 * v + 1],lazy[2 * v + 1]};
            lazy[v] = -inf;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int rep) {
        assert(abs(rep)<T6);
        //cout << v << " " << tl << " " << tr << " " << l << " " << r << " " << rep << endl;
        if (l > r) return;
        if (l == tl && r == tr) {
            //cout << "A" << endl;
            lazy[v] = rep;
            seg[v] = {(tr-tl+1)*lazy[v],lazy[v]};
        //ds(seg[v]);
        } else {
            //cout << "B" << endl;
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), rep);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, rep);
            seg[v] = F(seg[2 * v],seg[2 * v + 1]);
        }
    }
    pii query(int v, int tl, int tr, int l, int r) {
        if(debug)cout << "query " << v << " " << tl << " " << tr << " " << l << " " << r << endl;
        //if(debug)ds(seg);
        if (l > r) return {0,-99999999};
        push(v, tl, tr);
        if (l <= tl && r >= tr) return seg[v];
        int tm = (tl + tr) / 2;
        return F(query(2 * v, tl, tm, l, min(r, tm)),
                 query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int l, int r, int rep) { update(1, 0, n-1, l, r, rep); }
    void update(int rep) { update(1, 0, n-1, 0, n-1, rep); }
    pii query(int l, int r) { return query(1, 0, n-1, l, r); }


};

struct Tree {

    vector<vector<int>> adj;
    vector<Cheese> hld;
    vector<int> paths;
    vector<int> children;
    vector<pii> bruh;
    vector<int> euler;
    vector<int> times;
    vector<int> head;

    int sz,rt,lg;
    int timer;
    vector<int> depth;
    vector<vector<int>> up;

    Tree(int _sz, const vector<vector<int>>& _adj, int _rt = 1) :
        sz(_sz), adj(_adj), rt(_rt) {lg=ceil(log2(_sz)); build(_rt);}
    vector<bool> V;
    void dfs(int& t, int v, int x, int p, const vector<vector<int>>& adj, int h) {
        V[v]=1;
        depth[v]=x;
        times[v]=timer++;
        head[v]=h;
        bruh[v].f=t++;
        up[v].pb(p);
        F1(i,lg) up[v].pb(up[up[v][i-1]][i-1]);
        bool first = 1;
        euler.pb(v);
        FE(u,adj[v]) if (!V[u]) {
            int nh = head[v];
            if (!first || children[u]<children[v]/2) {
                nh = timer;
                paths.pb(timer);
            }
            dfs(t,u,x+1,v,adj,nh);
            first = 0;
        }
        bruh[v].s=t++;
    }
    pii F(pii a, pii b) {
        return {a.f+b.f,max(a.s+b.f,b.s)};
    }
    vector<int> lazy;
    vector<bool> mark;
    void push(int v, int tl, int tr) {
        if (mark[v]) {
            lazy[2 * v] = lazy[v];
            lazy[2 * v + 1] = lazy[v];
            mark[2 * v] = true;
            mark[2 * v + 1] = true;
            int tm = (tl + tr) / 2;
            if (tl==tm) {hld[tl].update(lazy[v]); mark[2*v]=false;}
            if (tm+1==tr) {hld[tm+1].update(lazy[v]); mark[2*v+1]=false;}
            mark[v] = false;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int rep) {
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] = rep;
            mark[v] = true;
            if (tl==tr) hld[l].update(rep);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), rep);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, rep);
        }
    }
    void pushdown(int v, int tl, int tr, int l, int r) {
        if(debug)cout << "pushdown(" << v << "," << tl << "," << tr << "," << l << "," << r << ")" << endl;
        if (l > r) return;
        push(v, tl, tr);
        if (l <= tl && r >= tr) return;
        int tm = (tl + tr) / 2;
        pushdown(2 * v, tl, tm, l, min(r, tm));
        pushdown(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return;
    }
    void pushdown(int l, int r) {
        pushdown(1,0,hld.size()-1,l,r);
    }
    void update(int l, int r, int rep) {
        l=times[l];r=times[r];
        int L = nle(paths,l)-1;
        int R = nle(paths,r)-1;
        int st = paths[L];
        int ed = paths[R];
        if(debug)cout << "update(" << l << "," << r << "," << rep << "): " << L << " " << R << " " << st << " " << ed << endl;
        assert(L<=R);
        pushdown(L,L);
        pushdown(R,R);
        if (L==R) {
            if(debug)cout << L << " " << l-st << " " << r-ed << " " << rep << endl;
            hld[L].update(l-st,r-ed,rep);
        } else {
            hld[L].update(l-st,paths[L+1]-st-1,rep);
            hld[R].update(0,r-ed,rep);
            update(1,0,hld.size()-1,L+1,R-1,rep);
        }
    }
    void update(int v, int rep) {
        int c = children[v];
        v=times[v];
        if(debug)cout<<v<<" " <<c<<endl;
        if(debug)cout << v+1 << " " << v+c << endl;
        if (c) update(euler[v+1],euler[v+c],rep);
    }
    pii query(int v) {
        int t = head[v];
        int pr = times[v];
        pii tot = {0,-99999999};
        while (true) {
            int T = nle(paths,t)-1;
            pushdown(T,T);
            if(debug)cout << "query(" << v << "): " << t << " " << pr << " ";
            if(debug)ds(hld[T].query(0,pr-t));
            tot=F(hld[T].query(0,pr-t),tot);
            if(debug)ds(tot);
            if(debug)cout<<endl;
            if (t==0) break;
            pr=times[up[euler[t]][0]];
            t=head[euler[pr]];
        }
        return tot;
    }
    pii gett(int v) {
        int t = times[v];
        int T = nle(paths,t)-1;
        pushdown(T,T);
        return hld[T].query(t-paths[T],t-paths[T]);
    }
    int get(int v) {
        return gett(v).f;
    }
    void sortChildren(int _rt=1, int p=1) {
        children[_rt]=0;
        vector<int> tmp;
        FE(u,adj[_rt]) if (u!=p) {
            sortChildren(u,_rt);
            children[_rt]+=children[u]+1;
            tmp.pb(u);
        }
        auto cmp = [&](int const& s1, int const& s2) -> bool {
           return children[s1]>children[s2];
        };
        srtc(tmp,cmp);
        adj[_rt]=tmp;
        if (_rt!=rt) adj[_rt].pb(p);
    }
    void build(int rt) {
        V.clear(); depth.clear(); bruh.clear(); up.clear(); children.clear();
        hld.clear(); paths.clear(); euler.clear(); head.clear();
        F0(i,sz+1) { V.pb(0); bruh.pb({-1,-1}); up.pb(vector<int>()); depth.pb(0); children.pb(0);}
        times = vector<int>(sz+1);
        head = vector<int>(sz+1);
        sortChildren();
        paths.pb(0);
        timer=0;
        int t = 0; dfs(t,rt,0,rt,adj,0);
        paths.pb(timer);
        F0(i,paths.size()-1) {
            hld.pb(Cheese(paths[i+1]-paths[i]));
        }
        lazy.clear(); mark.clear();
        F0(i,paths.size()*8+3) {lazy.pb(-1); mark.pb(0);}
    }
    void dump() {
        cout << "EVERYTHING" << endl;
        //cout << "V "; ds(V);
        //cout << "adj "; ds(adj);
        //cout << "depth "; ds(depth);
        //cout << "bruh "; ds(bruh);
        //cout << "up "; ds(up);
        cout << "children "; ds(children);
        cout << "H L D" << endl;
        F0(i,paths.size()-1) {
            cout << paths[i] << " path" << endl;
            Fr(j,paths[i],paths[i+1]) ds(euler[j]); cout << endl;
            ds(hld[i].seg);
        }
        F1(i,sz) {
            cout << i << endl;
            ds(get(i)); cout << endl;
        }
        cout << endl;
        cout << "paths "; ds(paths);
        cout << "euler "; ds(euler);
        cout << "head "; ds(head);
        cout << "times "; ds(times);
        //cout << "--------------" << endl;
    }
    bool is_ancestor(int u, int v) { return bruh[u].f <= bruh[v].f && bruh[u].s >= bruh[v].s; }
    int query(int v, int u) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = lg; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int v, int u) { return depth[v]+depth[u]-(depth[query(v,u)]<<1); }
    int walk(int v, int u, int d) {
        int dv = depth[v];
        int da = depth[query(v,u)];
        int du = depth[u];
        int lt = dv+du-(da<<1);
        if (lt<=d) return u;
        if (d<dv-da) {
            R0(x,lg+1) if (d&(1<<x)) {
                d^=1<<x; v=up[v][x];
            }
        } else {
            d=lt-d; v=u; R0(x,lg+1) if (d&(1<<x)) {
                d^=1<<x; v=up[v][x];
            }
        }
        return v;
    }
};




*/
