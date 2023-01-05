#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define val first
#define id  second

void merge(vector<pair<int,int>> &arr, int l, int r, vector<ll> &freq, int diff) {
	int leftStart = l, leftEnd = l + (r-l)/2, rightStart = leftEnd + 1, rightEnd = r;
	vector<pair<int,int>> temp(rightEnd - leftStart + 1);
	int left = leftStart, right = rightStart, k = 0;

	while(left <= leftEnd and right <= rightEnd) {

		if(arr[left].val - diff <= arr[right].val){
				freq[arr[left].id] += (rightEnd - right + 1);
				left++;
		}else {
			right++;
		}

	}

	sort(arr.begin() + leftStart,arr.begin() + rightEnd + 1);

}

void mergesort(vector<pair<int,int>> &arr, int l, int r, vector<ll> &freq, int diff) {

	if(l < r) {
		int m = l + (r-l)/2;
		mergesort(arr,l,m,freq,diff);
		mergesort(arr,m+1,r,freq,diff);
		merge(arr,l,r,freq,diff);
	}
}

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {

	int n = nums1.size();
	vector<pair<int,int>> nums(n);
	for(int i = 0; i < n; i++) nums[i] = {nums1[i] - nums2[i],i};
	// num[i] - num[j] <= diff
	// num[i] - diff <= num[j]
	// nums[j] >= nums[i] - diff

	vector<ll> freq(n,0);

	mergesort(nums,0,n-1,freq,diff);

	ll ans = 0;
	for(int i = 0; i < n; i++) ans += (ll)freq[i];
	for(int i = 0; i < n; i++) cout << freq[i] << " ";
		cout << endl;

	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> nums1(n), nums2(n);
	for(auto &i : nums1) cin>>i;
	for(auto &i : nums2) cin>>i;

	int diff;
	cin>>diff;
	cout << numberOfPairs(nums1, nums2,diff) << endl;

}