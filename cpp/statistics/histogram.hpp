#include <vector>
#include "structure.h"


//Todo move to structure.hpp


//Todo move to structure.hpp

template<typename T>
struct Histogram
{
    struct Bin{
        T value;
        int count;
    };

    SparseVector<Bin> bins; // indexed bins
};

template<typename T>
inline std::pair<size_t, T> linear_binning(const T &value, size_t nBins , const Range<T> &range, bool countOutOfRange = false)
{
    T binWidth = (range.max - range.min) / nBins;
    size_t binId = size_t(value - range.min) / binWidth;
    T binVal = value + (binWidth/2);
    binVal -= fmod(binVal , binWidth);
    return std::make_pair(binId, binVal);
}

template<typename T, typename F>
inline Histogram<T> compute_histogram(const std::vector<T> &values, F&& biningFunctor)
{
    Histogram<T> rslt;
    for (const auto &val : values)
    {
        std::pair<size_t, T> binnedValue = std::forward<F>(biningFunctor)(val);
        auto &bin = rslt.bins[binnedValue.first];
        bin.count++;
        bin.value = binnedValue.second;
    }
    return rslt;
}