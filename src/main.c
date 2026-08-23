#include <stdio.h>
#include <string.h>

#include "types.h"
#include "encode.h"
#include "decode.h"

static Operations parse_operation(const char *argument);
static void print_usage(const char *program_name);
static Status validate_arguments(Operations operation, int argument_count, char *argv[]);

int main(int argc, char *argv[])
{
    Operations operation;

    if (argc < 2)
    {
        print_usage(argv[0]);
        return STATUS_FAILURE;
    }

    operation = parse_operation(argv[1]);

    if (validate_arguments(operation, argc, argv) == STATUS_FAILURE)
    {
        return STATUS_FAILURE;
    }
    
    Status result;

    switch (operation)
    {
        case OP_ENCODE:            
            EncodeContext encode_context = {
                .image_path = argv[2],
                .secret_path = argv[3],
                .output_path = argv[4],
                .image_file = NULL,
                .secret_file = NULL,
                .output_file = NULL
            };
            
            result = encode_image(&encode_context);
            encode_cleanup(&encode_context);
            
            if (result == STATUS_FAILURE)
            {
                return STATUS_FAILURE;
            }
            
            break;

        case OP_DECODE:            
            DecodeContext decode_context = {
                .image_path = argv[2],
                .output_path = argv[3],
                .image_file = NULL,
                .output_file = NULL
            };

            result = decode_image(&decode_context);
            decode_cleanup(&decode_context);

            if (result == STATUS_FAILURE)
            {
                return STATUS_FAILURE;
            }

            break;
        
        default:
            fprintf(stderr, "ERROR: unsupported operation.\n");
            print_usage(argv[0]);
            return STATUS_FAILURE;
    }

    return STATUS_SUCCESS;
}

static Operations parse_operation(const char *argument)
{
    if (argument == NULL)
    {
        return OP_INVALID;
    }

    if (strcmp(argument, "encode") == 0)
    {
        return OP_ENCODE;
    }

    if (strcmp(argument, "decode") == 0)
    {
        return OP_DECODE;
    }

    return OP_INVALID;
}

static void print_usage(const char *program_name)
{
    printf(
        "Usage: \n"
        " %s encode <image> <secret> <output>\n"
        " %s decode <image> <output>\n",
        program_name, program_name
    );
}

static Status validate_arguments(Operations operation, int argument_count, char *argv[])
{
    if (operation == OP_ENCODE)
    {
        if (argument_count != 5)
        {
            fprintf(stderr, "ERROR: invalid number of arguments for encode operation.\n");
            print_usage(argv[0]);
            return STATUS_FAILURE;
        }
    }
    else if (operation == OP_DECODE)
    {
        if (argument_count != 4)
        {
            fprintf(stderr, "ERROR: invalid number of arguments for decode operation.\n");
            print_usage(argv[0]);
            return STATUS_FAILURE;
        }
    }
    else
    {
        fprintf(stderr, "ERROR: unsupported operation.\n");
        print_usage(argv[0]);
        return STATUS_FAILURE;
    }

    return STATUS_SUCCESS;
}