
class Solution {
public:
    bool res = true;

    void DFS(vector<vector<int>>& graph, int node, int c,
             vector<int>& colors) {
        colors[node] = c;

        for (int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];

            if (colors[neigh] != -1 && colors[neigh] == c) {
                res = false;
                return;
            }

            if (colors[neigh] == -1) {
                DFS(graph, neigh, 1 - c, colors);
                
                if (!res) return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                DFS(graph, i, 0, colors);
            }

            if (!res) return false;
        }

        return true;
    }
};
