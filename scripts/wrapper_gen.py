# RUN THIS FILE FROM THE PROJECTS ROOT DIRECTORY.


import os
import sys


def main():
    if not os.path.isdir('include'):
        return 'No folder called include.'
    if not os.path.isdir('wrappers'):
        return 'No folder called wrappers.'

    args = sys.argv[1:]
    if not len(args):
        return 'No arguments provided'

    template_file = 'scripts/templates/' + args.pop(0)
    if not os.path.isfile(template_file):
        return f'No template file "{template_file}"'



   
if __name__ == '__main__':
    exit_message = main()
    print(exit_message)
