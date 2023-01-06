#include<bits/stdc++.h>
using namespace std;
#define ll long long

int minOperations(vector<int>& nums, vector<int>& numsDivide) {
	int n = nums.size();
	int m = numsDivide.size();
	int gcd = numsDivide[0];
	for(int i = 1; i < m; i++) gcd = __gcd(gcd,numsDivide[i]);
	int mn = INT_MAX;
	for(int i = 0; i < n; i++) {
		if((gcd%nums[i]) == 0) mn = min(mn, nums[i]);
	}

	if(mn == INT_MAX) return -1;
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += (nums[i] < mn);
	}


	return ans;
}	
int main() {
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 int n,m;
	 cin>>n>>m;

	 vector<int> nums(n), numsDivide(m);
	 for(auto &i : nums) cin>>i;
	 for(auto &i : numsDivide) cin>>i;

	 cout << minOperations(nums,numsDivide) << endl;

}xx