def format_duration(seconds):
    result = ''

    if seconds == 0:
        return 'now'

    words = ['year', 'day', 'hour', 'minute', 'second']
    units = [31536000, 86400, 3600, 60, 1]

    for i in range(len(units)):
        current_num = seconds // units[i]

        if current_num > 0:
            seconds -= current_num * units[i]

            if len(result) > 0:
                result += " and " if seconds == 0 else ", "

            result += f'{current_num} {words[i]}{"s" if current_num > 1 else ""}'

    return result


def main():
    print(format_duration(0))     # "now"
    print(format_duration(1))     # "1 second"
    print(format_duration(62))    # "1 minute and 2 seconds"
    print(format_duration(120))   # "2 minutes"
    print(format_duration(3662))  # "1 hour, 1 minute and 2 seconds"


if __name__ == '__main__':
    main()
