#pragma once

namespace algos {

    template<class I, class Predicate>
    bool any_of(const I &begin, const I &end, Predicate pred) {
        for (auto iter = begin; iter != end; iter = std::next(iter)) {
            if (pred(*iter))
                return true;
        }
        return false;
    }

    template<class I, class Predicate>
    bool one_of(const I &begin, const I &end, Predicate pred) {
        int count = 0;
        for (auto iter = begin; iter != end; iter = std::next(iter)) {
            if (pred(*iter))
                count++;
        }
        return count == 1;
    }

    template<class I, class T>
    T find_not(const I &begin, const I &end, const T &val) {
        for (auto iter = begin; iter != end; std::next(iter)) {
            if (*iter == val)
                continue;
            return *iter;
        }
    }

}