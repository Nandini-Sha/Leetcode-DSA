class Solution {
public:
    int maxProduct(int n) {
        vector<int> hash(10,0);
        int temp;
        while(n){
            temp = n%10;
            hash[temp]++;
            n = n/10;
        }
        for(int i = 9;i>=0;i--){
            if(hash[i]>0){
                int num1 = i;
                hash[i]--;
                for(int j=9;j>=0;j--){
                    if(hash[j]>0){
                        int num2 = j;
                        return num1*num2;
                    }
                }
            }
        }

        return -1;
    }
};