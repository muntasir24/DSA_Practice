#include<bits/stdc++.h>
using namespace std;

void dfs(string target, string word, vector<vector<string>> &ans, vector<string>&v,map<string,int>&mp){
if(word==target){
    ans.push_back(v);
    return;
}
for (size_t i = 0; i < word.size(); i++)
{
    string mainWord = word;
    for (char c = 'a'; c <='z'; c++)
    {
        if (c == mainWord[i]) continue;
        word[i] = c;
        if(mp.count(word) && mp[mainWord]-1==mp[word]){
            v.push_back(word);
            dfs(target, word, ans, v, mp);
            v.pop_back();
        }
    }
    word = mainWord;
}
return;
}

    int main()
{
    string beginWord = "hot", endWord = "dog";
    vector<string> wordList = { "hot", "dog", "dot" };
    unordered_set<string> st(wordList.begin(), wordList.end());
    map<string, int> mp;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    mp[beginWord] = 1;
    st.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int level = q.front().second;
        
        if(word==endWord)
            break;

        q.pop();
        string orginalWord = word;
        for (size_t i = 0; i < word.size(); i++)
        {
            char originalChar = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == originalChar) continue;
                word[i] = c;
                
                if (st.find(word) != st.end())
                {
                    // cout << word << endl;
                    q.push({word, level + 1});
                    mp[word] = level + 1;
                    st.erase(word);
                }
            }
            word = orginalWord;
        }
    }

    // for(auto u:mp)
    //     cout << u.first << " " << u.second << endl;

    vector<vector<string>> ans;
    if (mp.find(endWord) != mp.end()) {
        vector<string> v;
        v.push_back(endWord);
        
        dfs(beginWord, endWord, ans, v, mp);
        
        for (size_t i = 0; i < ans.size(); i++) {
            reverse(ans[i].begin(), ans[i].end());
        }
    }
    
    // for (auto u:ans){
    //     for(auto x:u)
    //         cout << x << ' ';
    //     cout << endl;
    // }
}