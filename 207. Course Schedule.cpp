class Solution {
public:
    struct Node {
    unordered_set<int> requires; 
};

bool iscycle(int v, vector<Node>& nodes, vector<int>& colors) { // если есть цикл выводим true
    colors[v] = 1; 
    for (auto i = nodes[v].requires.begin(); i != nodes[v].requires.end(); ++i) {
        int to = *i; 
        if (colors[to] == 0) {
            if (iscycle(to, nodes, colors)) {
                return true;
            }
        }
        else if (colors[to] == 1){
            return true; 
        }
    }
    colors[v] = 2; 
    return false; 
        
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    vector<int>colors(numCourses);
    vector<Node> nodes(numCourses);
    for (int i = 0; i < prerequisites.size(); ++i) {
        nodes[prerequisites[i][0]].requires.insert(prerequisites[i][1]); 
    }
    for (int i = 0; i < numCourses; ++i) {
        if (iscycle(i, nodes, colors)) {
            return false;
        }
    }
    return true; 
}
};
