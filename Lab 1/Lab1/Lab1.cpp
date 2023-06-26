#include "modes.h"

int main(int argc, char* argv[])
{
    bool arg_mode, pointer_mode, stream_mode;

    if (argc != 3) {
        cout << "Incorect count of arguments. Try to use: program_name (-mode FilePointer | FileStream)\n";
        return 1;
    }
    arg_mode = !strcmp(argv[1], "-mode");
    pointer_mode = !strcmp(argv[2], "FilePointer");
    stream_mode = !strcmp(argv[2], "FileStream");

    if (!arg_mode) {
        cout << "Incorect arguments. Try to use: program_name (-mode FilePointer | FileStream)\n";
        return 1;
    }
    else if (!pointer_mode && !stream_mode) {
        cout << "Incorect arguments. Try to use: program_name (-mode FilePointer | FileStream)\n";
        return 1;
    }
    else if (pointer_mode) {
        file_pointer();
    }
    else if (stream_mode) {
        file_stream();
    }
    return 0;
}