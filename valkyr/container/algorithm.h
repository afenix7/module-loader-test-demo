#pragma once

#include <algorithm>

template <class Iter, class F>
using vforeach = std::for_each<Iter, F>;