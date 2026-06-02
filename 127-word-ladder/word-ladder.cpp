class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == endWord)
                    return level;

                string temp = cur;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;

                        temp[i] = c;

                        if (words.count(temp)) {
                            q.push(temp);
                            words.erase(temp);
                        }
                    }

                    temp[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};