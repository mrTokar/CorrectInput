#pragma once

#ifndef LOG
#define LOG

namespace logs {
	typedef const size_t log;
	log WITHOUT_DATA = 0;
	log NOT_INT = 1;
	log INT_SIZE = 2;
	log CLOSE_FILE = 3;
	const size_t CNTLOG = 4;
}

#endif // !LOG
