struct Task{
    int userId;
    int taskId;
    int priority;
    bool isDeleted = false;
    Task(int a, int b, int c): userId(a), taskId(b), priority(c) {};
};

struct CompareTask{
    bool operator()(const Task*t1, const Task*t2){
        if(t1 -> priority != t2 -> priority) 
            return t1 -> priority < t2 -> priority;
        return t1 -> taskId < t2 -> taskId;
    }
};   

class TaskManager {
priority_queue<Task*, vector<Task*>, CompareTask> pq;
unordered_map<int, Task*> mpp;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto&it:tasks){
            Task* task = new Task(it[0], it[1], it[2]);
            pq.push(task);
            mpp[it[1]] = task; 
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Task* task = new Task(userId, taskId, priority);
        mpp[taskId] = task;
        pq.push(task);
    }
    
    void edit(int taskId, int newPriority) {
        Task* oldTask = mpp[taskId];
        oldTask -> isDeleted = true;
        Task* newTask = new Task(oldTask -> userId, oldTask -> taskId, newPriority);
        mpp[taskId] = newTask;
        pq.push(newTask);
    }
    
    void rmv(int taskId) {
        mpp[taskId] -> isDeleted = true;
    }
    
    int execTop() {
        while(!pq.empty() && pq.top() -> isDeleted) pq.pop();
        if(pq.empty()) return -1;
        Task* task = pq.top();
        pq.pop();
        task -> isDeleted = true;
        return task -> userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */