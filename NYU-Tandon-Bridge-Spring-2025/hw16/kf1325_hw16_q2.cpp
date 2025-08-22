#include<iostream>
#include <vector>

using namespace std;

template <typename T>
class VectorQueue
{
private:
    vector<T> data;
    int start;

public:
    VectorQueue() : start(0) {}

    void push(const T& value)
    {
        data.push_back(value);
    }

    void pop()
    {
        if (empty())
            throw out_of_range("Queue is empty");
        ++start;
        if (start >= data.size())
        {
            data.clear();
            start = 0;
        }
    }

    T& front()
    {
        if (empty())
            throw out_of_range("Queue is empty");
        return data[start];
    }

    T& back()
    {
        if (empty())
            throw out_of_range("Queue is empty");
        return data.back();
    }

    bool empty() const
    {
        return start >= data.size();
    }

    int size() const
    {
        return data.size() - start;
    }

    void clear()
    {
        data.clear();
        start = 0;
    }
};

int main()
{
    VectorQueue<int> q;

    for (int i = 0; i < 10; ++i)
        q.push(i);

    cout
        << "queue size: "
        << q.size()
        << endl;

    cout
        << "queue front: "
        << q.front()
        << endl;

    cout
        << "queue back: "
        << q.back()
        << endl;
    return 0;
}