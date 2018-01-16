#pragma once
#include <vector>
#include <functional>
#include <numeric>

float sumOfSquaredResiduals(std::vector<float> y, std::vector<float> x)
{
	return std::inner_product(y.begin(), y.end(), x.begin(), 0.0f, std::plus<float>(), [](auto a, auto b) { return (a - b) * (a - b); });
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("sumOfSquaredResiduals test")
{
	std::vector<float> a = { 45.1f, 12.0f, 23.0f, 15.6f };
	std::vector<float> b = { 45.1f, 14.0f, 23.0f, 15.6f };
	float rslt = sumOfSquaredResiduals(a, b);
	CHECK(rslt == doctest::Approx(4.0f));
}
#endif DOCTEST_LIBRARY_INCLUDED

float rootMeanSquaredError(std::vector<float> y, std::vector<float> x)
{
	float error = sumOfSquaredResiduals(y, x);
	return sqrtf(error / y.size());
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("rootMeanSquaredError test")
{
	std::vector<float> a = { 45.1f, 10.0f, 23.0f, 15.6f };
	std::vector<float> b = { 45.1f, 14.0f, 23.0f, 15.6f };
	float rslt = rootMeanSquaredError(a, b);
	CHECK(rslt == doctest::Approx(2.0f));
}
#endif DOCTEST_LIBRARY_INCLUDED