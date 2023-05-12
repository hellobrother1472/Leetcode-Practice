#include <bits/stdc++.h>
using namespace std;

// we just have to form a cycle of two pointer, i is on the decision maker and j is iterated to search for next different party person.
// So whenever the party of i and j doest match I make it "C" other wise if it is already "c" then skip or if they are of same party then also skip.
// i also must not be on "c" so as we have found some uncommon party member then we take decision and move forward.
// As we are altering count of r and d so as soon as any of them become zero we return the answer.
class Solution {
public:
    string predictPartyVictory(string senate) {
        int i=0,j=0;
        unordered_map<char,int>mp;
        for(int i = 0; i < senate.size(); i++) mp[senate[i]]++;

        while(mp['R']>0 && mp['D']>0){
            if(senate[i]=='C') i++;
            else if(senate[i] == senate[j] || senate[j] == 'C') j++;
            else{
                mp[senate[j]]--;
                senate[j] = 'C';
                i++;
                j++;
            }
            if(i>=senate.size()) i = 0;
            if(j>=senate.size()) j = 0;
        }
        return (mp['R'] > 0) ? "Radiant" : "Dire";
    }
};

int main(){

    return 0;
}