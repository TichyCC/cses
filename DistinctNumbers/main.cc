#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> input() {
    int n, temp;
    vector<int> v;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        v.push_back(temp);
    }
    return v;
}

int count(vector<int> &v) {
    set<int> s;
    for(auto x: v) s.insert(x);
    return s.size();
}

int main() {
    vector<int> v;
    v = input();

    cout << count(v);
}
