#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        vector<string>usedOnLevel;
        vector<vector<string>>ans;
        int level = 0;
        q.push({beginWord});
        usedOnLevel.push_back(beginWord);
        while(!q.empty()){
            vector<string>vec = q.front();
            string word = vec.back();
            q.pop();
            if(vec.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
            }
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0 ; i < beginWord.size(); i++){
                char original = word[i];
                for(char j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}