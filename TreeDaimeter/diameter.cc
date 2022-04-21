#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

/*
 * get input, and construct the graph.
 * for convenience, we move index of nodes form range [1, n] to [0, n-1]
 */
void Input (std::vector<std::vector<int64_t>& g) {
    int64_t n_vert, x, y;
    std::cin >> n_vert;
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
        Node_idx i = q.front(); q.pop();
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

Node_idx diameter(Graph &g) {
    Dist_list d_list(g.size());
    DFS(g, 0, d_list);
    Node_idx next_idx = distance(d_list.begin(), max_element(d_list.begin(), d_list.end()));
    DFS(g, next_idx, d_list);
    return *(max_element(d_list.begin(),d_list.end()));
}

int main() {
    std::vector<std::vector<int64_t>> g;
    input(g);
    cout << diameter(g);
}
