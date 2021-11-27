class User:

    def __init__(self) -> None:
        self.rank = -8
        self.progress = 0

    def inc_progress(self, rank):
        if not (-8 <= rank <= 8 and rank != 0):
            raise Exception("Invalid input")

        if self.rank == 8:
            self.progress = 0
            return

        if rank == self.rank:
            self.progress += 3
        elif rank == self.rank - 1 or self.rank == 1 and rank == -1:
            self.progress += 1
        elif rank > self.rank:
            difference = rank - self.rank - int(rank > 0 and self.rank < 0)
            self.progress += 10 * difference**2

        if self.progress > 99:
            was_below = self.rank < 0
            self.rank += self.progress // 100
            self.rank += int(self.rank > -1 and was_below)
            self.rank = self.rank if self.rank < 9 else 8
            self.progress = self.progress % 100 if self.rank != 8 else 0


def test1():
    user = User()
    user.rank = -7
    user.progress = 60

    user.inc_progress(7)

    print(user.rank)  # 10


def test2():
    user = User()
    user.inc_progress(1)  # -2
    print(user.rank)


def main():
    test1()
    # test2()


if __name__ == '__main__':
    main()
