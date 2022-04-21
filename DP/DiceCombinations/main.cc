#include <iostream>
#include <cmath>
using namespace std;    

int DP(int n, int divisor) {
    int f[n + 1];
    
    f[0] = 1;

    for(int i = 1; i <= n; ++i) {
        int range = min(6, i);
	int temp = 0;
	for(int j = 1; j <= range; ++j)
	    temp = (f[i-j] + temp) % divisor;
	f[i] = temp;
    }

    return f[n];
}

int main() {
    int n;
    cin >> n;

    int divisor = pow(10, 9) + 7;
    cout << DP(n, divisor);
} 
