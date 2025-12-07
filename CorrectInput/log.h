#pragma once

#ifndef LOG
#define LOG

namespace log {
	typedef const size_t log;
	log WITHOUT_DATA = 0;
	log NOT_INT = 1;
	log INT_SIZE = 2;
	const size_t CNTLOG = 3;
}

#endif // !LOG
