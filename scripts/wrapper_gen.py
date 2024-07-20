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

    template_file = 'scripts/templates/' + args.pop(0)
    if not os.path.isfile(template_file):
        return f'No template file "{template_file}"'

    with open(template_file, 'r') as file:
        template_list = [x.strip() for x in file.read().split('###')]
    return templat_list
    header = template_list.pop(0)

    type_file = 'scripts/' + args.pop(0)
    if not os.path.isfile(type_file):
        return 'No type file "{type_file}"'

    with open(type_file, 'r') as file:
        types = [x for x in file.read().split('\n') if x != '']


if __name__ == '__main__':
    exit_message = main()
    print(exit_message)
