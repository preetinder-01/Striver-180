// queue using array 

class Queue {
    int *arr;
        int qfront;
        int rear;
        int size;
public:
        Queue(){
            size=100001;
               arr=new int[size];
               qfront=0;
               rear=-1;
               }
   

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear==-1)
            return 1;
        return 0;
        
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size)
        { cout<<"queue full";
        return;}
        else
        {
        rear++;
        arr[rear]=data;
            }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear==-1)
            return -1;
        else
        {
            int val=arr[qfront];
            if(qfront==rear)
            {
                qfront=0;rear=-1;
            }
            else
                qfront++;
            return val;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront>rear)
            return -1;
        return arr[qfront];
    }
};