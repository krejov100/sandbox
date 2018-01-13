#pragma once

template<typename T>
struct Range
{
    T min;
    T max;
};

template<typename T>
bool in_range_inc(Range<T> r, T val)
{
    return r.min <= val && val <= r.max;
}

template<typename T>
bool in_range_exc(Range<T> r, T val)
{
    return r.min <= val && val < r.max;
}