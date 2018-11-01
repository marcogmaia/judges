import os

# cautionary check
folderToExcludeFrom = 'd:/marco/programming/cpp/judges'

if __name__ == '__main__':
    # Will traverse the current folder downwards looking for a *.exe to exclude
    if os.path.dirname(__file__) == folderToExcludeFrom:
        for root, dirs, files in os.walk('.'):
            for file in files:
                if file.endswith(".exe"):
                    fileToExclude = os.path.join(root, file)
                    os.remove(fileToExclude)
                    print(f'{file} removed')
