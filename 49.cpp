#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution_49 {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> umap;
        for (auto str : strs) {
            std::string temp = str;
            std::sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }
        std::vector<std::vector<std::string>> result;
        result.reserve(umap.size());
        for (auto [fir, sec]: umap) {
            result.push_back(sec);
        }
        return result;
    }
};