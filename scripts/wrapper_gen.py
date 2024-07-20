# RUN THIS FILE FROM THE PROJECTS ROOT DIRECTORY.


import os
import sys


def main():
    if not os.path.isdir('include'):
        return 'No folder called include.'
    if not os.path.isdir('wrappers'):
        return 'No folder called wrappers.'

    args = sys.argv[1:]
    if len(args) < 3:
        return 'Too few arguments'

    type_name = args.pop(0)

    # Read the template file.
    template_file = 'scripts/templates/' + args.pop(0)
    if not os.path.isfile(template_file):
        return f'No template file "{template_file}"'
    with open(template_file, 'r') as file:
        template_list = [x.strip() for x in file.read().split('###')]
    header = template_list.pop(0)

    # Read the type file.
    type_file = 'scripts/' + args.pop(0)
    if not os.path.isfile(type_file):
        return 'No type file "{type_file}"'
    with open(type_file, 'r') as file:
        types = [x for x in file.read().split('\n') if x != '']

    # Write the c file.
    cfile = 'wrappers/'+type_name+'wrappers.c'
    print(cfile)
    with open(cfile, 'w') as file:
        if header != '':
            file.write(header)
            file.write('\n\n')
        for block in template_list:
            print('CURRENT_BLOCK: ', block)
            for t in types:
                print('CURRENT_TYPE: ', t)
                file.write(block.replace('<t>', t))
                file.write('\n')

    # Get function signatures for header file.
    signatures = []
    for function in template_list:
        function = list(function)
        signature = ''
        while function[0] != '{':
            signature += function.pop(0)
        signatures.append(signature.strip())
    

if __name__ == '__main__':
    exit_message = main()
    print(exit_message)
