#ifndef DICTCSV_H
#define DICTCSV_H

#include <fstream>
#include <string>

class DictCsv {
  private:
    std::ofstream f;

  public:
  	DictCsv();
    DictCsv(std::string);
  	void log(std::string, int32_t);
  	void close();
};

#endif