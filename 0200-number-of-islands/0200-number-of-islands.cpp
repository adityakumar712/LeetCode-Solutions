class Solution {
    int x[4] = {-1 , +1 , 0 , 0};
    int y[4] = {0 , 0 ,-1 , +1};

    bool valid(int i , int j , int n , int m){
        if(i < 0 or i>=n or j<0 or j>=m){
            return false;
        }else{
            return true;
        }
    }

    void DFS(vector<vector<char>>&grid , int n , int m , int i , int j , vector<vector<bool>>&vis){
        vis[i][j] = true;

        for(int k=0; k<4; k++){
            int row = i + x[k];
            int col = j + y[k];

            if(valid(row , col , n ,m) and grid[row][col]=='1' and vis[row][col] ==0){
                DFS(grid , n , m , row , col , vis);
            }
        }

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty() and grid[0].empty()){
            return 0;
        }

        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n);

        for(int i=0; i<n; i++){
                vector<bool>t(m , 0);
                vis[i] = t;
            }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and vis[i][j] == 0 ){
                    DFS(grid , n , m , i , j , vis);
                    res++;
                }
            }
        }

        return res;
    }
};