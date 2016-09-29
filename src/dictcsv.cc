
#include "dictcsv.h"

#include <iostream>

DictCsv::DictCsv() {}

DictCsv::DictCsv(std::string output) {
  f.open(output + ".token_bucket.map");
}

void DictCsv::log(std::string ngram, int32_t n) {
	f << ngram << " " << n << std::endl;
}

void DictCsv::close() {
	f.close();
}