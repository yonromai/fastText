#ifndef DICTCSV_H
#define DICTCSV_H

#include <string>
#include <vector>
#include <map>
#include <set>

class DictCsv {
  public:
    std::map<int32_t, std::set<std::string> > ngramMap;
    void splitByComma(const std::string&, std::vector<int32_t>&, uint32_t (*hash)(const std::string&), int32_t, int32_t);
};

#endif