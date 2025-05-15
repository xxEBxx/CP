def process_line(line):
    # Initialize variables
    word1 = ''
    word2 = ''
    i = 0
    
    # Extract the first word
    while line[i] != ' ':
        word1 += line[i]
        i += 1
    i += 1  # Move past the space
    
    # Extract the second word
    while line[i] != '\n':
        word2 += line[i]
        i += 1

    # Do something with the first two words
    result = word1.upper() + " " + word2.lower()
    return result


def main(input_file):
    try:
        with open(input_file, 'r') as file:
            i=0
            line=""
            while file[i]!='\n':
                for line in file:
                    processed_line = process_line(line)
                    print("HELLO")
                    print(processed_line)
    except FileNotFoundError:
        print(f"Error: File '{input_file}' not found.")

input_file = "input.txt"
main(input_file)
