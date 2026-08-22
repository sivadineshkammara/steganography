#ifndef ENCODE_H
#define ENCODE_H

#include <stdio.h>

#include "types.h"

typedef struct
{
    const char *image_path;
    const char *secret_path;
    const char *output_path;

    FILE *image_file;
    FILE *secret_file;
    FILE *output_file;

} EncodeContext;

// Status encode_prepare(EncodeContext *context);
Status encode_image(EncodeContext *context);
void encode_cleanup(EncodeContext *context);

#endif