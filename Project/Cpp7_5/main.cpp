#include <iostream>

using namespace std;


void func(int n)
{

}

int main()
{
    {
        // ����ִ�.
        int* p = nullptr;
        cout << p << endl;
    }
    {
        int* p = new int;
        delete p;
        p = nullptr; // ������ ���� nullptr�� �ʱ�ȭ

        // ��ȿ�� ���������� Ȯ��
        if (p != nullptr)
        {
        }
    }
    {
        // C++11 ������ NULL(0)
        func(NULL); // ȣ�� ��

        // ȣ�� �� ��
        //func(nullptr);
    }
    {
        // nullptr�� Ÿ��
        std::nullptr_t n = nullptr;

        // nullptr_t�� ���� � ������ �����ͷε� ��ȯ ����
        int* p = n;
    }
}