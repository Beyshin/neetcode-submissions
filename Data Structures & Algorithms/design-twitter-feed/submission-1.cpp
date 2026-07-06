class Twitter {
    private:
    vector<pair<int, int>> m_tweets;
    unordered_map<int, unordered_set<int>> m_follows;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        m_tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweets_to_display;
        
        for(int i = m_tweets.size()-1; i>=0; i--){
            int tweet_author = m_tweets[i].first;
            if(tweet_author == userId || m_follows[userId].count(tweet_author)){
                tweets_to_display.push_back(m_tweets[i].second);

                if(tweets_to_display.size() == 10) break;
            }
        }
        return tweets_to_display;
    }
    
    void follow(int followerId, int followeeId) {
        m_follows[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        m_follows[followerId].erase(followeeId);
    }
};
