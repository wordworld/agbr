//
// Created by fstone on 2022/7/2.
//

#ifndef AGBR_VERTEX_H
#define AGBR_VERTEX_H

#include <algorithm>
#include <libpp/macros.h>

namespace agbr {
    template<int N, typename T>
    class vtx
    {
    private:
        T data[N];

    public:
        vtx() : data(size_t(N)) {}

        vtx(std::initializer_list<T> list) {
            auto it = list.begin();
            for (int i = 0; i < std::min(N, (int) list.size()); i++)
                data[i] = *it++;
        }

        T &operator[](const int index) {
            return data[index];
        }

        const T operator[](const int index) const {
            return data[index];
        }
    };


#define DECL_UNION_T(...) struct { T PP_INTERSPERSE(PP_SEP_COMMA, __VA_ARGS__); }
#define DECL_UNION_VTX(N, ...)                                          \
    template<typename T>                                                \
    union PP_CONCAT(vtx,N){                                             \
        vtx<N,T> of;                                                    \
        PP_MAP_LISTS(DECL_UNION_T, PP_SEP_SEMICOLON, __VA_ARGS__);      \
        operator vtx<N, T>() { return of; }                             \
        PP_CONCAT(vtx,N)(std::initializer_list<T> list) : of(list) {}   \
    };                                                                  \
    using PP_FOLDL(PP_CONCAT,vtx,N,u) = PP_CONCAT(vtx,N)<uint32_t>;     \
    using PP_FOLDL(PP_CONCAT,vtx,N,i) = PP_CONCAT(vtx,N)<int32_t>;      \
    using PP_FOLDL(PP_CONCAT,vtx,N,l) = PP_CONCAT(vtx,N)<int64_t>;      \
    using PP_FOLDL(PP_CONCAT,vtx,N,f) = PP_CONCAT(vtx,N)<float>;        \
    using PP_FOLDL(PP_CONCAT,vtx,N,d) = PP_CONCAT(vtx,N)<double>

    // vtx2[uilfd]
    DECL_UNION_VTX(2, (x, y), (u, v), (w, h), (width, height));
    // vtx3[uilfd]
    DECL_UNION_VTX(3, (x, y, z), (r, g, b), (u, v, w));
    // vtx4[uilfd]
    DECL_UNION_VTX(4, (x, y, z, w), (r, g, b, a));
}
#endif //AGBR_VERTEX_H
