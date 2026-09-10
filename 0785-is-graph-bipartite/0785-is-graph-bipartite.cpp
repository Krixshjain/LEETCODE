class Solution {
public:
    bool check(int node , int V , vector<int>& vis , vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        vis[node] = 0;

        while(!q.empty()){
            int nodee = q.front();
            q.pop();
            
            for(auto it : graph[nodee]){
                if(vis[it] == -1){
                    vis[it] = !vis[nodee];
                    q.push(it);
                }
                else if(vis[it] == vis[nodee]) return false;
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,-1);
        for(int i=0 ; i<V ;i++){
            if(vis[i] == -1){
                if(check(i ,V , vis , graph) == false) return false;
            }
        }
        return true;
    }
};