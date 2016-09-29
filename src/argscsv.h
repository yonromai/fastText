#ifndef ARGSCSV_H
#define ARGSCSV_H

#include <string>

class ArgsCsv {

  public:
    ArgsCsv();
    bool enabled;

    std::string help();
    bool isCsvArg(char*);
};

#endif