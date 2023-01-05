#include<bits/stdc++.h>
using namespace std;
#define ll long long

double nthPersonGetsNthSeat(int n) {
	
	if(n == 1) return 1;
	else return 0.5;        
}
int main() {
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 int n;
	 cin>>n;

	 cout << nthPersonGetsNthSeat(n) << endl;
}