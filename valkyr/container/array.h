#pragma once

#include "../core/vplatform.h"
#include <array>

namespace valkyr
{
template <typename T, vsize N>
using array = std::array<T, N>;

} // namespace valkyr