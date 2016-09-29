#include "fasttextcsv.h"

#include <fstream>
#include <iostream>

// FastText helpers

void FastTextCsv::getTokenVectors(Vector& vec, const std::string& word, std::shared_ptr<Dictionary> dict_, std::shared_ptr<Matrix> input_) { // private fixme
  const std::vector<int32_t>& ngrams = dict_->getNgrams(word);
  vec.zero();
  for (auto it = ngrams.begin(); it != ngrams.end(); ++it) {
    vec.addRow(*input_, *it);
  }
  if (ngrams.size() > 0) {
    vec.mul(1.0 / ngrams.size());
  }
}

void FastTextCsv::saveTokenVectors(int dim, std::string& output,
                           std::shared_ptr<Dictionary> dict_, 
                           std::shared_ptr<Matrix> input_) {
  std::ofstream ofs(output + ".tokens.vec");
  if (!ofs.is_open()) {
    std::cout << "Error opening file for saving vectors." << std::endl;
    exit(EXIT_FAILURE);
  }
  ofs << dict_->nwords() << " " << dim << std::endl;
  Vector vec(dim);
  for (int32_t i = 0; i < dict_->nwords(); i++) {
    std::string word = dict_->getWord(i);
    getTokenVectors(vec, word, dict_, input_);
    ofs << word << " " << vec << std::endl;
  }
  ofs.close();
}

// void FastTextCsv::saveBucketToId() {

// }