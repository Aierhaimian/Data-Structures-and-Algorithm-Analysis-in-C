#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>

using namespace std;

//ʵ��˳��ջģ��
template<class T>
class stack
{
public:
    //���캯��
    Stack(){int MaxStackSize = 100};
    //��������
    ~Stack(){Clear()};
    //����ջ
    void Clear();
    //���ջ
    void Empty();
    //�ж�ջ�Ƿ�Ϊ��
    bool isEmpty();
    //�ж�ջ�Ƿ�����
    bool isFull();
    //��ջ
    bool Push(const T &item);
    //��ջ
    bool Pop();
    //����ջ��Ԫ��
    bool Top(T &item);
private:
    int topOfStack;
    int capacity;
    T *array;
};

template<class T>
Stack<T>::Stack(int MaxStackSize):capacity(MaxStackSize)
{
    array = new T[capacity];
    topOfStack = -1;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return topOfStack == -1;
}

template<class T>
bool Stack<T>::isFull()
{
    return topOfStack == capacity - 1;
}

template<class T>
bool Stack<T>::Push(const T &item)
{
    if(isFull() == true)
        return false;
    topOfStack ++;
    array[topOfStack] = item;
    return true;
}

template<class T>
bool Stack<T>::Pop()
{
    if(isEmpty() == true)
        return false;
    topOfStack --;
    return true;
}

template<class T>
bool Stack<T>::Top(T &item)
{
    if(isEmpty() == true)
        return false;
    item = array[topOfStack];
    return true;
}

template<class T>
void Stack<T>::Clear()
{
    topOfStack = -1;
    delete []array;
}

template<class T>
void Stack<T>::Empty()
{
    topOfStack = -1;
}

#endif // STACK_H_INCLUDED
