#include<bits/stdc++.h>
using namespace std;
#define ll     long long
#define mod    1000000007

string longestPrefix(string &s) {
	ll n = s.size();
	if(n == 1) return string("");

	ll pr = 31;
	ll pow = 1;

	ll pre = s[0] - 'a' + 1;
	ll suff = s[n-1] - 'a' + 1;
	ll idx = ((s[0] == s[n-1]) ? 0 : -1);
	for(int i = 1; i + 1 < n; i++) {
		int j = n-i-1;
		pow = pow*pr;
		pre = (pre + (s[i]-'a'+1)*pow)%mod;
		suff = (suff*pr)%mod;
		suff = (suff + s[j]-'a'+1)%mod;

		if(pre == suff) {
				idx = i;
		}
	}


	if(idx == -1) return string("");

	string ans;
	for(int i = 0; i <= idx; i++){
		ans.push_back(s[i]);
	}	

	return ans;
}


int main() {
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 ll n;
	 cin>>n;
	 string s;
	 cin>>s;

	cout << longestPrefix(s) << endl;

}