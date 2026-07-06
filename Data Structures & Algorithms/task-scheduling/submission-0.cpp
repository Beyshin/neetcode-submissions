class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_count(26, 0);

        for(const char& t : tasks){
            task_count[t - 'A']++;
        }

        priority_queue<int> pq; //pq to simulate max_heap holding occurencies

        for(const int& count : task_count){
            if(count > 0){
                pq.push(count);
            }
        }

        queue<pair<int, int>> q; //queue to hold pair of {ocurrency_count, cooldown_time};
        int cpu_cycles = 0;

        while(!pq.empty() || !q.empty()){
            //if done with cooldown move it back to pq
            if(!q.empty() && q.front().second <= cpu_cycles){
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()){
                int tasks_remaining = pq.top() - 1;
                pq.pop();

                if(tasks_remaining > 0){
                    q.push({tasks_remaining, cpu_cycles+n+1});
                }
            }

            cpu_cycles++;
        }
    
        return cpu_cycles;
    }
};
