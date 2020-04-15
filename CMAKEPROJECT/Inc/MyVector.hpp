#include <iostream>
#include <cstring>
using std::ostream;
using std::istream;

template <typename T>
class MyVector
{
    private:
        int vec_Len;
        int vec_capacity;
        T * m_element;
    public:
        
        MyVector() :vec_capacity(16) , vec_Len(0) 
        {
            m_element = new T[vec_capacity];
        }
        
        MyVector(int len) :vec_Len(len)
        {
            vec_capacity = len + 20;
            m_element = new T[vec_capacity];
        }

        MyVector(int len,T element) :vec_Len(len)
        {
            vec_capacity = len + 20;
            m_element = new T[vec_capacity];
            for ( int i = 0;i < vec_Len ; i++)  
            m_element[i] = element;
            //memcpy(&m_element[i],&element,sizeof(T));
        }

        ~MyVector()
        {
            delete[]    m_element;
        }

        void Push_back(const T element);

        void Sort();

        T & operator [] (const int Index);

        template<typename T2>
        friend ostream & operator << (ostream & out , MyVector<T2> & vec);


    protected:
};

template <typename T>
ostream & operator << (ostream & out , MyVector<T> & vec)
{
    for ( int i = 0 ; i < vec.vec_Len ;i++ )
    out << vec.m_element[i] << ',';
    return out; 
}

template<typename T>
T & MyVector<T>::operator [] (const int Index)
{
    return  m_element[Index];
}