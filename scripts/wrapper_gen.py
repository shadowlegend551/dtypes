# RUN THIS FILE FROM THE PROJECTS ROOT DIRECTORY.


import os
import sys


# Constants.
SRC_POSTFIX = 'wrappers.c'
INCLUDE_POSTFIX = 'wrappers.h'
INCLUDE_DIR = 'include/wrappers/'
WRAPPER_DIR = 'wrappers/'
TEMPLATE_DIR = 'scripts/templates/'
TYPE_FILE = 'scripts/types.t'
ARGS_AMOUNT = 1

# Lists.
DIRECTORIES = [
    INCLUDE_DIR,
    WRAPPER_DIR,
    TEMPLATE_DIR
]

FILES = [
    TYPE_FILE
]


def confirmDirectoryExists(directory: str) -> bool | str:
    return True if os.path.isdir(directory) else f'No directory named "{directory}"'

def confirmFileExists(file: str) -> bool | str:
    return True if os.path.isfile(file) else f'No file named "{file}"'



def main():
    # Parse arguments.
    if len(sys.argv) != ARGS_AMOUNT+1:
        return f'Invalid amount of arguments. Expected {ARGS_AMOUNT}, got {len(args)}.'
    template_file = TEMPLATE_DIR+sys.argv[1]
    FILES.append(template_file)


    # Confirm that all required files and directories exist.
    for dir in DIRECTORIES:
        if (dir_status:=confirmDirectoryExists(dir)) != True:
            return dir_status
        print(f'Found directory "{dir}"')

    for file in FILES:
        if (file_status:=confirmFileExists(template_file)) != True:
            return file_status
        print(f'found file "{file}"')


    # Read the template file.
    with open(template_file, 'r') as file:
        function_templates = [x.strip() for x in file.read().split('###')]
    type_name = function_templates.pop(0)
    header    = function_templates.pop(0).replace('<n>', type_name)

    # Read the type file.
    with open(TYPE_FILE, 'r') as file:
        types = [x for x in file.read().split('\n') if x != '']
    for i in range(len(types)):
        types[i] = types[i].split(',') if ',' in types[i] else [types[i], types[i]]

    # Write the source file.
    srcfile = WRAPPER_DIR + type_name + SRC_POSTFIX
    with open(srcfile, 'w') as file:
        print(f'Started writing file: {srcfile}.')
        file.write('// This file was automatically generated.\n')

        if len(header):
            print('Writing header...')
            file.write(header+'\n')
        else:
            print('No header specified, skipping...')

        print('Writing functions...')
        for block in function_templates:
            for t in types:
                file.write(block.replace('<t>', t[0])
                                .replace('<T>', t[1]))
                file.write('\n')

    print(f'Finished writing file: {srcfile}.')

    # Get function signatures for header file.
    signatures = []
    print('Getting function signature templates...')
    for function in function_templates:
        signature = function.split('{')[0]  # Discard the function definition.
        signatures.append(signature.strip())

    # Write the header file.
    hfile = INCLUDE_DIR + type_name + INCLUDE_POSTFIX
    with open(hfile, 'w') as file:
        print(f'Started writing file: {hfile}.')
        file.write('// This file was automatically generated.\n\n')
        file.write(f'#ifndef {type_name.upper()}_WRAPPERS_H\n')
        file.write(f'#define {type_name.upper()}_WRAPPERS_H\n')

        for signature in signatures:
            for t in types:
                file.write(signature.replace('<t>', t[0])
                                    .replace('<T>', t[1]) +';\n')
        file.write('#endif\n')

    print(f'Finished writing file: {hfile}.')

    return 'Creation successful!'

if __name__ == '__main__':
    exit_message = main()
    print(exit_message)
