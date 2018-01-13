#include "stl_typedefs.hpp"
#include "range.hpp"
#include "histogram.hpp"


void main()
{ 
    std::vector<float> values = { 0.234f,12.45f, 9.324f, -3.34f, 8.0f, -2.98f, 20.0f, -20.0f, 0.0f };
    
    auto hist = compute_histogram(values, 4, Range<float>{-20.0f, 20.0f}, linear_quantize);
    
}