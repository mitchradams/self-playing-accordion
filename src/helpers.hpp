#include <string>
#include <vector>

namespace accordion_bot {

template<typename T>
std::string toString(std::vector<T> vec) {
    std::string result = "[";
    for (const auto& item : vec) {
        result += toString(item) + ", ";
    }
    if (!vec.empty()) {
        result.pop_back(); // Remove last space
        result.pop_back(); // Remove last comma
    }
    result += "]";
    return result;
}

} // namespace accordion_bot