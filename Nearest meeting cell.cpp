#include <bits/stdc++.h>
using namespace std;

// Problem Description :

// You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (i.e. entry/exit points are unidirectional doors like valves). The cells are named with an integer from 0 to N-1.

// You have to find :

// Nearest meeting cell : Given any two cells - C1, C2, find the closest cell Cm that can be reached from both C1 and C2.

// INPUT FORMAT :

// The first line contains the number of cells N.
// The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have an exit.
// Third line for each testcase contains two cell numbers whose nearest meeting cell needs to be found. (return -1 if there is no meeting cell from two given cells)
// OUTPUT FORMAT :
// Output a single line that denotes the nearest meeting cell (NMC).

// Sample Input :
// 23
// 4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
// 9 2

// Sample Output :
// 4


// Calculate the distance of all nodes from both the nodes, now ans is minimum of sum of both the distances from both the nodes.
int find_nearest_meeting_cell(int N, const vector<int>& edges, int cell1, int cell2) {
    vector<vector<int>> adj_list(N);

    // Build an adjacency list from the edges array
    for (int i = 0; i < N; i++) {
        int edge = edges[i];
        if (edge != -1) {
            adj_list[i].push_back(edge);
        }
    }

    // Perform BFS from both cells simultaneously
    queue<int> queue1;
    queue<int> queue2;
    vector<int> distance1(N, -1);
    vector<int> distance2(N, -1);

    queue1.push(cell1);
    distance1[cell1] = 0;

    while (!queue1.empty()) {
        int curr1 = queue1.front();
        queue1.pop();

        for (int neighbor : adj_list[curr1]) {
            if (distance1[neighbor] == -1) {
                distance1[neighbor] = distance1[curr1] + 1;
                queue1.push(neighbor);
            }
        }
    }

    queue2.push(cell2);
    distance2[cell2] = 0;

    while (!queue2.empty()) {
        int curr2 = queue2.front();
        queue2.pop();

        for (int neighbor : adj_list[curr2]) {
            if (distance2[neighbor] == -1) {
                distance2[neighbor] = distance2[curr2] + 1;
                queue2.push(neighbor);
            }
        }
    }

    // Find the nearest meeting cell
    int nearest_meeting_cell = -1;
    int min_distance = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (distance1[i] != -1 && distance2[i] != -1) {
            int total_distance = distance1[i] + distance2[i];
            if (total_distance < min_distance) {
                min_distance = total_distance;
                nearest_meeting_cell = i;
            }
        }
    }

    return nearest_meeting_cell;
}


int main(){

    return 0;
}