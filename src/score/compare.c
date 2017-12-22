#include "include/score.h"

int score_compare (const void * actual, const void * other)
{
        return (int)(((score_t *)actual)->points - ((score_t *)other)->points);
}
