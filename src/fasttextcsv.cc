#include "fasttextcsv.h"

#include <fstream>
#include <iostream>
#include <set>

// FastText helpers

void FastTextCsv::getTokenVector(Vector& vec, std::shared_ptr<Matrix> input_, int64_t i) { // private fixme
  vec.zero();
  vec.addRow(*input_, i);
}

// void FastTextCsv::saveTokenVectors(int dim, std::string& output,
//                            std::shared_ptr<Dictionary> dict_, 
//                            std::shared_ptr<Matrix> input_) {
//   std::ofstream ofs(output + ".tokens.vec");
//   if (!ofs.is_open()) {
//     std::cout << "Error opening file for saving vectors." << std::endl;
//     exit(EXIT_FAILURE);
//   }
//   ofs << dict_->ntokens() << " " << dim << std::endl;
//   Vector vec(dim);
//   for (int64_t i = 0; i < dict_->ntokens(); i++) {
//     getTokenVector(vec, input_, i);
//     ofs << i << " " << vec << std::endl;
//   }
//   ofs.close();
// }

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
  std::set<int64_t> seenTokens;
  for (int32_t i = 0; i < dict_->nwords(); i++) {
    std::string word = dict_->getWord(i);
    const std::vector<int32_t>& ngrams = dict_->getNgrams(word);
    for (auto it = ngrams.begin(); it != ngrams.end(); ++it) {
      if(seenTokens.insert(*it).second) {
        getTokenVector(vec, input_, *it);
        ofs << *it << " " << vec << std::endl;
      }
    }
  }
  ofs.close();
}
