class MyCircularDeque {
public:
    vector<int> dq;
    int front;
    int rear;
    int sz;
    int cap;

    MyCircularDeque(int k) {
        cap = k;
        dq.resize(k);
        front = 0;
        rear = 0;
        sz = 0;
    }

    bool insertFront(int value) {
        if(isFull()) return false;

        front = (front - 1 + cap) % cap;
        dq[front] = value;
        sz++;

        return true;
    }

    bool insertLast(int value) {
        if(isFull()) return false;

        dq[rear] = value;
        rear = (rear + 1) % cap;
        sz++;

        return true;
    }

    bool deleteFront() {
        if(isEmpty()) return false;

        front = (front + 1) % cap;
        sz--;

        return true;
    }

    bool deleteLast() {
        if(isEmpty()) return false;

        rear = (rear - 1 + cap) % cap;
        sz--;

        return true;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return dq[front];
    }

    int getRear() {
        if(isEmpty()) return -1;

        int idx = (rear - 1 + cap) % cap;
        return dq[idx];
    }

    bool isEmpty() {
        return sz == 0;
    }

    bool isFull() {
        return sz == cap;
    }
};