
#include "dictcsv.h"

#include <sstream>

void DictCsv::splitByComma(const std::string& word, 
                           std::vector<int32_t>& ngrams, 
                           uint32_t (*hash)(const std::string&),
                           int32_t nwords,
                           int32_t bucket) {
	std::stringstream ss(word);
	std::string item;
	while (getline(ss, item, ',')) {
		int32_t h = (*hash)(item) % bucket;
		ngramMap[nwords + h].insert(item);
		ngrams.push_back(nwords + h);
	}
}