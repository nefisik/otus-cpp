#include "ip_filter.h"

void print(const std::vector<std::vector<int>>& ip_pool)
{
    for (auto it_i = ip_pool.cbegin(); it_i < ip_pool.cend(); ++it_i)
    {
        for (auto it_j = it_i->cbegin(); it_j < it_i->cend(); ++it_j)
        {
            std::cout << *it_j;
            if (it_j != it_i->cend() - 1)
                std::cout << ".";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>>& sort(std::vector<std::vector<int>>& ip_pool)
{
    auto comp = [](const auto& v1, const auto& v2) {
                    for (unsigned int j = 0; j < 4; ++j) {
                        if (v1.at(j) > v2.at(j)) {
                            return v1 > v2;
                        }
                    }
                    return v1 == v2;
    };

    std::sort(ip_pool.begin(), ip_pool.end(), comp);
    return ip_pool;
}

std::vector<std::vector<int>> get_1(const std::vector<std::vector<int>>& ip_pool)
{
    std::vector<std::vector<int>> ip_pool_1;
    for (unsigned int i = 0; i < ip_pool.size(); ++i)
    {
        if (ip_pool.at(i).at(0) == 1)
        {
            ip_pool_1.emplace_back(ip_pool.at(i));
        }
    }
    return ip_pool_1;
}

std::vector<std::vector<int>> get_46_70(const std::vector<std::vector<int>>& ip_pool)
{
    std::vector<std::vector<int>> ip_pool_46_70;
    for (unsigned int i = 0; i < ip_pool.size(); ++i)
    {
        if (ip_pool.at(i).at(0) == 46 && ip_pool.at(i).at(1) == 70)
        {
            ip_pool_46_70.emplace_back(ip_pool.at(i));
        }
    }
    return ip_pool_46_70;
}

std::vector<std::vector<int>> get_any_46(const std::vector<std::vector<int>>& ip_pool)
{
    std::vector<std::vector<int>> ip_pool_any_46;
    for (const auto& i : ip_pool)
    {
        for (const auto& j : i)
        {
            if (j == 46)
            {
                ip_pool_any_46.emplace_back(i);
                break;
            }
        }
    }
    return ip_pool_any_46;
}

std::vector<std::vector<int>> get_data()
{
    std::vector<std::vector<int>> ip_pool;
    for(std::string line; std::getline(std::cin, line);)
    {
        if (line == "")
            break;
        std::vector<int> v;
        std::string ip_n;
        for (const auto& i : line)
        {
            if (i == '0' || i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6'|| i == '7' || i == '8'|| i == '9')
            {
                ip_n += i;
            }
            else if (i == '.')
            {
                v.emplace_back(stoi(ip_n));
                ip_n.clear();
            }
            else if (i == '\t')
            {
                v.emplace_back(stoi(ip_n));
                ip_n.clear();
                ip_pool.emplace_back(v);
                v.clear();
                break;
            }
        }
    }
    return ip_pool;
}