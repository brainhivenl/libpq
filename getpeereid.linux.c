#include "c.h"

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/*
 * BSD-style getpeereid() for platforms that lack it.
 */
int
getpeereid(int sock, uid_t *uid, gid_t *gid)
{	/* No implementation available on this platform */
	errno = ENOSYS;
	return -1;
}