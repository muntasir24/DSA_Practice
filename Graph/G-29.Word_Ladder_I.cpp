#include<bits/stdc++.h>
using namespace std;

int main(){
    string beginWord="hit", endWord="cog";

    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    unordered_set<string> s(wordList.begin(), wordList.end());
    int ans = 0,step=0;
    while (!q.empty())
    {
        string word = q.front().first;
        step = q.front().second;
        if (word == endWord)
            {
                ans = step;
                break;
            }
        q.pop();
        for (int i = 0; i < word.size(); i++)
        {
            string orginalWord=word;
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if(s.find(word)!=s.end())
                    {
                        q.push({word,step+1});
                        s.erase(word);
                    }
            }
            word = orginalWord;
        }
    }
    cout <<ans << endl;

    return 0;
}