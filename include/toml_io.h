#ifndef TOML_IO_H
#define TOML_IO_H

#include <stdio.h>
#include <stdlib.h>

/**-----------------------------------------------------------------------------
 = STRUCTS
-----------------------------------------------------------------------------**/

/**
 * Handy location to store data that has been read in.
 */
typedef struct BufferData
{
    char* data;
    size_t size;

} BufferData;

/**-----------------------------------------------------------------------------
 = FUNCTIONS
-----------------------------------------------------------------------------**/

/**
 * Get the size of a file in bytes.
 *
 * @param FILE* fp
 *
 * @return int
 */
int GetFileSize(FILE* fp);

/**
 * Read the contents of a file and store it in memory.
 *
 * @param const char* toml_file    The name of the .toml file
 *
 * @return BufferData*
 */
BufferData* ReadFile(const char* toml_file);

/**
 * Destroy all of the memory allocated for this buffer
 *
 * @param BufferData* buffer    Contents of .toml file.
 *
 * @return void
 */
void DestroyBufferData(BufferData* buffer);

#endif  //TOML_IO_H
