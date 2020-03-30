class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxsize = k;
        queue = new int[maxsize];
        count  = 0;
        front = 0;
        back = -1;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(!isFull())
        {
            if(front == 0){
                front = maxsize-1;
                if(isEmpty())
                    back = front;
                queue[front] = value;
                count++;
                return true;
            }else{
                front--;
                queue[front] = value;
                count++;
                return true;
            }
        }else{
            return false;
        }
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(!isFull())
        {
            back = (back + 1) % maxsize;
            queue[back] = value;
            count++;
            return true;
        }else{
            return false;
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(!isEmpty())
        {
            front = (front + 1) % maxsize;
            count--;
            return true;
        }else{
            return false;
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(!isEmpty())
        {
            if(back == 0 && front>0)
            {
                back = maxsize-1;
                count--;
                return true;
            }else {
                back--;
                count--;
                return true;
            }
        }else{
            return false;
        }
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(count != 0)
        {
            return queue[front];
        }else{
            return -1;
        }
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(count != 0)
        {
            return queue[back];
        }else{
            return -1;
        }
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (count == 0);
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (count == maxsize);
    }
private:
    int maxsize;
    int *queue;
    int count;
    int front;
    int back;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
