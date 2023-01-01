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

int evalRPN(vector<string> &tokens) {
    int n = tokens.size();
    if(n == 1) return stoi(tokens[0]);
    stack<ll> st;
    ll curr = stoi(tokens[0]);
    st.push(curr);

    for(int i = 1; i < n; i++) {
        if(tokens[i] == "+") {
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();
            ll res = a + b;
            st.push(res);

        }else if(tokens[i] == "*") {
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();
            ll res = a * b;
            st.push(res);
            
        }else if(tokens[i] == "-") {
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();
            ll res = a - b;
            st.push(res);
            
        }else if(tokens[i] == "/") {
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();
            ll res = a / b;
            st.push(res);
            
        }else {
            ll res = stoi(tokens[i]);
            st.push(res);
        }
    }

    return st.top();
}


int main() {
    FIO();

    // Code Starts from here!

    int n;
    cin>>n;
    vector<string> tokens(n);
    for(auto &i : tokens) cin>>i;
    cout << evalRPN(tokens) << endl;



    return 0;
}