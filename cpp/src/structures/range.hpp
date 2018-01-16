#pragma once

template<typename T>
struct Range
{
    T min;
    T max;
};

template<typename T>
inline bool in_range_inc(const Range<T> &r, T val)
{
    return r.min <= val && val <= r.max;
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("in_range_exc test")
{
	auto r = Range<float>{ 0.0f, 10.0f };
	CHECK(in_range_inc(r, 0.0f) == true);
	CHECK(in_range_inc(r, 5.0f) == true);
	CHECK(in_range_inc(r, 10.0f) == true);
	CHECK(in_range_inc(r, 15.0f) == false);
}
#endif DOCTEST_LIBRARY_INCLUDED

template<typename T>
inline bool in_range_exc(const Range<T> &r, T val)
{
    return r.min <= val && val < r.max;
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("in_range_exc test")
{
	auto r = Range<float>{ 0.0f, 10.0f };
	CHECK(in_range_exc(r, 0.0f) == true);
	CHECK(in_range_exc(r, 5.0f) == true);
	CHECK(in_range_exc(r, 10.0f) == false);
	CHECK(in_range_exc(r, 15.0f) == false);
}
#endif DOCTEST_LIBRARY_INCLUDED

template<typename T>
inline T middle(const Range<T> &r)
{
	return (r.max - r.min) / 2.0f + r.min;
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("middle test")
{
	CHECK(middle(Range<float>{25.0f,75.0f}) == doctest::Approx(50.0f));
}
#endif DOCTEST_LIBRARY_INCLUDED