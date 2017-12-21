#include "include/score.h"

int score_compare (const void * actual, const void * other)
{
        return (int)(actual->points - other->points);
}
