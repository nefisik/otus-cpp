#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cstdlib>

// void print(const std::vector<int>& ip_pool);

void print(const std::vector<std::vector<int>>&);

std::vector<std::vector<int>>& sort(std::vector<std::vector<int>>&);

std::vector<std::vector<int>> get_1(const std::vector<std::vector<int>>&);

std::vector<std::vector<int>> get_46_70(const std::vector<std::vector<int>>&);

std::vector<std::vector<int>> get_any_46(const std::vector<std::vector<int>>&);

std::vector<std::vector<int>> get_data();