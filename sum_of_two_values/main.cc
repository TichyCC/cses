#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void input(vector<int> &v, int &x) {
    int n, temp;
    vector<int> v;
    cin >> n >> x;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        v.push_back(temp);
    }
}

pair<int, int> count(vector<int> &v, int x) {
    map<int, int> m;
    for(int i = 0; i < v.size(); ++i) {
        m.insert(pair<int, int>(v[i], i));
    }
    for(int i = 0; i < v.size(); ++i) {
	auto it = m.find(x - v[i]);
	if(it != m.end()) return pair<int, int>(i, it->second);
    }
    return NULL
}

int main() {
    vector<int> v;
    int x;
    input(v, x);

    pair<int, int> res = count(v, x);

    if(res != NULL) cout << res.first << res.second;
    else cout << "IMPOSSIBLE";
}
