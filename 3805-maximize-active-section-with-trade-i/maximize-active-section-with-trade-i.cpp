class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        s = '1' + s + '1';

        vector<pair<char,int>> blocks;

        char c = s[0];
        int length = 1;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == c)
                length++;
            else {
                blocks.push_back({c, length});
                c = s[i];
                length = 1;
            }
        }
        blocks.push_back({c, length});

        int ones = 0;
        for(char ch : s)
            if(ch == '1')
                ones++;
        ones -= 2;    

        int gain = 0;
        int left = 0,right = 0;
        for(int i = 1;i<blocks.size()-1;i++){
            if(blocks[i].first == '1'){
                gain = max(gain,(blocks[i-1].second+blocks[i+1].second));
            }
        }

        return gain + ones;
    }
};