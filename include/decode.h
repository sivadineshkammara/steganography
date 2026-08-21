#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>

#include "types.h"

typedef struct
{
    const char *image_path;
    const char *output_path;

    FILE *image_file;
    FILE *output_file;

} DecodeContext;

// Status decode_prepare(DecodeContext *context);
Status decode_image(DecodeContext *context);
void decode_cleanup(DecodeContext *context);

#endif