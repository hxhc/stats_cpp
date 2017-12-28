/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

// g++-mp-7 -O3 -Wall -std=c++11 -I./../../include -I/opt/local/include no_arma_test.cpp -o no_arma_test.test -framework Accelerate
// g++-mp-7 -O3 -Wall -std=c++11 -DSTATS_NO_ARMA -I./../../include -I/opt/local/include no_arma_test.cpp -o no_arma_test.test -framework Accelerate

#include <math.h>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-05;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double mu = 1;
    double sigma = 2;

    // x = 2
    double x_1 = 2;
    double val_1 = 0.17603266;
    double dens_1 = stats::dnorm(x_1,mu,sigma);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);

    // x = 1, return log
    double x_2 = 1;
    double val_2 = -1.612085;
    double dens_2 = stats::dnorm(x_2,mu,sigma,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);

    if (success_1 && success_2) {
        printf("\ndnorm: all tests passed.\n");
    }

    return 0;
}