class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto prerequisite : prerequisites){
            int u = prerequisite[0];
            int v = prerequisite[1];

            adj[u].push_back(v);
        }


        vector<int> indegree(numCourses,0);
        for(int i=0 ; i<numCourses ;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        int count=0;
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            count++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(count == numCourses) return true;
        return false;
    }
};