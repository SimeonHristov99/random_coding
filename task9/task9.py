def bracket_indices(code, code_len):
    brackets_op = [
        idx
        for idx, bracket in enumerate(code)
        if bracket == '['
    ]

    brackets_cl = [
        code_len - idx - 1
        for idx, bracket in enumerate(code[::-1])
        if bracket == ']'
    ]

    indices = dict(zip(brackets_op, brackets_cl))
    return indices

def brain_luck(code, program_input):
    code_len = len(code)
    code_idx = 0
    
    input_len = len(program_input)
    input_idx = 0

    brackets = bracket_indices(code, code_len)
    brackets_inverted = {value: key for key, value in brackets.items()}

    current_char = '0'

    result = []

    while code_idx < code_len:
        if code[code_idx] == '>':
            pass
        elif code[code_idx] == '<':
            pass
        elif code[code_idx] == '+':
            current_char = chr((ord(current_char) + 1) % 256)
        elif code[code_idx] == '-':
            current_char = chr((ord(current_char) - 1) % 256)
        elif code[code_idx] == '.':
            result.append(current_char)
        elif code[code_idx] == ',':
            current_char = program_input[input_idx]
            input_idx += 1
        elif code[code_idx] == '[':
            if ord(current_char) == 0:
                code_idx = bracket_indices.get(code_idx, None)
        elif code[code_idx] == ']':
            if ord(current_char) != 0:
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
    print(brain_luck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.", chr(8) + chr(9)))  # chr(72)


if __name__ == "__main__":
    main()
