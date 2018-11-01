# this program receives 2 inputs, the executable and a file with the testcases
# for each line in the testcases file it will run the program and
# at the end it will time
import time
import subprocess
import sys
import io

if __name__ == '__main__':

    program_name = sys.argv[1]  # program name
    input_file = sys.argv[2]  # testCases file name

    def timeit(decorated_function):
        """Outputs the time that
        a function takes to run."""

        def wrapper(*args, **kwargs):
            t1 = time.time()
            decorated_function(*args, **kwargs)
            t2 = time.time()
            print("Total running time=", t2 - t1)

        return wrapper

    @timeit
    def run():
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

    run()
