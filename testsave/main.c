#include <stdio.h>
#include <sys/types.h>
#include <sys/dir.h>

#ifdef _DARWIN_FEATURE_64_BIT_INODE
# define MESSAGE "defined"
#endif
 
int		main(void)
{
	printf(MESSAGE);
	return (0);
}
