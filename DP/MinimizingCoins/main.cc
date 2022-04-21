#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;    

bool min_minus1_is_inf(int a,int b) {
    if(a == -1) return b;
    if(b == -1) return a;
    return min(a,b);
}

int DP(vector<int> &coins, int sum) {
    int f[sum + 1];

    f[0] = 0;
    
    for(auto i = 1; i <= sum; ++i) {
        int temp = -1;
	for(int coin: coins) {
	    if(i - coin < 0)
	        break;
	
	    if(f[i-coin] != -1) 
	        temp = min_minus1_is_inf(temp, f[i-coin] + 1);
	}
	f[i] = temp;
    }

    for(auto x: f) cout << x << " ";
    cout << endl;

    return f[sum];
}

int main() {
    int num_coin, sum;
    cin >> num_coin >> sum;

    vector<int> coins(num_coin);
    for(auto i = 0; i < num_coin; ++i)
        cin >> coins[i];

    sort(coins.begin(), coins.end());

    cout << DP(coins, sum);
}
