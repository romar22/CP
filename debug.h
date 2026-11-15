#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

namespace dbg {

    // Check if T is a pair
    template <typename T>
    struct is_pair : false_type {};

    template <typename A, typename B>
    struct is_pair<pair<A, B>> : true_type {};

    // Check if T is iterable (vector, array, set, map, etc.)
    template <typename T, typename = void>
    struct is_iterable : false_type {};

    template <typename T>
    struct is_iterable<T, void_t<
        decltype(begin(declval<const T&>())),
        decltype(end(declval<const T&>()))
    >> : true_type {};

    // Check if T is a string
    template <typename T>
    struct is_string : false_type {};

    template <>
    struct is_string<string> : true_type {};

    // Main print function
    template <typename T>
    void print(const T& x) {
        using U = decay_t<T>;

        if constexpr (is_string<U>::value) {
            cerr << '"' << x << '"';
        }
        else if constexpr (is_pair<U>::value) {
            cerr << "{";
            print(x.first);
            cerr << ", ";
            print(x.second);
            cerr << "}";
        }
        else if constexpr (is_iterable<U>::value) {
            cerr << "[";

            bool first = true;

            for (const auto& item : x) {
                if (!first) cerr << ", ";
                print(item);
                first = false;
            }

            cerr << "]";
        }
        else {
            cerr << x;
        }
    }

    // Debug function
    template <typename T>
    void debug(const char* name, const T& x) {
        cerr << name << " = ";
        print(x);
        cerr << '\n';
    }
}

#define debug(x) dbg::debug(#x, x)

#endif
