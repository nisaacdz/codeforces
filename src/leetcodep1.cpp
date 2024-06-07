#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>> connections(edges.size());
        vector<int> distances1(edges.size(), INT_MAX);
        vector<int> distances2(edges.size(), INT_MAX);
        for(int i = 0; i < edges.size(); i++) {
            if (edges[i] == -1) continue;
            connections[i].push_back(edges[i]);
        }

        find_distances(connections, distances1, node1);
        find_distances(connections, distances2, node2);

        int ans = INT_MAX;
        int node = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (max(distances1[i], distances2[i]) < ans) {
                ans = max(distances1[i], distances2[i]);
                node = i;
            }
        }
        return node;
    }

    void find_distances(vector<vector<int>>& connections, vector<int>& distances, int from) {
        int n = connections.size();
        distances[from] = 0;
        queue<int> q;
        q.push(from);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            q.pop();
            for (int nb: connections[cur]) {
                if (distances[nb] == INT_MAX) {
                    distances[nb] = distances[cur] + 1;
                    q.push(nb);
                }
            }
        }
    }

};