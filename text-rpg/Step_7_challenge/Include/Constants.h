#pragma once

#include <limits>

namespace Constants
{
    constexpr int IntMax =
        std::numeric_limits<int>::max();

    constexpr int IntMin =
        std::numeric_limits<int>::min();

    constexpr unsigned int UIntMax =
        std::numeric_limits<unsigned int>::max();
}