#pragma once

#include <algorithm>
namespace valkyr {
	template <class K, class V, class F>
	using vforeach = std::for_each<K, V, F>;
};