#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

using Graph = vector<vector<int> >;
using Node_idx = int;
using Dist_list = vector<int>;


/*
 * get input, and construct the graph.
 * for convenience, we move index of node form range [1, n] to [0, n-1]
 */
void input(Graph &g) {
    int n_vert, x, y;
    cin >> n_vert;
    g = Graph(n_vert);

    while(cin >> x >> y) {
        g[--x].push_back(--y); // move node range from [1, n] to [0, n-1]
        g[y].push_back(x);
    }
}

void DFS(Graph &g, Node_idx idx, Dist_list &d_list) {
    int n_vert = g.size();
    vector<bool> used(n_vert, false);
    queue<Node_idx> q = queue<Node_idx>();

    used[idx] = true;
    d_list[idx] = 0;
    q.push(idx);

    while(!q.empty()) {
        Node_idx i = q.front();
	q.pop();
        int i_dist = d_list[i];
        for(int j: g[i]) {
            if(!used[j]) {
                used[j] = true;
                d_list[j] = i_dist + 1;
                q.push(j);
            }
        } 
    }
}

Dist_list distances(Graph &g) {
    int n_vert = g.size();

    Dist_list d_list(n_vert),
    	      d_list1(n_vert);

    DFS(g, 0, d_list);
    Node_idx next_idx = distance(d_list.begin(), max_element(d_list.begin(), d_list.end()));

    DFS(g, next_idx, d_list);
    next_idx = distance(d_list.begin(), max_element(d_list.begin(), d_list.end()));

    DFS(g, next_idx, d_list1);

    for(int i = 0; i < n_vert; ++i) {
        d_list[i] = max(d_list[i], d_list1[i]);
    }

    return d_list;
}

int main() {
    Graph g;
    input(g);

    for(auto x: distances(g)) cout<<x<<" ";
}
