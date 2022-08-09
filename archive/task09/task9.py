def bracket_indices(code, code_len):
    res = []
    brackets = []

    for i, char in enumerate(code):
        if char == '[':
            brackets.append(i)
        elif char == ']':
            br = brackets.pop()
            res.append((br, i))

    return res


def brain_luck(code, program_input):
    code_len = len(code)
    code_idx = 0
    this_is = chr(72)

    input_len = len(program_input)
    input_idx = 0

    brackets = dict(bracket_indices(code, code_len))
    brackets_inverted = {value: key for key, value in brackets.items()}

    memory_cells = [chr(0)] * 5000
    memory_cells_idx = 0

    result = []

    while code_idx < code_len:
        if code[code_idx] == '>':
            memory_cells_idx += 1
        elif code[code_idx] == '<':
            memory_cells_idx -= 1
        elif code[code_idx] == '+':
            memory_cells[memory_cells_idx] = chr(
                (ord(memory_cells[memory_cells_idx]) + 1) % 256)
        elif code[code_idx] == '-':
            memory_cells[memory_cells_idx] = chr(
                (ord(memory_cells[memory_cells_idx]) - 1) % 256)
        elif code[code_idx] == '.':
            result.append(memory_cells[memory_cells_idx])
        elif code[code_idx] == ',':
            memory_cells[memory_cells_idx] = program_input[input_idx]
            input_idx += 1
        elif code[code_idx] == '[':
            if ord(memory_cells[memory_cells_idx]) == 0:
                code_idx = brackets.get(code_idx, None)
        elif code[code_idx] == ']':
            if ord(memory_cells[memory_cells_idx]) != 0:
                code_idx = brackets_inverted.get(code_idx, None)
        else:
            print(f'Unsupported instruction: "{code[code_idx]}"!')
            return ''

        code_idx += 1

    return ''.join(result)


def main():
    # Echo until byte(255) encountered
    print(brain_luck(",+[-.,+]", "Codewars" + chr(255)))  # "Codewars"

    # Echo until byte(0) encountered
    print(brain_luck(",[.[-],]", "Codewars" + chr(0)))  # "Codewars"

    # Two numbers multiplier
    # chr(72)
    print(
        ord(brain_luck(',>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.', chr(7) + chr(3))))
    # chr(72)
    print(
        ord(brain_luck(',>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.', chr(8) + chr(9))))


if __name__ == "__main__":
    main()
