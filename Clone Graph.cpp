class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        unordered_map<int,UndirectedGraphNode *> dic1; // 记录某个点是否已经物理存在
        unordered_set<int> dic2; // 记录某个点是否已经穷举完了全部的边
        unordered_map<int,UndirectedGraphNode *>::iterator it1;
        unordered_set<int>::iterator it2;
        queue<UndirectedGraphNode *> origin;
        queue<UndirectedGraphNode *> target;
        UndirectedGraphNode *start = new UndirectedGraphNode(node->label);
        
        origin.push(node);
        target.push(start);
        
        dic1[start->label] =  start;
        dic2.insert(start->label);
        while (!origin.empty())
        {
            UndirectedGraphNode *origintmp = origin.front();
            UndirectedGraphNode *targettmp = target.front();
            UndirectedGraphNode *tmp;
            for (int i = 0;i < origintmp->neighbors.size();i++)
            {
                it1 = dic1.find(origintmp->neighbors[i]->label);
                if (it1 == dic1.end())
                {
                    tmp = new UndirectedGraphNode(origintmp->neighbors[i]->label);
                    dic1[tmp->label] = tmp;
                    targettmp->neighbors.push_back(tmp);

                }
                else
                {
                    tmp = dic1[origintmp->neighbors[i]->label];
                    targettmp->neighbors.push_back(tmp);
                }

                it2 = dic2.find(tmp->label);
                if (it2 == dic2.end()) // 边没有处理过
                {
                    origin.push(origintmp->neighbors[i]); // 进这个队了，就算处理过了
                    target.push(tmp);
                    dic2.insert(tmp->label);
                }
            }
            
            
            origin.pop();
            target.pop();
        }
        return start;
    }
};