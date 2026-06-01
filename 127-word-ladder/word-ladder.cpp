class Solution {
public:
    bool oneDiff(string a, string b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1) return false;
            }
        }

        return diff == 1;
    }

    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(
            wordList.begin(),
            wordList.end()
        );

        if (!words.count(endWord))
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while(!q.empty()) {
            auto [word,len] = q.front();
            q.pop();

            if(word == endWord)
                return len;

            for(auto &next : wordList) {
                if(!visited.count(next) &&
                   oneDiff(word,next)) {

                    visited.insert(next);
                    q.push({next,len+1});
                }
            }
        }

        return 0;
    }
};