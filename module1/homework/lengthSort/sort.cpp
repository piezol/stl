#include "sort.hpp"

#include <iostream>
auto iterToInsertIntoSortedDeque(const std::deque<std::string>& sortedDeque,
                                 const std::string& strToInsert) {
    if (sortedDeque.size() == 0)
        return sortedDeque.end();

    size_t leftBound = 0;
    auto rightBound = sortedDeque.size();

    do {
        auto middle = leftBound + (rightBound - leftBound) / 2;
        const auto& middleElement = sortedDeque[middle];
        if (middleElement.size() > strToInsert.size() or
            (middleElement.size() == strToInsert.size() and middleElement >= strToInsert)) {  // should be a predicate but we don't know them yet :)
            rightBound = middle;
        } else {
            leftBound = std::max(leftBound + 1, middle);
        }

    } while (leftBound < rightBound);

    return std::next(sortedDeque.begin(), leftBound);
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& fList) {
    std::deque<std::string> sortedStrings;
    for (const auto& str : fList) {
        auto posToInsert = iterToInsertIntoSortedDeque(sortedStrings, str);
        sortedStrings.insert(posToInsert, str);
    }
    return sortedStrings;
}
