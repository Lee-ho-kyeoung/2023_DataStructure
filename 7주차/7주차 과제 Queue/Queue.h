#ifndef Queue_h
#define Queue_h

using namespace std;

template <class T>
class Queue{
    private:
        T* queue;
        int rear;
        int front;
        int capacity;
    
    public:
        Queue(int queueCapacity = 8);
        ~Queue();
        inline bool IsEmpty() const;
        void Push(const T& item);
        void Pop();
        void Password();
};

#endif /* Queue_hpp */
