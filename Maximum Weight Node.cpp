#include <bits/stdc++.h>
using namespace std;

// Problem Description :- Maximum Weight Node
// Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).

// You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

// The task is to find :- the node number of maximum weight node(Weight of the node is the sum of node numbers of all nodes pointing to that node).

// Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

// INPUT FORMAT :-

// The first line contains the number of cells N.
// The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have ans exit.
// OUTPUT FORMAT :

// First line denotes the node number with maximum weight node.
// Sample Input :
// 23
// 4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21

// Sample Output :
// 22


// We basically have to calculate the in-degree and return the max indegree.

int find_max_weight_node(int N, const vector<int>& edges) {
    vector<int> inDegree(N, 0);

    // Calculate the weight of each node
    for (int i = 0; i < N; i++) {
        int edge = edges[i];
        if (edge != -1) {
            inDegree[edge] += i;
        }
    }

    int max_weight = 0;
    int max_weight_node = 0;

    // Find the node with maximum weight
    for (int i = 0; i < N; i++) {
        if (inDegree[i] > max_weight) {
            max_weight = inDegree[i];
            max_weight_node = i;
        }
    }

    return max_weight_node;
}


int main(){
    

    return 0;
}