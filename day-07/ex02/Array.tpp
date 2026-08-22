#ifndef ARRAY_TPP
#define ARRAY_TPP


template <typename T>
Array<T>::Array(): row(NULL), len(0)
{}

template <typename T>
Array<T>::Array(unsigned int i): row(new T[i]()), len(i)
{}

template <typename T>
Array<T>::Array(const Array& other): row(new T[other.len]()), len(other.len)
{
    for (unsigned int i = 0; i < len; i++)
        row[i] = other.row[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] row;
        len = other.len;
        row = new T[len]();
        for (unsigned int i = 0; i < len; i++)
            row[i] = other.row[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] row;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= len)
        throw OutOfRangeException();
    return row[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= len)
        throw OutOfRangeException();
    return row[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return len;
}


#endif