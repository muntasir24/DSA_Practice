#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c==1){
            cout << a << endl;
        }
        else if(c==2){
            cout << b << endl;
        }
        else{
            cout << (a & b) << endl;
        }
    }
}