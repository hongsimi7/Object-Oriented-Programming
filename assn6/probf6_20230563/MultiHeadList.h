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
        Iterator(Node<T>* node) : curr(node) {}     //������

        Iterator operator++() {                     //���� ++ operator
            if (curr != nullptr) curr = curr->next;
            return *this;
        }

        Iterator operator++(int) {                  //���� ++ operator
            Iterator temp = *this;
            if (curr != nullptr) curr = curr->next;
            return temp;
        }

        Iterator operator--() {                     //���� -- operator
            if (curr != nullptr) curr = curr->prev;
            return *this;
        }

        Iterator operator--(int) {                  //���� -- operator
            Iterator temp = *this;
            if (curr != nullptr) curr = curr->prev;
            return temp;
        }

        Iterator operator+(int n) {             //+operator
            Iterator result = *this;
            for (int i = 0; i != n; ++i) {      //n�� ++ operator �۵�
                ++result;
            }
            return result;
        }

        Iterator operator-(int n) {             //-operator
            Iterator result = *this;
            for (int i = 0; i != n; ++i) {      //n�� -- operator �۵�
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

        ReverseIterator operator++() {                  //���� ++ operator
            if (curr != nullptr) curr = curr->prev;
            return *this;
        }

        ReverseIterator operator++(int) {               //���� ++ operator
            ReverseIterator temp = *this;
            if (curr != nullptr) curr = curr->prev;
            return temp;
        }

        ReverseIterator operator--() {                  //���� -- operator
            if (curr != nullptr) curr = curr->next;
            return *this;
        }

        ReverseIterator operator--(int) {               //���� ++ operator
            ReverseIterator temp = *this;
            if (curr != nullptr) curr = curr->next;
            return temp;
        }

        ReverseIterator operator+(int n) {              //+ operator
            ReverseIterator result = *this;
            for (int i = 0; i != n; ++i) {              //n�� ++ operator �۵�
                ++result;
            }
            return result;
        }

        ReverseIterator operator-(int n) {          //- operator
            ReverseIterator result = *this;
            for (int i = 0; i != n; ++i) {          //n�� -- operator �۵�
                --result;
            }
            return result;
        }

        bool operator!=(const ReverseIterator& other) { return curr != other.curr; }    //!= operator
        bool operator==(const ReverseIterator& other) { return curr == other.curr; }    //== operator
        T operator*() { return curr->data; }        //*operator;
    };


public:
    int headSize() { return headList.size(); }          //headList�� ũ�⸦ ��ȯ

    void push_back(const T& data, int headIdx = -1)     
    {
        if (headIdx < 0 || headIdx >= headSize())       //���ο� head ���� �� �߰�
        {
            Node<T>* head = new Node<T>(data);
            headList.push_back(head);
        }
        else                                            //headIdx��° List �� ���� data �߰�
        {
            ReverseIterator ri = rbegin(headIdx);
            Node<T>* element = new Node<T>(data);
            ri.curr->next = element;
            element->prev = ri.curr;
        }
    }
    
    void push_front(const T& data, int headIdx = -1)
    {
        if (headIdx < 0 || headIdx >= headSize())       //���ο� head ���� �� �߰�
        {
            Node<T>* head = new Node<T>(data);
            headList.push_back(head);
        }
        else                                            //headIdx��° List �� �տ� data �߰�
        {
            Iterator it = begin(headIdx);
            Node<T>* element = new Node<T>(data);
            element->next = it.curr;
            it.curr->prev = element;
            headList[headIdx] = element;

        }
    }

    void insert(Iterator pos, const T& data)        //pos�� ����Ű�� �� ������ data ����
    {
        Node<T>* element = new Node<T>(data);
        element->next = pos.curr;                   //element prev, next ����
        element->prev = pos.curr->prev;

        if (pos.curr->prev != nullptr)              //pos ������ nullptr�� �ƴ� ��
        {
            pos.curr->prev->next = element;         //element ������ prev ����
        }
        else                                        //pos�� head�� ��
        {
            int count = 0;
            while (pos != headList[count])          //�� ��° head���� ã��
            {
                count++;
            }
            headList[count] = element;              //head ����
        }
        pos.curr->prev = element;                   //pos prev ����
    }

    void pop_back(int headIdx) 
    {
        ReverseIterator ri = rbegin(headIdx);       //������ iterator ����
        if (ri.curr->prev != nullptr)   ri.curr->prev->next = nullptr;  //pop����� head�� �ƴ� ��
        else headList.erase(headList.begin() + headIdx);                //pop����� head�� ��
        delete ri.curr;     //�Ҵ�����
    }

    void pop_front(int headIdx) 
    {
        Iterator it = begin(headIdx);       //iterator ����
        if (it.curr->next != nullptr)       //head�� �������� ���� ��
        {
            it.curr->next->prev = nullptr;
            headList[headIdx] = it.curr->next;
        }
        else headList.erase(headList.begin() + headIdx);    //head�� ������ ��
        delete it.curr;
    }

    void merge(int frontHeadIdx, int backHeadIdx) 
    {
        ReverseIterator ri_front = rbegin(frontHeadIdx);    //������ iterator ����
        Iterator it_back = begin(backHeadIdx);              //iterator ����

        ri_front.curr->next = it_back.curr;     //����
        it_back.curr->prev = ri_front.curr;
        headList.erase(headList.begin() + backHeadIdx);     //������ headIdx ����
    }

    bool erase(const T& data, int targetHeadIdx) 
    {
        Iterator it = begin(targetHeadIdx);     //iterator ����
        
        while (it != end())     //������ ã��
        {
            
            if (it.curr->data == data)  //�����͸� ã���� ��
            {        
                if (it.curr->next != nullptr)   //�������� next�� nullptr�� �ƴ� ��
                {
                    it.curr->next->prev = nullptr;
                    headList.push_back(it.curr->next);
                }
                if (it.curr->prev != nullptr) it.curr->prev->next = nullptr;    //�������� prev�� nullptr�� �ƴ� ��
                if (it == headList[targetHeadIdx]) headList.erase(headList.begin() + targetHeadIdx);    //�����Ͱ� head�� ��

                delete it.curr;     //�Ҵ�����
                
                return true;
            }
            else ++it;      //�����͸� �� ã���� ��
        }
        return false;
    }
    bool erase(Iterator pos) 
    {
        if (pos.curr->next != nullptr)   //�������� next�� nullptr�� �ƴ� ��
        {
            pos.curr->next->prev = nullptr;
            headList.push_back(pos.curr->next);
        }
        if (pos.curr->prev != nullptr) pos.curr->prev->next = nullptr;      //�������� prev�� nullptr�� �ƴ� ��

        int count = 0;
        for (int i = 0; i != headSize(); ++i)
        {
            if (pos == headList[i])                 //�����Ͱ� head�� ��
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