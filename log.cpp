#include "log.h"
#include <iostream>
#include <cstring>

bool
LogUnit::openLog(const char * filename)
{
	if (isFile && logFile.is_open()) {
		cerr << APPNAME
			<< ": opening a new Log file, while another is already open"
			<< endl;
		closeLog();
	}

	if (strcmp(filename, "/dev/stderr") == 0) {
		isFile = false;
		return true;
	} else {
		logFile.open(filename, ios_base::app);
		isFile = true;
		return !(logFile.fail());
	}
}

void
LogUnit::closeLog()
{
	if (!isFile) return;
	if (logFile.is_open())
		logFile.close();
}
