
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

typedef struct {
    double x;
    double y;
    double z;
} vec_t;

// how far the vector is from (0, 0, 0)
// len((x, y, z)) = sqrt(x^2 + y^2 + z^2)
double vec_len(vec_t a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// difference between vectors, can also be seen as translation
// sub((x1, y1, z1), (x2, y2, z2)) = (x1 - x2, y1 - y2, z1 - x2)
vec_t vec_sub(vec_t a, vec_t b) {
    return (vec_t) {
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
    };
}

// the distance between the vectors
double vec_dist(vec_t a, vec_t b) {
    return vec_len(vec_sub(a, b));
}

bool vec_is_between(vec_t v1, vec_t v2, vec_t check) {
    return vec_dist(v1, check) < vec_dist(v1, v2) && vec_dist(v2, check) < vec_dist(v1, v2);
}

void vec_print(const char *name, vec_t vec) {
    printf("%s = (%.14g, %.14g, %.14g)\n", name, vec.x, vec.y, vec.z);
}

#define debug_vec(x) vec_print(#x, x)
#define debug_bool(x) printf("%s = %s\n", #x, (x) ? "true" : "false")

int main() {
    vec_t zero = {0, 0, 0};
    vec_t unit = {1, 1, 1};
    // vec_t mid = {0.5, 0.5, 0.5};
    vec_t mid = {0.5, 10.5, 0.5};
    debug_vec(zero);
    debug_vec(unit);
    debug_vec(mid);
    debug_bool(vec_is_between(zero, unit, mid));
    return 0;
}
