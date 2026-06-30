#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << min(max(n, m), 2 * min(n, m)) << '\n';
   
        if(max(n,m)==m){
                for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                cout << min(m, i + j) << ' ';
            }
            cout << '\n';
        

        }
        }
        else{
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                cout << min(n, i + j) << ' ';
            }
            cout << '\n';
        
        }
        }
    }

    return 0;
}