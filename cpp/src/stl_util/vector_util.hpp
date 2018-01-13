// Copyright 2018 Philip Krejov
#ifndef CPP_VECTOR_UTIL_HPP_
#define CPP_VECTOR_UTIL_HPP_

#include <vector>

namespace pk {
    template<typename T>
    std::vector<std::vector<T> > transpose(
        const std::vector<std::vector<T> > &data) {
        // https://stackoverflow.com/questions/6009782/how-to-pivot-a-vector-of-vectors
        // this assumes that all inner vectors have the same size and
        // allocates space for the complete result in advance
        std::vector<std::vector<T> > result(data[0].size(),
            std::vector<T>(data.size()));
        for (std::vector<T>::size_type i = 0; i < data[0].size(); i++)
            for (std::vector<T>::size_type j = 0; j < data.size(); j++) {
                result[i][j] = data[j][i];
            }
        return result;
    }
}  // namespace pk

#endif  // CPP_VECTOR_UTIL_HPP_
