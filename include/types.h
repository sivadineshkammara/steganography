/*
 *  Name:      types.h
 *  Does:      To create a global types for the projects to maintain consistent language.
 *  Contains:  Enumerated values.
*/

#ifndef TYPES_H
#define TYPES_H

typedef enum
{
    OP_ENCODE,
    OP_DECODE,
    OP_INVALID
} Operations;

typedef enum
{
    STATUS_SUCCESS,
    STATUS_FAILURE,
} Status;

#endif