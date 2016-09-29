#include "csv.h"

#include <string.h>

Csv::Csv() {
	bool enabled = false;
}


// Args helpers

std::string Csv::help() {
	return "  -csv                parse tokens as csv tuples [0]\n";
}

bool Csv::isCsvArg(char* arg) {
	return strcmp(arg, "-csv") == 0;
}
