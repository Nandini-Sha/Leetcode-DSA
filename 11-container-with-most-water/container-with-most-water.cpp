class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int i = 0,j=height.size()-1;
        while(i<j){
            int temp = (j-i)*min(height[i],height[j]);
            maxi = max(temp,maxi);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxi;
    }
};