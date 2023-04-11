#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=ERvmF2qB9CM

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        priority_queue<int,vector<int>,greater<int> > minHeap;
        for(int i = 0 ; i < A.size(); i++){
            for(int j = 0 ; j < B.size(); j++){
                if(minHeap.size() < K || minHeap.top() < A[i]+B[j])minHeap.push(A[i]+B[j]);
                if(minHeap.size() > K) minHeap.pop();
            }
        }
        vector<int>ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// More optimized version where newA means top k biggest element of every array is taken out and then the operation is performed it reduces the size of array on which operation is performed.

class Solution {
  public:
    vector<int> findMinimumVector(vector<int>a, int K){
        priority_queue<int,vector<int>,greater<int> > minHeap;
        vector<int>newA;
        for(int i = 0 ; i < a.size(); i++){
            minHeap.push(a[i]);
            if(minHeap.size() > K) minHeap.pop();
        }
        while(!minHeap.empty()){
            newA.push_back(minHeap.top());
            minHeap.pop();
        }
        return newA;
    }
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        priority_queue<int,vector<int>,greater<int> > minHeap;
        vector<int>newA = findMinimumVector(A,K);
        vector<int>newB = findMinimumVector(B,K);
        
        for(int i = newA.size()-1 ; i >= 0 ; i--){
            for(int j = newB.size()-1 ; j >= 0; j--){
                if(minHeap.size() < K || minHeap.top() < newA[i]+newB[j])minHeap.push(newA[i]+newB[j]);
                if(minHeap.size() > K) minHeap.pop();
            }
        }
        vector<int>ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// https://www.youtube.com/watch?v=ERvmF2qB9CM
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> ans;

        priority_queue<pair<int, pair<int, int>>> pq;

        set<pair<int, int>> my_set;

        pq.push(make_pair(A[N - 1] + B[N - 1], make_pair(N - 1, N - 1)));

        my_set.insert(make_pair(N - 1, N - 1));

        for (int count = 0; count < K; count++) {
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();

            ans.push_back(temp.first);

            int i = temp.second.first;
            int j = temp.second.second;

            if (i - 1 >= 0) {
                int sum = A[i - 1] + B[j];

                pair<int, int> temp1 = make_pair(i - 1, j);

                if (my_set.find(temp1) == my_set.end()) {
                    pq.push(make_pair(sum, temp1));
                    my_set.insert(temp1);
                }
            }

            if (j - 1 >= 0) {
                int sum = A[i] + B[j - 1];
                pair<int, int> temp1 = make_pair(i, j - 1);

                if (my_set.find(temp1) == my_set.end()) {
                    pq.push(make_pair(sum, temp1));
                    my_set.insert(temp1);
                }
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}