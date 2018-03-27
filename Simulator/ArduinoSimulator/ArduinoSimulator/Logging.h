#ifndef _LOGGING_H_
#define _LOGGING_H_
#include <cstdio>

/*enum
{
	LVL_INFO = 0,
	LVL_WARNING,
	LVL_ERROR,
	ALL_LEVELS
}LOG_LEVEL;

const char* LOG_STRING[ALL_LEVELS] = 
{
	"INFO",
	"WARNING",
	"ERROR"
};*/

#define DISPLAY_LOG(level, format, ...)		printf("%s: %s\n", __FUNCTION__, format, __VA_ARGS__);

#endif