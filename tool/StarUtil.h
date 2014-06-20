#ifndef STARUTIL_H
#define STARUTIL_H

class StarUtil
{
public:
    

};


template<typename T>
void _swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}
template<typename T>
T _min(T a, T b)
{
    if(a<b)
        return a;
    else
        return b;
}

template<typename T>
T _max(T a, T b)
{
    if(a>b)
        return a;
    else
        return b;
}

template<typename T>
T _constrain(T c, T a, T b)
{
    if(c<a)
        return a;
    else if(b<c)
        return b;
    else
        return c;
}


#endif
