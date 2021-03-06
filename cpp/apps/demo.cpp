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
}