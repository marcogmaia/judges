import subprocess
import sys
import io

if __name__ == '__main__':

    program_name = sys.argv[1]  # program name
    input_file = sys.argv[2]  # testCases file name

    with open(input_file, 'r', encoding='utf8') as f:
        for line in f:
            line_as_file = io.StringIO(line)
            process = subprocess.Popen(
                program_name,
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                universal_newlines=True)
            output, output_err = process.communicate(line_as_file.read())
            print(output, end='')
