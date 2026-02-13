import re
import sys

def convert_indent(line):
    # Extract leading whitespace
    leading = re.match(r'^(\s*)', line).group(1)

    # Replace tabs with 2 spaces
    leading = leading.replace('\t', '  ')

    # Replace groups of 4 spaces with 2 spaces
    leading = re.sub(r' {4}', '  ', leading)

    # Reattach modified indentation to the rest of the line
    return leading + line[len(re.match(r'^(\s*)', line).group(1)):]

def process_file(input_path, output_path):
    with open(input_path, 'r') as f:
        lines = f.readlines()

    with open(output_path, 'w') as f:
        for line in lines:
            f.write(convert_indent(line))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python indent_fix.py <input.cpp> <output.cpp>")
        sys.exit(1)

    process_file(sys.argv[1], sys.argv[2])
