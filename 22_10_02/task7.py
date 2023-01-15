import re

def validate_pin(pin):
    pat = re.compile(r'\d{4}|\d{6}')
    return bool(re.fullmatch(pat, pin))
