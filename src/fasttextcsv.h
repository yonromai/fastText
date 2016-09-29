#ifndef FASTTEXTCSV_H
#define FASTTEXTCSV_H

#include <atomic>
#include <string>

#include "matrix.h"
#include "vector.h"
#include "dictionary.h"

class FastTextCsv {
  private:
    static void getTokenVectors(Vector&, const std::string&, std::shared_ptr<Dictionary>, std::shared_ptr<Matrix>);

  public:
    static void saveTokenVectors(int, std::string&, std::shared_ptr<Dictionary> , std::shared_ptr<Matrix>);
};

#endif
