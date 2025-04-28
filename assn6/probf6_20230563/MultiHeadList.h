#pragma once
#ifndef MULTIHEADLIST_H
#define MULTIHEADLIST_H
#include <vector>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

template<typename T>
class MultiHeadList {
private:
    vector<Node<T>*> headList;
public :
    class Iterator {                //iterator
    public:
        Node<T>* curr;              //Node pointer
        Iterator(Node<T>* node) : curr(node) {}     //생성자

        Iterator operator++() {                     //전위 ++ operator
            if (curr != nullptr) curr = curr->next;
            return *this;
        }

        Iterator operator++(int) {                  //후위 ++ operator
            Iterator temp = *this;
            if (curr != nullptr) curr = curr->next;
            return temp;
        }

        Iterator operator--() {                     //전위 -- operator
            if (curr != nullptr) curr = curr->prev;
            return *this;
        }

        Iterator operator--(int) {                  //후위 -- operator
            Iterator temp = *this;
            if (curr != nullptr) curr = curr->prev;
            return temp;
        }

        Iterator operator+(int n) {             //+operator
            Iterator result = *this;
            for (int i = 0; i != n; ++i) {      //n번 ++ operator 작동
                ++result;
            }
            return result;
        }

        Iterator operator-(int n) {             //-operator
            Iterator result = *this;
            for (int i = 0; i != n; ++i) {      //n번 -- operator 작동
                --result;
            }
            return result;
        }

        bool operator!=(const Iterator& other) { return curr != other.curr; }       //!= operator
        bool operator==(const Iterator& other) { return curr == other.curr; }       //== operator
        T operator*() { return curr->data; }    //*operator
    };

    class ReverseIterator {
    public:
        Node<T>* curr;
        ReverseIterator(Node<T>* node) : curr(node) {}

        ReverseIterator operator++() {                  //전위 ++ operator
            if (curr != nullptr) curr = curr->prev;
            return *this;
        }

        ReverseIterator operator++(int) {               //후위 ++ operator
            ReverseIterator temp = *this;
            if (curr != nullptr) curr = curr->prev;
            return temp;
        }

        ReverseIterator operator--() {                  //전위 -- operator
            if (curr != nullptr) curr = curr->next;
            return *this;
        }

        ReverseIterator operator--(int) {               //후위 ++ operator
            ReverseIterator temp = *this;
            if (curr != nullptr) curr = curr->next;
            return temp;
        }

        ReverseIterator operator+(int n) {              //+ operator
            ReverseIterator result = *this;
            for (int i = 0; i != n; ++i) {              //n번 ++ operator 작동
                ++result;
            }
            return result;
        }

        ReverseIterator operator-(int n) {          //- operator
            ReverseIterator result = *this;
            for (int i = 0; i != n; ++i) {          //n번 -- operator 작동
                --result;
            }
            return result;
        }

        bool operator!=(const ReverseIterator& other) { return curr != other.curr; }    //!= operator
        bool operator==(const ReverseIterator& other) { return curr == other.curr; }    //== operator
        T operator*() { return curr->data; }        //*operator;
    };


public:
    int headSize() { return headList.size(); }          //headList의 크기를 반환

    void push_back(const T& data, int headIdx = -1)     
    {
        if (headIdx < 0 || headIdx >= headSize())       //새로운 head 생성 및 추가
        {
            Node<T>* head = new Node<T>(data);
            headList.push_back(head);
        }
        else                                            //headIdx번째 List 맨 끝에 data 추가
        {
            ReverseIterator ri = rbegin(headIdx);
            Node<T>* element = new Node<T>(data);
            ri.curr->next = element;
            element->prev = ri.curr;
        }
    }
    
    void push_front(const T& data, int headIdx = -1)
    {
        if (headIdx < 0 || headIdx >= headSize())       //새로운 head 생성 및 추가
        {
            Node<T>* head = new Node<T>(data);
            headList.push_back(head);
        }
        else                                            //headIdx번째 List 맨 앞에 data 추가
        {
            Iterator it = begin(headIdx);
            Node<T>* element = new Node<T>(data);
            element->next = it.curr;
            it.curr->prev = element;
            headList[headIdx] = element;

        }
    }

