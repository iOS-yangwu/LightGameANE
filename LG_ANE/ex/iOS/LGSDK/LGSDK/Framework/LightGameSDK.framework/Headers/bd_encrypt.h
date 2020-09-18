#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
/*
 * get out size for given input length.
 */
int bd_encrypted_size(int length);

/* NOTE: version number 2
 * encrypt input bytes to data.
 * Note: caller need to ensure data length with ss_encrypted_size.
 * Returns 0 for success, otherwise -1 is returned.
 */
int bd_encrypt(uint8_t *input, int length, uint8_t *key, int key_len, uint8_t *data);

#ifdef __cplusplus
}
#endif
