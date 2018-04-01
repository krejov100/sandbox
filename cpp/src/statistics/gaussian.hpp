#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include "linalg.h"

template<typename T>
class UniVariantGaussian
{
public:
    T mu;
    float sig;
    float sig2;
};

template<typename T>
float closed_form_intergral_of_gaussian_products(const UniVariantGaussian<T>& a, const UniVariantGaussian<T>& b)
{
    auto a_sig2_plus_b_sig2 = a.sig2 + b.sig2;
    auto dist = linalg::distance(a.mu, b.mu);
    return 2 * M_PI*((a.sig2 * b.sig2) / a_sig2_plus_b_sig2) * std::exp(-((dist*dist) / a_sig2_plus_b_sig2));
}

