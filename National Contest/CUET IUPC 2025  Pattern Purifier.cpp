#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        stack<char> st;
        st.push(s[0]);
        int ptr = 1;
        while(ptr<n ){
            if(st.empty()){
                st.push(s[ptr]);
                ptr++;
            }
            else if(s[ptr]==st.top()){
                st.pop();
                ptr++;
            }
            else{
                st.push(s[ptr]);
                ptr++;
            }
        }
        cout << (st.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}