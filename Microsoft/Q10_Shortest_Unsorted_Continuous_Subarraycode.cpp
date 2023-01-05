#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();

    vector<int> aux(nums);
    sort(aux.begin(), aux.end());
    int f = -1;
    for(int i = 0; i < n; i++) {
        if(aux[i]!=nums[i]) {
            f = i; break;
        }
    }         

    if(f == -1) return 0;

    int l = -1;

    for(int i = n-1; i >= 0; i--) {
        if(aux[i]!=nums[i]){
            l = i; break;
        }
    }


    return (l-f+1);
}

int main() {
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i : arr) cin>>i;

    cout << findUnsortedSubarray(arr) << endl;
}
