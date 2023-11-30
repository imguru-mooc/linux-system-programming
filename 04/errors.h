#ifndef __errors_h
#define __errors_h
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#ifdef DEBUG
# define DPRINTF(fmt,...) printf(fmt, __VA_ARGS__)
#else
# define DPRINTF(fmt,...)
#endif
#define err_abort(code,text) do {       \
	fprintf(stderr, "%s at \"%s\":%d: %s\n",  \
			text, __FILE__, __LINE__, strerror(code));  \
	abort();    \
}while(0)
#define errno_abort(text) do {       \
	fprintf(stderr, "%s at \"%s\":%d: %s\n",  \
			text, __FILE__, __LINE__, strerror(errno));  \
	abort();    \
}while(0)
#endif
