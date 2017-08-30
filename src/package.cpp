#include <Rcpp.h>
#include <memory>
#include "bloom_filter.hpp"
using namespace Rcpp;

//[[Rcpp::export]]
SEXP create_bloom_parameters() {

  bloom_parameters *parameters = new bloom_parameters;

  // How many elements roughly do we expect to insert?
  (*parameters).projected_element_count = 1000;

  // Maximum tolerable false positive probability? (0,1)
  (*parameters).false_positive_probability = 0.0001; // 1 in 10000

  // Simple randomizer (optional)
  (*parameters).random_seed = 0xA5A5A5A5;

  (*parameters).compute_optimal_parameters();

  Rcpp::XPtr<bloom_parameters> ptr(parameters, true);

  return ptr;
}


//[[Rcpp::export]]
SEXP create_bloom_filter (SEXP par) {

  Rcpp::XPtr<bloom_parameters> par_ptr(par);

  bloom_filter * filter = new bloom_filter(*par_ptr);

  Rcpp::XPtr<bloom_filter> ptr(filter, true);

  return ptr;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
a <- create_bloom_parameters()
b <- create_filter(a)
*/
