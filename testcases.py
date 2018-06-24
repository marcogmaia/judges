import subprocess
import sys
import io

if __name__ == '__main__':
    program = sys.argv[1]
    input_file = sys.argv[2]
    # args = [program]
    # print(args)
    with open(
            input_file, 'r',
            encoding='utf8') as f:
        for line in f:
            my_input_file = io.BytesIO(bytes(line, encoding='utf8'))
            p = subprocess.Popen(
                program, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
            output, output_err = p.communicate(my_input_file.read())
            print(output.decode('utf8'), end='')
