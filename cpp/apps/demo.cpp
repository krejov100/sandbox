#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "stl_typedefs.hpp"
#include "range.hpp"
#include "histogram.hpp"


int main(int argc, char** argv)
{ 
    doctest::Context context;
	context.setOption("no-breaks", true);
    int res = context.run();
	if (context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
		return res;          // propagate the result of the tests

    std::vector<float> values = { 0.234f,12.45f, 9.324f, -3.34f, 8.0f, -2.98f, 20.0f, -20.0f, 0.0f };
    
    auto hist = compute_histogram(values, 4, Range<float>{-20.0f, 20.0f}, linear_quantize);
    
	
}