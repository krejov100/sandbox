#include <linalg.h>

namespace pk {
    template<T>
    struct Rect_<T>
    {
        T tl;
        T bl;
        T size;
    };

    typedef Rect_<linalg::aliases::float2> RectF;
    typedef Rect_<linalg::aliases::int2> Rect;
}