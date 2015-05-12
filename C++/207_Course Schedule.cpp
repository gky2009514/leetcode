class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.size() == 0)
            return true;
        vector<int> in_degree(numCourses, 0);
        vector<bool> visit(numCourses, false);
        vector<vector<int> > edge(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in_degree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            int choose = -1;
            for (int j = 0; j < numCourses; j++) {
                if (in_degree[j] == 0 && !visit[j]) {
                    choose = j;
                    visit[j] = true;
                    break;
                }
            }
            if (choose == -1)
                return false;
            for (int j = 0; j < edge[choose].size(); j++) {
                if (visit[edge[choose][j]])
                    continue;
                in_degree[edge[choose][j]]--;
            }
        }
        return true;
    }
};