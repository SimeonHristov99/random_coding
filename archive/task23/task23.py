def rev_order(s: str):
    return ' '.join(s.split(' ')[::-1])


def test1():
    print(rev_order('Technical Interview Preparation')
          == 'Preparation Interview Technical')


def main():
    test1()


if __name__ == '__main__':
    main()