    void insert(Iterator pos, const T& data)        //pos가 가리키는 곳 이전에 data 삽입
    {
        Node<T>* element = new Node<T>(data);
        element->next = pos.curr;                   //element prev, next 지정
        element->prev = pos.curr->prev;

        if (pos.curr->prev != nullptr)              //pos 이전이 nullptr이 아닐 때
        {
            pos.curr->prev->next = element;         //element 이전의 prev 변경
        }
        else                                        //pos가 head일 때
        {
            int count = 0;
            while (pos != headList[count])          //몇 번째 head인지 찾기
            {
                count++;
            }
            headList[count] = element;              //head 변경
        }
        pos.curr->prev = element;                   //pos prev 변경
    }

    void pop_back(int headIdx) 
    {
        ReverseIterator ri = rbegin(headIdx);       //리버스 iterator 생성
        if (ri.curr->prev != nullptr)   ri.curr->prev->next = nullptr;  //pop대상이 head가 아닐 때
        else headList.erase(headList.begin() + headIdx);                //pop대상이 head일 때
        delete ri.curr;     //할당해제
    }

    void pop_front(int headIdx) 
    {
        Iterator it = begin(headIdx);       //iterator 생성
        if (it.curr->next != nullptr)       //head만 존재하지 않을 때
        {
            it.curr->next->prev = nullptr;
            headList[headIdx] = it.curr->next;
        }
        else headList.erase(headList.begin() + headIdx);    //head만 존재할 때
        delete it.curr;
    }

    void merge(int frontHeadIdx, int backHeadIdx) 
    {
        ReverseIterator ri_front = rbegin(frontHeadIdx);    //리버스 iterator 생성
        Iterator it_back = begin(backHeadIdx);              //iterator 생성

        ri_front.curr->next = it_back.curr;     //병합
        it_back.curr->prev = ri_front.curr;
        headList.erase(headList.begin() + backHeadIdx);     //후자의 headIdx 삭제
    }

    bool erase(const T& data, int targetHeadIdx) 
    {
        Iterator it = begin(targetHeadIdx);     //iterator 생성
        
        while (it != end())     //데이터 찾기
        {
            
            if (it.curr->data == data)  //데이터를 찾았을 때
            {        
                if (it.curr->next != nullptr)   //데이터의 next가 nullptr이 아닐 때
                {
                    it.curr->next->prev = nullptr;
                    headList.push_back(it.curr->next);
                }
                if (it.curr->prev != nullptr) it.curr->prev->next = nullptr;    //데이터의 prev가 nullptr이 아닐 때
                if (it == headList[targetHeadIdx]) headList.erase(headList.begin() + targetHeadIdx);    //데이터가 head일 때

                delete it.curr;     //할당해제
                
                return true;
            }
            else ++it;      //데이터를 못 찾았을 때
        }
        return false;
    }
    bool erase(Iterator pos) 
    {
        if (pos.curr->next != nullptr)   //데이터의 next가 nullptr이 아닐 때
        {
            pos.curr->next->prev = nullptr;
            headList.push_back(pos.curr->next);
        }
        if (pos.curr->prev != nullptr) pos.curr->prev->next = nullptr;      //데이터의 prev가 nullptr이 아닐 때

        int count = 0;
        for (int i = 0; i != headSize(); ++i)
        {
            if (pos == headList[i])                 //데이터가 head일 때
            {
                headList.erase(headList.begin() + i);
                break;
            }
        }
        delete pos.curr;

        return true;
    }

    Iterator begin(int headIdx) {return Iterator(headList[headIdx]);}   //begin
    Iterator end() { return Iterator(nullptr); }                        //end
    ReverseIterator rbegin(int headIdx)                                 //rbegin
    { 
        Node<T>* rb = headList[headIdx];
        while (rb->next != nullptr)
        {
            rb = rb->next;
        }
        return ReverseIterator(rb); 
    }
    ReverseIterator rend() { return Iterator(nullptr); }            //rend
};

#endif