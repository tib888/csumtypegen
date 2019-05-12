#include <string>
#include "tuples.h"

// comment1
// comment2
sumtype States // comment2_
{
    First;
    Second(int);
    Third(int);
    Fourth(std::string); //comment2__
    Last;
};

/* comment3
   comment4 */
sumtype States2 {
    First;  //comment5
    Second(int*);
    Third(tuple<int,int,int>);
    Fourth(const std::tuple<std::string, std::tuple<int*, const int* const *>>);
    Last;
};

hello;