#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
SEXP foo() {

  int *a = new int;
  *a = 1;

  Rcpp::XPtr<int> ptr(a);

  return ptr;
}

// [[Rcpp::export]]
int bar(SEXP a){

  Rcpp::XPtr<int> x(a);
  int b = *x;

  return b;
}

/*** R
a <- foo()
bar(a)
*/
