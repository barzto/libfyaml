#ifndef FY_WIN_H
#define FY_WIN_H

#include "fy-win-mmap.h"

#include <limits.h>
#include <malloc.h>

#ifndef S_IRWXU
#define	S_IRWXU 	0000700	/* rwx, owner */
#endif

#ifndef		S_IRUSR
#define		S_IRUSR	0000400	/* read permission, owner */
#endif

#ifndef		S_IWUSR
#define		S_IWUSR	0000200	/* write permission, owner */
#endif

#ifndef		S_IXUSR
#define		S_IXUSR	0000100	/* execute/search permission, owner */
#endif

/* Windows doesn't have group permissions so set all these to zero. */
#define	S_IRWXG		0	/* rwx, group */
#define		S_IRGRP	0	/* read permission, group */
#define		S_IWGRP	0	/* write permission, grougroup */
#define		S_IXGRP	0	/* execute/search permission, group */

/* Windows doesn't have others permissions so set all these to zero. */
#define	S_IRWXO		0	/* rwx, other */
#define		S_IROTH	0	/* read permission, other */
#define		S_IWOTH	0	/* write permission, other */
#define		S_IXOTH	0	/* execute/search permission, other */

#ifndef S_ISFIFO
#define S_ISFIFO(mode)	(((mode) & _S_IFMT) == _S_IFIFO)
#endif

#ifndef S_ISREG
#define	S_ISREG(mode)	(((mode) & _S_IFREG) == _S_IFREG)
#endif


#define _SC_PAGESIZE 1

long sysconf(int name);

int vasprintf(char **strp, const char *format, va_list ap);
int asprintf(char **strp, const char *format, ...);

#endif //FY_WIN_H
