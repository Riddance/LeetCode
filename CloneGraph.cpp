
struct UndirectedGraphNode {
	int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	    if (node == nullptr) {
	        return node;
	    }

	    typedef unordered_map<int, UndirectedGraphNode*> LABEL_MAP_NODE;
	    LABEL_MAP_NODE Graph;
	    LABEL_MAP_NODE CloneGraph;

	    queue<UndirectedGraphNode* > NodeQueue;
	    NodeQueue.push(node);

	    while (!NodeQueue.empty()) {
	        int val = NodeQueue.front()->label;

	        if (Graph.find(val) != Graph.end()) {
	            NodeQueue.pop();
	            continue;
	        }

	        Graph[val] = NodeQueue.front();
	        for (auto Gnode : NodeQueue.front()->neighbors) {
	            NodeQueue.push(Gnode);
	        }

	        CloneGraph[val] = new(std::nothrow)UndirectedGraphNode(val);
	        assert(CloneGraph[val]);
	        NodeQueue.pop();
	    }

	    for (auto NodePair : Graph) {
	        int val = NodePair.first;
	        for (auto Gnode : NodePair.second->neighbors) {
	            CloneGraph[val]->neighbors.push_back(CloneGraph[Gnode->label]);
	        }
	    }

	    return CloneGraph[node->label];
	}
};