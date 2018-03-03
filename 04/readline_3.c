#include <unistd.h>
#include <stdlib.h>
#define MAXLINE 4096


typedef struct 
{
	int		read_cnt;
	char	*read_ptr;
	char	read_buf[MAXLINE];
} Rline;

static ssize_t my_read(int fd, char *ptr, Rline *buff)
{
	if (buff->read_cnt <= 0) {
		if ( (buff->read_cnt = read(fd, buff->read_buf,
						sizeof(buff->read_buf))) < 0) {
			return(-1);
		} else if (buff->read_cnt == 0)
			return(0);
		buff->read_ptr = buff->read_buf;
	}

	buff->read_cnt--;
	*ptr = *buff->read_ptr++;
	return(1);
}
ssize_t  readline(int fd, void *vptr, size_t maxlen)
{
	int     n, rc;
	char    c, *ptr;
	Rline   buff = {0,};
	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
		if ( (rc = my_read(fd, &c, &buff)) == 1) {
			*ptr++ = c;
			if (c == '\n')
				break; 
		} else if (rc == 0) {
			if (n == 1)
				return(0);  
			else
				break;      
		} else
			return(-1);     
	}
	*ptr = 0;   
	return(n);
}

