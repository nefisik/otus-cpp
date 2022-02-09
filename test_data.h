#pragma once

#include <vector>

namespace test
{
	inline static std::vector<std::vector<int>> sort = {
		{5, 94, 213, 44},
		{7, 45, 24, 12},
		{1, 64, 32, 121},
		{53, 21, 12, 57},
		{1, 64, 32, 22},
		{53, 111, 24, 75},
		{212, 43, 64, 125}
	};
	inline static std::vector<std::vector<int>> _1 = {
		{5, 94, 213, 44},
		{7, 45, 24, 12},
		{1, 64, 32, 121},
		{53, 21, 12, 57},
		{1, 64, 32, 22},
		{53, 111, 24, 75},
		{212, 43, 64, 125}
	};
	inline static std::vector<std::vector<int>> _46_70 = {
		{5, 94, 213, 44},
		{46, 70, 24, 12},
		{1, 64, 32, 121},
		{53, 21, 12, 57},
		{1, 64, 32, 22},
		{53, 111, 24, 75},
		{46, 70, 64, 125}
	};
	inline static std::vector<std::vector<int>> any_46 = {
		{5, 46, 213, 44},
		{46, 70, 24, 12},
		{1, 64, 32, 121},
		{53, 21, 12, 57},
		{1, 64, 46, 22},
		{53, 111, 24, 75},
		{46, 70, 64, 125}
	};
} // test

namespace result
{
	inline static std::vector<std::vector<int>> sort = {
		{212, 43, 64, 125},
		{53, 111, 24, 75},
		{53, 21, 12, 57},
		{7, 45, 24, 12},
		{5, 94, 213, 44},
		{1, 64, 32, 121},
		{1, 64, 32, 22}
	};
	inline static std::vector<std::vector<int>> _1 = {
		{1, 64, 32, 121},
		{1, 64, 32, 22}
	};
	inline static std::vector<std::vector<int>> _46_70 = {
		{46, 70, 24, 12},
		{46, 70, 64, 125}
	};
	inline static std::vector<std::vector<int>> any_46 = {
		{5, 46, 213, 44},
		{46, 70, 24, 12},
		{1, 64, 46, 22},
		{46, 70, 64, 125}
	};
} // result