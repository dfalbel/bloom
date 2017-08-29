// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// timesTwo
NumericVector timesTwo(NumericVector x);
RcppExport SEXP _bloom_timesTwo(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(timesTwo(x));
    return rcpp_result_gen;
END_RCPP
}
// create_bloom_parameters
SEXP create_bloom_parameters();
RcppExport SEXP _bloom_create_bloom_parameters() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(create_bloom_parameters());
    return rcpp_result_gen;
END_RCPP
}
// create_filter
SEXP create_filter();
RcppExport SEXP _bloom_create_filter() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(create_filter());
    return rcpp_result_gen;
END_RCPP
}
// bloom
int bloom();
RcppExport SEXP _bloom_bloom() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(bloom());
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_bloom_timesTwo", (DL_FUNC) &_bloom_timesTwo, 1},
    {"_bloom_create_bloom_parameters", (DL_FUNC) &_bloom_create_bloom_parameters, 0},
    {"_bloom_create_filter", (DL_FUNC) &_bloom_create_filter, 0},
    {"_bloom_bloom", (DL_FUNC) &_bloom_bloom, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_bloom(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}