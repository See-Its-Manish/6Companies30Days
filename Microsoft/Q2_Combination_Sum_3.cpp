//Link   -
//Author - seeitsmanish
#include<bits/stdc++.h>
using namespace std;

#define ll long long
void FIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void f(int s, int e, int sum, int k, int n, vector<int> curr, vector<vector<int> > &ans) {
    if(sum == n and int(curr.size()) == k ) ans.push_back(curr);
    if(s > e || curr.size() > k || sum > n) return;
   

    for(int i = s; i <= e; i++){
        curr.push_back(i);
        f(i+1,e,sum + i, k, n,curr,ans);
        curr.pop_back();
    }
 }

vector< vector<int> > combinationSum3(int k, int n) {
    vector< vector<int> > ans;
    f(1,9,0,k,n,vector<int>(),ans);

    return ans; 
}


int main() {
    FIO();

    // Code Starts from here!

    int k,n;
    cin >>k >> n;

    vector< vector<int> > ans = combinationSum3(k,n);
    for(auto &vec : ans) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }


    return 0;
}