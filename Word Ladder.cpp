#include <bits/stdc++.h>
using namespace std;

// Trying all the possible characters at every index and going forward doing bfs. As soon as we got the endWord then we return the level associated with it.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        for(int i = 0; i < wordList.size(); i++){
            mp[wordList[i]]++;
        }
        queue<pair<string,int>>q;
        q.push({beginWord, 1});
        mp[beginWord] = 0;
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord) return level;
            for(int i = 0; i < beginWord.size(); i++){
                char original = word[i];
                for(int j = 'a'; j<= 'z'; j++){
                    word[i] = j;
                    if(mp[word]){
                        q.push({word,level+1});
                        mp[word] = 0;
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main(){

    return 0;
}