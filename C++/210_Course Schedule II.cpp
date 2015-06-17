class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<bool> visit(numCourses, false);
        vector<vector<int> > edge(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            in_degree[prerequisites[i].first]++;
            edge[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            int course = -1;
            for (int j = 0; j < numCourses; j++) {
                if (in_degree[j] == 0 && !visit[j]) {
                    course = j;
                    break;
                }
            }
            if (course == -1)
                return vector<int>();
            visit[course] = true;
            res.push_back(course);
            for (int j = 0; j < edge[course].size(); j++) {
                if (visit[edge[course][j]])
                    continue;
                in_degree[edge[course][j]]--;
            }
        }
        return res;
    }
};