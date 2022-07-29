class LRUCache {
public:
    // for O(1) time complexity we used doubly linkd list nodes and hashmpa to store kry.node pairs 
    class  node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    node*head= new node(-1,-1);
    node*tail= new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* newnode)
    {
        node* temp=head->next;
        newnode->next=temp;
        head->next=newnode;
        newnode->prev=head;
        temp->prev=newnode;
    }
    void deletenode(node *delnode)
    {
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int cache_key) {
        if(m.find(cache_key)!=m.end())
        {                                   // key present in map 
            node *keynode=m[cache_key];     // get node of that key 
            int res=keynode->val;           // get value from 
            m.erase(cache_key);          // erase from map 
            deletenode(keynode);
            addNode(keynode);
            m[cache_key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_)!=m.end())
        {   // key present in hasmap so erasing and deleting the node as no matter  already present or not we need erase from map and delete node to create new node and store that node in map
            node *existingnode =m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size()==cap)
        {
            // size of cache is full now we need to delete the tail->prev
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addNode(new node(key_,value));
        m[key_]=head->next; // as we add new node to head->next so directly access 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */





as we need O(1) complexity and that can be achieved using doubly linked list and hashmap 
so we used doubly linked list as our cache and hashmap to store key along with that node which stores
key,value in our cache 
also as we can see we need to know about least recent used node so we adopted working of queue in node 
whenever we need to push we will push at head->next and whenever we need to delete (if capacity full ) then we will delete from tail->prev 
as we can observe that when an noed is used by push or get it will be at head->next and leaast used will remain at last 