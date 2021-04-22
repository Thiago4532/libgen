#ifndef _LIBGEN_VECTOR_HPP
#define _LIBGEN_VECTOR_HPP

#include <vector>
#include "randomizer.hpp"

namespace libgen {

template<typename T, typename Randomizer = randomizer<T>>
class vector : public std::vector<T> {
public:
    template<typename Generator>
    void generate(int sz, std::pair<T, T> const& range, Generator& gen) {
        Randomizer rng(range.first, range.second);

        this->resize(sz);

        for (int i = 0; i < sz; i++)
            this->at(i) = rng(gen);
    }
private:
};

}

#endif
