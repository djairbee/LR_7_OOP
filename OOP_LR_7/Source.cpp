#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>
#include <Windows.h>

using namespace std;

int size = 0;

template<class T>
class Queue {

private:
    queue<T> MyQueue;
    queue<T> MyQueue_copy;
public:
    Queue() { ; }

    Queue(int data)
    {
        for (int i = 0; i < data; i++)
        {
            MyQueue.push(i + 1);
        }
    }
    ~Queue()
    {
        cout << "Destructor " << endl;
    }

    void operator += (T element)
    {
        MyQueue.push(element);
    }
    void operator -- (int value)
    {
        MyQueue.pop();
    }



    friend istream& operator >> (istream& in, Queue<T>& obj)
    {
        static int size = 0;
        cout << "Input quantity of queue elements: ";
        cin >> size;

        T elem;
        while (size > 0)
        {
            in >> elem;
            obj.MyQueue.push(elem);
            size--;
            if (in.eof())
            {
                break;
            }
        }
        return in;
    }

    friend ostream& operator << (ostream& os, Queue<T>& obj)
    {

        obj.MyQueue_copy = obj.MyQueue;

        while (!obj.MyQueue_copy.empty())
        {
            os << obj.MyQueue_copy.front() << endl;
            obj.MyQueue_copy.pop();
        }
        cout << endl << endl << endl;

        return os;
    }

    int check()
    {
        int check = 1;
        this->MyQueue_copy = this->MyQueue;

        T min = this->MyQueue_copy.front();
        while (!this->MyQueue_copy.empty())
        {
            if (this->MyQueue_copy.front() >= min)
            {
                min = this->MyQueue_copy.front();
            }

            else
            {
                check = -1;
                break;
            }
            this->MyQueue_copy.pop();
        }

        if (check == 1)
        {
            return check;
        }

        this->MyQueue_copy = this->MyQueue;
        T max = this->MyQueue_copy.front();
        while (!this->MyQueue_copy.empty())
        {
            if (this->MyQueue_copy.front() <= min)
            {
                min = this->MyQueue_copy.front();
            }

            else
            {
                check = -2;
                break;
            }
            this->MyQueue_copy.pop();
        }
        if (check == -1)
        {
            return check;
        }
        return 0;

    }

    void check_main()
    {
        int check = this->check();

        if (check == 1)
        {
            cout << endl << endl << " Порядок зростаючий" << endl << endl;
        }
        else if (check == -1)
        {
            cout << endl << endl << " Порядок спадний" << endl << endl;
        }
        else
        {
            cout << endl << endl << " Ні зростаючий, ні спадний" << endl << endl;
        }
    }
};


int main()
{
    system("chcp 1251");
    system("cls");

    string name1 = "D:\\OOP_7\\numbers.txt";
    string name2 = "D:\\OOP_7\\text.txt";


    fstream int_file;
    fstream string_file;

    int_file.open(name1, fstream::in);
    string_file.open(name2, fstream::in);

    Queue <int> intQueue;
    Queue <string> stringQueue;




    int_file >> intQueue;
    string_file >> stringQueue;



    int_file.close();
    string_file.close();

    cout << endl;

    cout << "Int Queue: " << endl;
    cout << intQueue;

    intQueue.check_main();

    cout << "String Queue: " << endl;
    cout << stringQueue;

    intQueue--;
    stringQueue--;

    cout << "Int Queue with first element deleted " << endl;
    cout << intQueue;
    cout << "String Queue with first element deleted" << endl;
    cout << stringQueue;

    intQueue += 999999999;
    stringQueue += "Test_line";

    cout << "Int Queue with newly added element:  " << endl;
    cout << intQueue;
    cout << "String Queue with newly added element:" << endl;
    cout << stringQueue;






    int_file.open(name1, fstream::out);
    string_file.open(name2, fstream::out);

    int_file << intQueue;
    string_file << stringQueue;

    int_file.close();
    string_file.close();

    cout << endl;
    return 0;
}