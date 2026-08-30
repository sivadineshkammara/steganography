#ifndef BMP_H
#define BMP_H

#include <stdint.h>
#include <stdio.h>

#include "types.h"

typedef struct
{
    uint32_t width;
    uint32_t height;
    uint16_t bits_per_pixel;
    uint32_t pixel_data_offset;
} BmpInfo;

Status bmp_read_info(FILE *file, BmpInfo *info);
Status bmp_validate(const BmpInfo *info);

#endif /*BMP_H*/