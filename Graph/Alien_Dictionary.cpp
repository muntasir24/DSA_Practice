#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> words = {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"

    };
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<bool> isPresent(26, false);
    for(auto word:words){
        for (char c: word){
            isPresent[c - 'a'] = true;
        }
    }

    for (int i = 0; i < words.size() - 1; i++){
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.length(), s2.length());
        
        
        if (s1.length() > s2.length() && s1.substr(0, len) == s2) {
            cout << "" << endl;
            return 0; 
        }

        for (int k = 0; k < len;k++){
            if(s1[k]!=s2[k]){
                adj[s1[k] - 'a'].push_back(s2[k] - 'a');
                indegree[s2[k] - 'a']++;
                break;
            }
        }
    }
    // for (int i = 0; i < 26; i++)
    // {
    //     cout << "for " << i << endl;
        
    //     for (auto u : adj[i])
    //         cout << u << " ";
    //     cout << endl;
    // }
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if(isPresent[i] and !indegree[i])
            q.push(i);
    }
    string ans = "";
    while (!q.empty())
    {
        int u = q.front();
        char c = u + 'a';
        ans += c;
        q.pop();
        for(auto child: adj[u]){
            indegree[child]--;
            if(indegree[child]==0)
                q.push(child);
        }
    }
    int ok = 1;
    for (int i = 0; i < 26; i++)
    {
        if (isPresent[i] and indegree[i])
            ok = 0;
    }
    cout << (ok ? ans : "") << endl;

    return 0;
}