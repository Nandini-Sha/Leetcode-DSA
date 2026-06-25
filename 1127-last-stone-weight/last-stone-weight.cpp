class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> hehe;
        for(int i = 0;i<stones.size();i++){
            hehe.push(stones[i]);
        }
        while(hehe.size()>1){
            int stone1 = hehe.top();
            hehe.pop();
            int stone2 = hehe.top();
            hehe.pop();
            int finally = abs(stone1-stone2);
            if(finally>0) hehe.push(finally);
        }
        return (hehe.size()==1)?hehe.top():0;
    }
};