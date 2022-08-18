/*################################################################################
  ##
  ##   Copyright (C) 2011-2022 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

/*
 * cdf of the inverse-gamma distribution
 */

#ifndef _statslib_pinvgamma_HPP
#define _statslib_pinvgamma_HPP

//
// scalar input

/**
 * @brief Distribution function of the Inverse-Gamma distribution
 *
 * @param x a real-valued input.
 * @param shape_par the shape parameter, a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return the cumulative distribution function evaluated at \c x.
 *
 * Example:
 * \code{.cpp} stats::pinvgamma(1.5,2,1,false); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
pinvgamma(const T1 x, const T2 shape_par, const T3 rate_par, const bool log_form = false) noexcept;

//
// vector/matrix input

/**
 * @brief Distribution function of the Inverse-Gamma distribution
 *
 * @param x a standard vector.
 * @param shape_par the shape parameter, a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a vector of CDF values corresponding to the elements of \c x.
 * 
 * Example:
 * \code{.cpp}
 * std::vector<double> x = {1.8, 0.7, 4.2};
 * stats::pinvgamma(x,3.0,2.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>>
statslib_inline
std::vector<rT>
pinvgamma(const std::vector<eT>& x, const T1 shape_par, const T2 rate_par, const bool log_form = false);
#endif

/**
 * @brief Distribution function of the Inverse-Gamma distribution
 *
 * @param X a matrix of input values.
 * @param shape_par the shape parameter, a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {1.8, 0.7, 4.2},
 *                 {0.3, 5.3, 3.7} };
 * stats::pinvgamma(X,3.0,2.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>>
statslib_inline
ArmaMat<rT>
pinvgamma(const ArmaMat<eT>& X, const T1 shape_par, const T2 rate_par, const bool log_form = false);

/**
 * @brief Distribution function of the Inverse-Gamma distribution
 *
 * @param X a matrix of input values.
 * @param shape_par the shape parameter, a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * arma::mat X = { {1.8, 0.7, 4.2},
 *                 {0.3, 5.3, 3.7} };
 * stats::pinvgamma(X,3.0,2.0,false);
 * \endcode
 */

template<typename mT, typename tT, typename T1, typename T2>
statslib_inline
mT
pinvgamma(const ArmaGen<mT,tT>& X, const T1 shape_par, const T2 rate_par, const bool log_form = false);
#endif

/**
 * @brief Distribution function of the Inverse-Gamma distribution
 *
 * @param X a matrix of input values.
 * @param shape_par the shape parameter, a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::pinvgamma(X,3.0,2.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>, bool To = blaze::columnMajor>
statslib_inline
BlazeMat<rT,To>
pinvgamma(const BlazeMat<eT,To>& X, const T1 shape_par, const T2 rate_par, const bool log_form = false);
#endif

/**
 * @brief Distribution function of the Inverse-Gamma distribution
 *
 * @param X a matrix of input values.
 * @param shape_par the shape parameter, a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return a matrix of CDF values corresponding to the elements of \c X.
 * 
 * Example:
 * \code{.cpp}
 * stats::pinvgamma(X,3.0,2.0,false);
 * \endcode
 */

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT = common_return_t<eT,T1,T2>, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
statslib_inline
EigenMat<rT,iTr,iTc>
pinvgamma(const EigenMat<eT,iTr,iTc>& X, const T1 shape_par, const T2 rate_par, const bool log_form = false);
#endif

//
// include implementation files

#include "pinvgamma.ipp"

#endif
