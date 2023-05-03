#pragma once

#include <iostream>

namespace Math
{
float roundToFloat(float num)
{
    char str[40];

    sprintf(str, "%.2f", num);
    sscanf(str, "%f", &num);

    return num;
}

} // namespace Math
