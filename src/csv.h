#ifndef CSV_ARGS_H
#define CSV_ARGS_H

#include <string>

class Csv {
  public:
    Csv();
    bool enabled;

    std::string help();
    bool isCsvArg(char*);
};

#endif
