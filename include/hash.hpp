//
// Created by jaggernaute on 5/1/22.
//

#ifndef BOWOT_HASH_HPP
#define BOWOT_HASH_HPP

constexpr auto hash(const char *s, int off = 0) -> unsigned int {
    return !s[off] ? 5381 : (hash(s, off+1)*33) ^ s[off];
}


#endif // BOWOT_HASH_HPP
