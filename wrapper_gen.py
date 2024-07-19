import os



def main():
    if os.path.isdir('include'):
        exit('No folder called include')


if __name__ == '__main__':
    main()
    print('quitting')
