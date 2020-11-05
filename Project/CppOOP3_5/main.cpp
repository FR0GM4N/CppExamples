#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Shape
{

};

// Shape - Rectangle : is-a ����
class Rectangle : public Shape
{

};


// Queue - vector : has-a ����
class Queue0
{
private:
    vector<int> v;
public:
    void push(int value)
    {
        v.push_back(value);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back();
    }
};


// public ����� vector�� ��� �������̽��� public���� ����Ѵ�.
// private ����� vector�� ��� �������̽��� private���� ����Ѵ�.
// ���� Queue1������ vector�� ������ø� ����� �� ������ �ܺο����� ����� �� ����
// �ظ��ϸ� ������� ����.
// vector�� protected ��� �Լ��� ����ϰ� ���� ��� ����ϸ� ����
// �����ڸ� �����ϸ� private ���(struct�� ���� public)

class Queue1 : private vector<int>
{
public:
    void push(int value)
    {
        push_back(value);
    }

    void pop()
    {
        pop_back();
    }

    int top()
    {
        return back();
    }
};


// vector�� �������̽��� Queue2�� �ڽĿ��Ա��� �����ϱ� ���� protected ����� �Ѵ�
class Queue2 : protected vector<int>
{
public:
    virtual void push(int value)
    {
        push_back(value);
    }

    virtual void pop()
    {
        pop_back();
    }

    virtual int top()
    {
        return back();
    }

    virtual ~Queue2()
    {

    }
};


class PriorityQueue : public Queue2
{
public:
    virtual void push(int value) override
    {
        Queue2::push(value);
        push_heap(begin(), end());
    }

    virtual void pop() override
    {
        pop_heap(begin(), end());
        Queue2::pop_back();
    }

    virtual int top() override
    {
        return front();
    }
};



int main()
{
    PriorityQueue pq;
    pq.push(10);
    pq.push(100);
    pq.push(0);


    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();
}