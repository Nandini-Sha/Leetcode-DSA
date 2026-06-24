class Solution {
private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        stack<char> s;
        vector<int> map(2);
        string temp;
        map[0] = n;//(
        map[1] = n;//)
        back(map,s, temp);

        return res;

    }
    void back(vector<int> &map, stack<char> &s, string &temp){
        if(s.empty() && map[0] == 0 && map[1] == 0){
            res.push_back(temp);
            return;
        }
        if(map[0]>0){
            temp+='(';
            s.push('(');
            map[0]--;

            back(map,s,temp);

            temp.pop_back();
            s.pop();
            map[0]++;
        }
        if(map[1]>0 && !s.empty()){
            if(s.top()=='('){
                temp+=')';
                map[1]--;
                s.pop();

                back(map,s,temp);
                
                temp.pop_back();
                s.push('(');
                map[1]++;
            }
        }
    }
};