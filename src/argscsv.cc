#include "argscsv.h"

#include <string.h>

ArgsCsv::ArgsCsv() {
	bool enabled = false;
}

// Args helpers

std::string ArgsCsv::help() {
	return "  -csv                parse tokens as csv tuples [0]\n";
}

bool ArgsCsv::isCsvArg(char* arg) {
	return strcmp(arg, "-csv") == 0;
}
