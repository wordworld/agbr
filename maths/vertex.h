//
// Created by fstone on 2022/7/2.
//

#ifndef AGBR_VERTEX_H
#define AGBR_VERTEX_H

#include <algorithm>

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
                data[i] = *(it++);
        }

        T &operator[](const int index) {
            return data[index];
        }

        const T operator[](const int index) const {
            return data[index];
        }
    };

    template<typename T>
    union vtx2
    {
        vtx<2, T> of;
        struct { T x, y; };
        struct { T u, v; };
        struct { T a, b; };

        vtx2(std::initializer_list<T> list) : of(list) {}
    };

    template<typename T>
    union vtx3
    {
        vtx<3, T> of;
        struct { T x, y, z; };
        struct { T u, v, w; };

        vtx3(std::initializer_list<T> list) : of(list) {}
    };

    template<typename T>
    union vtx4
    {
        vtx<4, T> of;
        struct { T x, y, u, v; };
        struct { T r, g, b, a; };

        vtx4(std::initializer_list<T> list) : of(list) {}
    };

    using vtx2u = vtx2<uint32_t>;
    using vtx2i = vtx2<int32_t>;
    using vtx2l = vtx2<int64_t>;
    using vtx2f = vtx2<float>;
    using vtx2d = vtx2<double>;

    using vtx3u = vtx3<uint32_t>;
    using vtx3i = vtx3<int32_t>;
    using vtx3l = vtx3<int64_t>;
    using vtx3f = vtx3<float>;
    using vtx3d = vtx3<double>;

    using vtx4u = vtx4<uint32_t>;
    using vtx4i = vtx4<int32_t>;
    using vtx4l = vtx4<int64_t>;
    using vtx4f = vtx4<float>;
    using vtx4d = vtx4<double>;
}
#endif //AGBR_VERTEX_H
