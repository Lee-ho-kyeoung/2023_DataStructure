#ifndef Subway_h
#define Subway_h

using namespace std;

class Station{
    friend class RouteMap;                  //friend 선언
    public:
        Station(string name) : name(name), link(0){};   //link를 0으로 초기화하는 생성자
        ~Station(){};                       //파괴자
        
    private:
        string name;                        //역 이름
        Station *link;                      //다음 이어진 경로
};

class RouteMap{
    public:
        RouteMap() : first(0), last(0){};   //first와 last를 0으로 초기화하는 생성자
        ~RouteMap(){};                      //파괴자
    
        void Insert(string);           //역을 노선에 넣는 함수
        void Delete(string);                //역을 노선에서 제거하는 함수
        void RENAME(string, string);        //역의 이름을 변경하는 함수
        void Make(string, string);          //인자가 2개일 때 역을 만드는 함수
        void Make(string, string, string);  //인자가 3개일 때 역을 만드는 함수
        void PrintStation();                //노선도를 출력하는 함수

    private:
        Station *first;                     //첫 노드를 가리킴
        Station *last;                      //마지막 노드를 가리킴
};
#endif /* Subway_hpp */
