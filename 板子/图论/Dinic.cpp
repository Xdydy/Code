#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;

struct Edge {
    int from , to , cap , flow;
};
struct Dinic {
    int n , m , s , t;
    vector <Edge> edges;
    vector <int> G[max_size];
    bool vis[max_size];
    int d[max_size];
    int cur[max_size];

    void addedge ( int from , int to , int cap ) {
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS () {
        memset ( vis , 0 , sizeof(vis) );
        queue <int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front() ; Q.pop();
            for ( int i = 0 ; i < G[x].size() ; i++ ) {
                Edge& e = edges[G[x][i]];
                if ( !vis[e.to] && e.cap > e.flow ) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS ( int x , int a ) {
        if ( x == t || a == 0 ) return a;
        int flow = 0 , f;
        for ( int& i = cur[x] ; i < G[x].size() ; i++ ) {
            Edge& e = edges[G[x][i]];
            if ( d[x] + 1 == d[e.to] && ( f = DFS(e.to , min(a, e.cap-e.flow))) > 0 ) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if ( a == 0 ) break;
            }
        }
        return flow;
    }

    int Maxflow ( int s , int t ) {
        this -> s = s , this -> t = t;
        int flow = 0;
        while (BFS()) {
            memset ( cur , 0 , sizeof(cur) );
            flow += DFS(s,INF);
        }
        return flow;
    }
};