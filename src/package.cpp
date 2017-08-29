#include <Rcpp.h>
#include <memory>
#include "bloom/bloom_filter.hpp"
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x * 2;
}

//[[Rcpp::export]]
SEXP create_bloom_parameters() {

  bloom_parameters parameters;

  // How many elements roughly do we expect to insert?
  parameters.projected_element_count = 1000;

  // Maximum tolerable false positive probability? (0,1)
  parameters.false_positive_probability = 0.0001; // 1 in 10000

  // Simple randomizer (optional)
  parameters.random_seed = 0xA5A5A5A5;

  //(*parameters).compute_optimal_parameters();

  Rcpp::XPtr<bloom_parameters> ptr(parameters, true);

  return ptr;
}


//[[Rcpp::export]]
SEXP create_filter () {

  bloom_parameters parameters;

  // How many elements roughly do we expect to insert?
  parameters.projected_element_count = 1000;

  // Maximum tolerable false positive probability? (0,1)
  parameters.false_positive_probability = 0.0001; // 1 in 10000

  // Simple randomizer (optional)
  parameters.random_seed = 0xA5A5A5A5;

  parameters.compute_optimal_parameters();

  Rcpp::XPtr<bloom_filter> ptr(new bloom_filter(parameters), true);

  return ptr;
}


// [[Rcpp::export]]
int bloom() {
  bloom_parameters parameters;

  // How many elements roughly do we expect to insert?
  parameters.projected_element_count = 1000;

  // Maximum tolerable false positive probability? (0,1)
  parameters.false_positive_probability = 0.0001; // 1 in 10000

  // Simple randomizer (optional)
  parameters.random_seed = 0xA5A5A5A5;

  if (!parameters)
  {
    std::cout << "Error - Invalid set of bloom filter parameters!" << std::endl;
    return 1;
  }

  parameters.compute_optimal_parameters();

  //Instantiate Bloom Filter
  bloom_filter filter(parameters);

  std::string str_list[] = { "AbC", "iJk", "XYZ" };

  // Insert into Bloom Filter
  {
    // Insert some strings
    for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i)
    {
      filter.insert(str_list[i]);
    }

    // Insert some numbers
    for (std::size_t i = 0; i < 100; ++i)
    {
      filter.insert(i);
    }
  }


  // Query Bloom Filter
  {
    // Query the existence of strings
    for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i)
    {
      if (filter.contains(str_list[i]))
      {
        std::cout << "BF contains: " << str_list[i] << std::endl;
      }
    }

    // Query the existence of numbers
    for (std::size_t i = 0; i < 100; ++i)
    {
      if (filter.contains(i))
      {
        std::cout << "BF contains: " << i << std::endl;
      }
    }

    // Query the existence of invalid numbers
    for (int i = -1; i > -100; --i)
    {
      if (filter.contains(i))
      {
        std::cout << "BF falsely contains: " << i << std::endl;
      }
    }
  }

  return 0;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
timesTwo(42)
*/
