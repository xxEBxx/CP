def arithmetic_arranger(problems, calculate=False):
    if len(problems) > 5:
        return "Error: Too many problems."

    arranged_problems = {"top": [], "bottom": [], "line": [], "result": []}
    for problem in problems:
        operand1, operator, operand2 = problem.split()

        if operator not in ['+', '-']:
            return "Error: Operator must be '+' or '-'."

        if not operand1.isdigit() or not operand2.isdigit():
            return "Error: Numbers must only contain digits."

        if len(operand1) > 4 or len(operand2) > 4:
            return "Error: Numbers cannot be more than four digits."

        width = max(len(operand1), len(operand2)) + 2
        arranged_problems["top"].append(operand1.rjust(width))
        arranged_problems["bottom"].append(operator + operand2.rjust(width - 1))
        arranged_problems["line"].append('-' * width)

        if calculate:
            if operator == "+":
                result = str(int(operand1) + int(operand2)).rjust(width)
            else:
                result = str(int(operand1) - int(operand2)).rjust(width)
            arranged_problems["result"].append(result)

    arranged_output = ""
    for i in range(len(arranged_problems["top"])):
        arranged_output += arranged_problems["top"][i] + "    "
    arranged_output = arranged_output.rstrip() + "\n"

    for i in range(len(arranged_problems["bottom"])):
        arranged_output += arranged_problems["bottom"][i] + "    "
    arranged_output = arranged_output.rstrip() + "\n"

    for i in range(len(arranged_problems["line"])):
        arranged_output += arranged_problems["line"][i] + "    "
    arranged_output = arranged_output.rstrip()

    if calculate:
        arranged_output += "\n"
        for i in range(len(arranged_problems["result"])):
            arranged_output += arranged_problems["result"][i] + "    "
        arranged_output = arranged_output.rstrip()

    return arranged_output


# Test cases
print(arithmetic_arranger(["32 + 698", "3801 - 2", "45 + 43", "123 + 49"]))
print(arithmetic_arranger(["32 + 8", "1 - 3801", "9999 + 9999", "523 - 49"], True))
