class LRUCache{
private:
    int capacity;
    map<int,int> ram;
    map<int,int> Time;
    int ti;
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->ti = 0;
    }
    
    int get(int key) {
        map<int,int>::iterator it;
        it = ram.find(key);
        if (it == ram.end())
            return -1;
        else
        {
            Time[key] = ti;
            ti ++;
            return ram[key]; 
        }
    }
    
    void set(int key, int value) {
        map<int,int>::iterator it;
        it = ram.find(key);
        if (it != ram.end())
        {
            ram[key]  = value;
            Time[key] = ti;
            ti ++;
        }
        else if (ram.size() < capacity)
        {
            ram[key]  = value;
            Time[key] = ti;
            ti ++;
        }
        else
        {
            int min = Time.begin()->second;
            int tmp = Time.begin()->first;
            for (it = Time.begin();it != Time.end();++it)
            {
                if (it->second < min)
                {
                    min = it->second;
                    tmp = it->first;
                }
            }
            ram.erase(tmp);
            Time.erase(tmp);
            ram[key] = value;
            Time[key] = ti;
            ti ++;
        }
    }
};