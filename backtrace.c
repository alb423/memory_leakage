#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <execinfo.h>

#ifdef __cplusplus
extern "C" {
#endif

static void _ShowBacktrace(void)
{
	void *bt[1024];
	int bt_size;
	char **bt_syms;
	int i;
fprintf(stderr,"%s:%d\n", __func__, __LINE__);
	bt_size = backtrace(bt, 1024);
fprintf(stderr,"%s:%d\n", __func__, __LINE__);
	
#if 1
	backtrace_symbols_fd(bt, bt_size, STDOUT_FILENO);
#else
	// This function will use malloc, so if we hook malloc, we can't use this functions
	bt_syms = backtrace_symbols(bt, bt_size); 
	for (i = 1; i < bt_size; i++) 
	{
		printf("%s\n", bt_syms[i]);
	}
	free(bt_syms);
#endif
}

extern void *__libc_malloc(size_t size); 
extern void *malloc(size_t size)
{
    static int i=0;
    if(i++==0)
		_ShowBacktrace();

fprintf(stderr,"%s:%d\n", __func__, __LINE__);

    void *ptr = __libc_malloc(size);



    return ptr;
}

#ifdef __cplusplus
}
#endif