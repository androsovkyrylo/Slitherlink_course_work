#pragma once
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <utility>

struct PairHash {
    size_t operator()(const std::pair<int,int>& p) const noexcept {
        return std::hash<int>()(p.first) * 100003 ^ std::hash<int>()(p.second);
    }
};

struct DSU {
    std::unordered_map<int,int> parent;
    std::unordered_map<int,int> rank_;

    void make(int x) {
        if (!parent.count(x)) { parent[x] = x; rank_[x] = 0; }
    }

    int find(int x) {
        auto it = parent.find(x);
        if (it == parent.end()) return -1;
        while (it->second != x) {
            it->second = parent[it->second];
            x = it->second;
            it = parent.find(x);
        }
        return x;
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == -1 || ry == -1) return true;
        if (rx == ry) return false;
        if (rank_[rx] < rank_[ry]) std::swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
        return true;
    }

    bool connected(int x, int y) const {
        auto fx = const_cast<DSU*>(this)->find(x);
        auto fy = const_cast<DSU*>(this)->find(y);
        return fx != -1 && fy != -1 && fx == fy;
    }

    size_t component_count() const {
        std::unordered_set<int> roots;
        for (auto& [k,v] : parent) {
            roots.insert(const_cast<DSU*>(this)->find(k));
        }
        return roots.size();
    }

    bool empty() const { return parent.empty(); }
};
