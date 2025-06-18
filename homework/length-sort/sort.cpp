#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& fl)
{
    std::deque<std::string> dq{fl.begin(), fl.end()};

    std::sort(dq.begin(), dq.end());
    std::sort(dq.begin(), dq.end(), [](const std::string& a, const std::string& b){ return a.size() < b.size();});

    return dq;
}