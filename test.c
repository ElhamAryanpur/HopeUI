#include "cvector.h"
#include "stdio.h"

typedef struct test
{
    int a;
} test;

int main()
{
    test t;
    t.a = 5;

    test y;
    y.a = 10;

    cvector_vector_type(test) array = NULL;

    cvector_push_back(array, t);
    cvector_push_back(array, y);

    if (array)
    {
        size_t i;
        for (i = 0; i < cvector_size(array); ++i)
        {
            printf("array[%lu] = %d\n", i, array[i].a);
        }
    }

    cvector_free(array);

    getchar();
    return 0;
}