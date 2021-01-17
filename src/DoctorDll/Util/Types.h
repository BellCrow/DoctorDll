#pragma once
#include <memory>
#include <vector>

namespace Util {
	template <typename T>
	using sp = std::shared_ptr<T>;
}
