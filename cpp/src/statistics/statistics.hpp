#pragma once

#include <numeric>
#include "histogram.hpp"
#include "gaussian.hpp"
#include "measures.hpp"

template<typename Iter>
auto mean(const Iter &first, const Iter &last)
{
	using value_type = typename std::iterator_traits<Iter>::value_type;
	value_type sum = std::accumulate(first, last, value_type());
	size_t count = std::distance(first, last);
	return sum / count;
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("mean test")
{
	std::vector<float> values = { 0.0f, 10.0f, 25.0f, 50.0f};
	float rslt = mean(values.begin(), values.end());
	CHECK(rslt == doctest::Approx(21.25f));
}
#endif DOCTEST_LIBRARY_INCLUDED

template<typename Iter>
auto variance(const Iter &first, const Iter &last)
{
	auto meanVal = mean(first, last);
	using value_type = typename std::iterator_traits<Iter>::value_type;

	value_type sumDiffs = std::accumulate(first, last, value_type(), [meanVal](value_type &prev, value_type& a) { return prev + ((meanVal - a)*(meanVal - a)); });
	return sumDiffs / std::distance(first, last);
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("variance test")
{
	std::vector<float> values = { 600.0f, 470.0f, 170.0f, 430.0f, 300.0f };
	CHECK(variance(values.begin(), values.end()) == doctest::Approx(21704.0f));
}
#endif DOCTEST_LIBRARY_INCLUDED

template<typename Iter>
auto stddev(const Iter &first, const Iter &last)
{
	return sqr
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("variance test")
{
	std::vector<float> values = { 600.0f, 470.0f, 170.0f, 430.0f, 300.0f };
	CHECK(variance(values.begin(), values.end()) == doctest::Approx(21704.0f));
}
#endif DOCTEST_LIBRARY_INCLUDED
