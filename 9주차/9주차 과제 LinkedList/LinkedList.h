#ifndef LinkedList_h
#define LinkedList_h

using namespace std;

template <class T> class Chain; // 전방 선언

template <class T>
class ChainNode {               //노드 클래스
    friend class Chain<T>;      //friend 선언
    public:
        //data는 d로 link는 0으로 초기화 하는 생성자
        ChainNode(T d) : data(d), link(0){};
        ~ChainNode(){};         //파괴자
    
    private:
        T data;
        ChainNode *link;
};

template <class T>
class Chain {
    public:
        Chain() : first(0){};   // first를 0으로 초기화하는 생성자
        ~Chain(){};             //파괴자
        
        void insertNode(T);     //노드를 리스트에 추가하는 함수
        void PrintList();       //리스트를 출력하는 함수
    
    private:
        ChainNode<T> *first;    
};

#endif /* LinkedList_hpp */
