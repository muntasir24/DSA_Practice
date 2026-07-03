#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int l = 0, r = n - 1;
        int flag = 1,el1=1,el2=2;
        
            if((el1==v[l] and el2==v[r])or(el1==v[r] and el2==v[l])){
                l++;
                r--;
                el1+=2;
                el2+=2;
            }
            else {
                flag = 0;
             
            }
        
          cout << (flag ? "YES" : "NO") << endl;
    }
  

    return 0;
}