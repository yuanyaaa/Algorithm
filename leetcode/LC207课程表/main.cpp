bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 广度优先搜索+拓扑排序 
        //  注释是自己写的方法，但是很不简约，又重新写了一次。但是发现了一些问题。不能在for循环里面erase，
        // 首先erase之后会返回下一个iter，然后for循环里面iter++再次执行，相当于iter+2，并且可能会越界。
        // 采用标记，标记其出错。我觉得resize用着也很不错
        vector<vector<int>> map;
        vector<int> degree;
        map.resize(numCourses);
        degree.resize(numCourses);
        // int **map = new int*[numCourses];
        // int *degree = new int[numCourses];

        int nums = 0;
        queue<int> q;
        // for(int i = 0; i < numCourses; i++){
        //     map[i] = new int[numCourses];
        //     degree[i] = 0;
        //     for(int j = 0; j < numCourses; j++){
        //         map[i][j] = 0;
        //     }
        // }

        for(const auto edge : prerequisites){
            map[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
        }
        // for(int i = 0; i < prerequisites.size(); i++){
        //     map[prerequisites[i][1]][prerequisites[i][0]] = 1;
        //     degree[prerequisites[i][0]]++;
        // }

        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                q.push(i);
                nums++;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& n:map[node]){
                degree[n]--;
                if(degree[n] == 0){
                    q.push(n);
                    // map.erase(map.begin());
                    //iter = map[node].erase(iter);
                    nums++;
                    n = -1;
                    //if(iter ==  map[node].end()){
                    //    break;
                    //}
                    
                }
            }
            // for(int i = 0; i< map[node].size(); i++){
            //     if(map[node][i] != 0){
            //         map[node][i] = 0;
            //         degree[i]--;
            //         if(degree[i] == 0){
            //             q.push(i);
            //             nums++;
            //         }
            //     }
            // }
        }

        return numCourses == nums;
        // if(nums == numCourses){
        //     return true;
        // }
        // return false;
    }