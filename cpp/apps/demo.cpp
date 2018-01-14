#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "stl_typedefs.hpp"
#include "range.hpp"
#include "histogram.hpp"


int main(int argc, char** argv)
{ 
    doctest::Context context;
    int res = context.run();

    std::vector<float> values = { 0.234f,12.45f, 9.324f, -3.34f, 8.0f, -2.98f, 20.0f, -20.0f, 0.0f };
    
    auto hist = compute_histogram(values, 4, Range<float>{-20.0f, 20.0f}, linear_quantize);
    
}