# RUN THIS FILE FROM THE PROJECTS ROOT DIRECTORY.


import os
import sys


def main():
    if not os.path.isdir('winclude'):
        return 'No folder called winclude.'
    print('Found include folder.')

    if not os.path.isdir('wrappers'):
        return 'No folder called wrappers.'
    print('Found wrapper folder.')

    args = sys.argv[1:]
    if len(args) != 3:
        return f'Invalid amount of arguments. Expected 3, got {len(args)}.'

    type_name = args.pop(0)
    print(f'Type name is: {type_name}.')

    # Read the template file.
    template_file = 'scripts/templates/' + args.pop(0)
    if not os.path.isfile(template_file):
        return f'No template file "{template_file}"'
    print(f'Found template file: {template_file}.')

    with open(template_file, 'r') as file:
        template_list = [x.strip() for x in file.read().split('###')]
    header = template_list.pop(0)

    # Read the type file.
    type_file = 'scripts/' + args.pop(0)
    if not os.path.isfile(type_file):
        return f'No type file "{type_file}"'
    print(f'Found type file: {type_file}.')

    with open(type_file, 'r') as file:
        types = [x for x in file.read().split('\n') if x != '']
    for i in range(len(types)):
        types[i] = types[i].split(',') if ',' in types[i] else [types[i]]

    # Write the c file.
    cfile = 'wrappers/'+type_name+'wrappers.c'
    with open(cfile, 'w') as file:
        print(f'Started writing file: {cfile}.')
        file.write('// This file was automatically generated.\n\n')
        if header != '':
            print('Writing header...')
            file.write(header)
            file.write('\n')
        else:
            print('No header specified, skipping...')

        print('Writing functions...')
        for block in template_list:
            for t in types:
                file.write(block.replace('<t>', t[0])
                                .replace('<T>', t[-1]))
                file.write('\n')

    print(f'Finished writing file: {cfile}.')

    # Get function signatures for header file.
    signatures = []
    print('Getting function signature templates...')
    for function in template_list:
        function = list(function)
        signature = ''
        while function[0] != '{':
            signature += function.pop(0)
        signatures.append(signature.strip())

    # Write the header file.
    hfile = 'winclude/'+type_name+'wrappers.h'
    with open(hfile, 'w') as file:
        print(f'Started writing file: {hfile}.')
        file.write('// This file was automatically generated.\n\n')
        file.write(f'#ifndef {type_name.upper()}_WRAPPERS_H\n')
        file.write(f'#define {type_name.upper()}_WRAPPERS_H\n')

        for signature in signatures:
            for t in types:
                file.write(signature.replace('<t>', t[0])
                                    .replace('<T>', t[-1])+';\n')
        file.write('#endif')

    print(f'Finished writing file: {hfile}.')

    return 'Creation successful!'

if __name__ == '__main__':
    exit_message = main()
    print(exit_message)
