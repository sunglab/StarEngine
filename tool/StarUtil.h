
//
//  StarUtil.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef STARUTIL_H
#define STARUTIL_H
#include <algorithm>
/*
 *  singleton
 */
template <typename T>
class StarSingleton
{
    
public:
    static T* share()
    {
        if(_single)
            return _single;
        else
            return _single = new T;
    };
    static void release()
    {
            delete _single;
            _single = false;
    }
private:
    static T* _single;
};

template <typename T> T* StarSingleton<T>::_single = 0;

/*
 * global functions for useful
 */
#define starSwap std::swap
#define starMin std::min
#define starMax std::max
/*
template<typename T>
void starSwap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T starMin(T a, T b)
{
    if(a<b)
        return a;
    else
        return b;
}

template<typename T>
T starMax(T a, T b)
{
    if(a>b)
        return a;
    else
        return b;
}
*/
template<typename T>
T starConstrain(T c, T a, T b)
{
    if(c<a)
        return a;
    else if(b<c)
        return b;
    else
        return c;
}

template<typename T>
void starDeleteArray(T bye)
{
    if(bye) delete[] bye;
}

template<typename T>
void starDeleteVar(T bye)
{
    if(bye) delete bye;
}

#endif
