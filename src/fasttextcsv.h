#ifndef FASTTEXTCSV_H
#define FASTTEXTCSV_H

#include <atomic>
#include <string>

#include "matrix.h"
#include "vector.h"
#include "dictionary.h"

class FastTextCsv {
  private:
    static void getTokenVector(Vector&, std::shared_ptr<Matrix>, int64_t);

  public:
    static void saveTokenVectors(int, std::string&, std::shared_ptr<Dictionary> , std::shared_ptr<Matrix>);
};

#endif
