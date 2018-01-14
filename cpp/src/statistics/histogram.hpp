#include <vector>
#include "range.hpp"

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