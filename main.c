#include "io.h"
#include "toml_parser.h"
#include "toml_print.h"

int main()
{
    BufferData* buffer = ReadFile("data.toml");

    TomlToken* t = TokenizeToml(buffer);

    PrintBuffer(buffer);

    DestroyBufferData(buffer);

    PS("Parsing Done.");

    return 0;
}
