#ifndef __YARR_PATCH
#define __YARR_PATCH

#include <linux/types.h>

// TODO: Document.

/**
 * Patches the kernel memory at dst with size bytes from src.
 *
 * @dst: The address to be patched.
 * @src: The address with the content to be written.
 * @size: The number of bytes to be read from src and written into dst.
 * @return: Zero on success, non-zero elsewhere.
 */
int patch(unsigned char *dst, unsigned char *src, size_t size);

/**
 * Undoes all the patches previously done by calling patch().
 *
 * @return: Zero on success, non-zero elsewhere.
 */
int unpatch_all(void);

#endif

