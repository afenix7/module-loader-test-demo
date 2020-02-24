#pragma once

#include "vplatform.h"
#include <vector>

namespace valkyr
{
template <typename T>
using vec = std::vector<T>;

template <typename T, vsize N>
using smallVec = std::vector<T，N>;

} // namespace valkyr