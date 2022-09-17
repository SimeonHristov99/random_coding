def valid_parentheses(string):
    stack = []

    for s in string:
        if s == '(':
            stack.append(s)
        elif s == ')' and len(stack) > 0 and stack[-1] == '(':
            stack.pop()
        elif not s.isalpha():
            return False

    return stack == []
