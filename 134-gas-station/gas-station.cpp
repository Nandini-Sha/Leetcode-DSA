class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> allover;
        int n = gas.size();
        if(n==1 && gas[0]>=cost[0]) return 0;
        int x;
        int sum = 0;
        for(int i = 0;i<n;i++){
            x = gas[i]-cost[i];
            sum+=x;
            allover.push_back(x);
        }
        if(accumulate(allover.begin(), allover.end(), 0) < 0) return -1;
        for(int i = 0;i<n;i++){
            sum = 0;
            if(allover[i]>0){
                sum+=allover[i];
                int j = (i+1)%n;
                bool exist = true;
                while(j!=i){
                    sum+=allover[j];
                    if(sum<0) {
                        exist = false;
                        break;
                    }
                    j = (j+1)%n;
                }
                if(exist) return i;
            }
        }

        return -1;
    }
};