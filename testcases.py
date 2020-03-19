# this program receives 2 inputs, the executable and a file with the testcases
# for each line in the testcases file it will run the program and
# at the end it will time
import time
import subprocess
import sys
import io


def timeit(decorated_funtion):
    """
    Outputs the time tha a function takes to run.
    """
    def wrapper(*args, **kwargs):
        t1 = time.time()
        decorated_funtion(*args, **kwargs)
        t2 = time.time()
        print(f'Total running time = {t2-t1}')

    return wrapper


@timeit
def main(program_name: str, input_file: str):
    with open(input_file, 'r', encoding='utf8') as f:
        for line in f:
            proc = subprocess.Popen(program_name,
                                    stdin=subprocess.PIPE,
                                    stdout=subprocess.PIPE,
                                    universal_newlines=True)
            lineAsFile = io.StringIO(line)
            output, err = proc.communicate(lineAsFile.read())
            print(output, end='')


if __name__ == '__main__':
    try:
        program_name = sys.argv[1]
        input_file = sys.argv[2]
        main(program_name, input_file)
    except Exception as e:
        print('No program or input were given.')
