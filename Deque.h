#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
class Deque
{
private:
    size_t size;
    size_t count;
    T * data;
public:
    Deque();
    Deque(size_t size);
    Deque(const Deque &dq);
    ~Deque();

    Deque<T> & operator=(const Deque<T> &dq);

    bool pushBack(T value);
    bool pushFront(T value);
   void popBack(T value);
  void popFront(T value);
    void topBack(T &value) const;
    void topFront(T &value) const;
    void clear();
    bool isEmpty()const;
    size_t Size()const;
    void print() const;
};

template<typename T>
Deque<T>::Deque()
{
    size = 1;
    count = 0;
    data = new T[size];
}

template<typename T>
Deque<T>::Deque(size_t size)
{
    if(size < 1)
    {
        size = 1;
    }

    this->size = size;
    this->count = 0;
    this->data = new T[size];
}

template<typename T>
Deque<T>::Deque(const Deque &dq)
{
    this->size = dq.size;
    this->count = dq.count;
    this->data = new T[dq.size];

    for(size_t i=0;i<dq.count;i++)
    {
        this->data[i]=dq.data[i];
    }
}

template<typename T>
Deque<T>::~Deque()
{
    if(data) delete [] data;
}

template<typename T>
Deque<T> & Deque<T>::operator=(const Deque<T> &dq)
{
    if(data) delete [] data;

    this->size = dq.size;
    this->count = dq.count;
    this->data = new T[dq.size];

    for(size_t i=0;i<dq.count;i++)
    {
        this->data[i]=dq.data[i];
    }
}

template<typename T>
bool Deque<T>::pushBack(T value)
{
    if(count < size)
    {
        data[count] = value;
        ++count;
        return true;
    }
    return false;

}


template<typename T>
bool Deque<T>::pushFront(T value)
{
    int i;
    for (i=count;i>0; i--)
    {
      data[i]=data[i-1];
    }
    if(count < size)
    {

        data[0] = value;
        ++count;
        return true;
    }
    return false;

}



template<typename T>
void Deque<T>::popFront(T value)
{

        data[0] = value;

}

template<typename T>
void Deque<T>::popBack( T value)
{


        data[count-1] = value;

}

template<typename T>
void Deque<T>::topFront(T &value) const
{

        value = data[0];

}

template<typename T>
void Deque<T>::topBack(T &value) const
{

        value = data[count-1];

}


template<typename T>
void Deque<T>::clear()
{
    count = 0;
}

template<typename T>
size_t Deque<T>::Size()const
{
    return size;
}

template<typename T>
bool Deque<T>::isEmpty()const
{
    return count == 0;
}

template<typename T>
void Deque<T>::print() const
{
    cout << "Deque size: " << size << ", count: " << count << endl;
    for(size_t i=0;i<count;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
#endif // DEQUE_H_INCLUDED
