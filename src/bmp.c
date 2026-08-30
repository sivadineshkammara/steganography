#include "bmp.h"

static uint16_t read_le16(const uint8_t *buffer);
static uint32_t read_le32(const uint8_t *buffer);