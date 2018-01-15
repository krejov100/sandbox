#include <vector>
#include "range.hpp"
#include <numeric>

template<typename T>
struct Histogram
{
    struct Bin{
        Range<T> range;
        int count;
    };
    SparseVector<Bin> bins; // indexed bins
};

inline std::pair<size_t, Range<float>> linear_quantize(const float &value, size_t steps, const Range<float> &minMax)
{
    float stepWidth = (minMax.max - minMax.min) / steps;
    size_t stepId = size_t((value - minMax.min) / stepWidth);
 
    float val = value;
    val += val == 0 ? stepWidth / 2 : 0; // zero condition
    float rebased = val / stepWidth;
    float lowerPoint = floor(rebased);
    float upperPoint = ceil(rebased);
    if (std::abs(lowerPoint - upperPoint) < 0.5f) // multiple of base condition
        upperPoint++;
    lowerPoint *= stepWidth; 
    upperPoint *= stepWidth;

    return std::make_pair(stepId, Range<float>{lowerPoint, upperPoint});
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("linear_quantize test")
{
	auto rslt = linear_quantize(0.234f, 4, Range<float>{-20.0f, 20.0f});
	CHECK(rslt.first == 2);
	CHECK(rslt.second.min == doctest::Approx(0.0f));
	CHECK(rslt.second.max == doctest::Approx(10.0f));
	
	rslt = linear_quantize(0.234f, 4, Range<float>{0, 20.0f});
	CHECK(rslt.first == 0);
	CHECK(rslt.second.min == doctest::Approx(0.0f));
	CHECK(rslt.second.max == doctest::Approx(5.0f));
}
#endif DOCTEST_LIBRARY_INCLUDED


template<typename T, typename F>
inline Histogram<T> compute_histogram(const std::vector<T> &values, size_t nBins, const Range<T> &minMax, F&& biningFunctor)
{
    Histogram<T> rslt;
    for (const auto &val : values)
    {
        if (in_range_exc(minMax, val))
        {
            auto binnedValue = std::forward<F>(biningFunctor)(val, nBins, minMax);
            auto &bin = rslt.bins[binnedValue.first];
            bin.count++;
            bin.range = binnedValue.second;
        }
    }
    return rslt;
}

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE("compute_histogram test")
{
	std::vector<float> values = { 0.234f,12.45f, 9.324f, -3.34f, 8.0f, -2.98f, -20.0f, 0.0f };
	auto hist = compute_histogram(values, 4, Range<float>{-20.0f, 20.0f}, linear_quantize);
	const size_t totalCount = std::accumulate(hist.bins.begin(), hist.bins.end(), 0, [](const size_t previous, const std::pair<size_t, Histogram<float>::Bin> &p) { return previous + p.second.count; });
	
	CHECK(hist.bins.size() == 4);
	CHECK(totalCount == values.size());
	CHECK(hist.bins[0].range.min == doctest::Approx(-20.0f));
	CHECK(hist.bins[0].range.max == doctest::Approx(-10.0f));
}
#endif DOCTEST_LIBRARY_INCLUDED