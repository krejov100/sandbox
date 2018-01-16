#pragma once

#include <numeric>
#include "histogram.hpp"
#include "gaussian.hpp"

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
