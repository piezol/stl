#include "vowel.hpp"

#include <algorithm>
#include <array>

namespace {
constexpr std::array<char, 6> lowerVowels = {'a', 'e', 'i', 'o', 'u', 'y'};
};

bool isVowel(char c) {
    char lowerC = tolower(c);
    return std::any_of(lowerVowels.begin(), lowerVowels.end(), [lowerC](char v) { return v == lowerC; });
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& str : vec) {
        str.erase(std::remove_if(str.begin(), str.end(), isVowel), str.end());
    }
}
