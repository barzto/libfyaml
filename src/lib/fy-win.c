#include "fy-win.h"

#include <sysinfoapi.h>
#include <stdio.h>  /* needed for vsnprintf    */
#include <stdlib.h> /* needed for malloc, free */
#include <stdarg.h> /* needed for va_*         */

#define vscprintf _vscprintf

static long get_page_size() {
    SYSTEM_INFO info;
    GetNativeSystemInfo(&info);
    return info.dwPageSize;
}

long sysconf(int name)
{
    switch (name) {
        case _SC_PAGESIZE:
            return get_page_size();
    }
    return -1;
}

int vasprintf(char **strp, const char *format, va_list ap)
{
    int len = vscprintf(format, ap);
    if (len == -1)
        return -1;
    char *str = (char*)malloc((size_t) len + 1);
    if (!str)
        return -1;
    int retval = vsnprintf(str, len + 1, format, ap);
    if (retval == -1) {
        free(str);
        return -1;
    }
    *strp = str;
    return retval;
}

int asprintf(char **strp, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int retval = vasprintf(strp, format, ap);
    va_end(ap);
    return retval;
}


