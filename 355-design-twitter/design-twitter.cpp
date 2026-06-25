class Twitter {
private:
    int t = 0;
    
    struct User{
        int userID;
        vector<pair<int,int>> tweetids;
        unordered_set<int> followings;

        User(int id){
            userID = id;
        }
    };
    User* getuser(int userID){
            if(users.find(userID) == users.end()){
                users[userID] = new User(userID);
            }
            return users[userID];
    }
    unordered_map <int, User*> users;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        User* u = getuser(userId);
        u->tweetids.push_back({t++, tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> list;
        if(users.find(userId) == users.end()) return list;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> que;
        User* u = getuser(userId);
        for(auto tweet: u->tweetids){
            if(que.size()<10) que.push(tweet);
                else{
                    if(tweet.first>que.top().first){
                        que.pop();
                        que.push(tweet);
                    }
                }
        }
        for(auto follower: u->followings){
            User* f = getuser(follower);
            for(auto tweet: f->tweetids){
                if(que.size()<10) que.push(tweet);
                else{
                    if(tweet.first>que.top().first){
                        que.pop();
                        que.push(tweet);
                    }
                }
            }
        }
        while(!que.empty() && list.size()<10){
            auto tweet = que.top();
            que.pop();
            list.push_back(tweet.second);
        }
        reverse(list.begin(),list.end());
        return list;
    }
    
    void follow(int followerId, int followeeId) {
        User* u = getuser(followerId);
        u->followings.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        User* u = getuser(followerId);
        u->followings.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */