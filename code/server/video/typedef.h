/**
 * @File: typedef.h
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: Common type definition.
 */

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#ifdef __cplusplus
#define DECLS_BEGIN extern "C" {
#define DECLS_END   }
#else
#define DECLS_BEGIN
#define DECLS_END
#endif

typedef int (*CtxCompareFunc)(void *ctx1, void *ctx2);
typedef void (*DataRequestFunc)(unsigned char *buf, int buf_size, void *ctx);
typedef int (*FrameProcessFunc)(unsigned char *out_buf,
                                unsigned char *in_buf,
                                int in_size,
                                int in_format,
                                int out_format);

#endif
