def get_size():
    pass


def print_grid(size):
    pass


def main():
    height = get_size()
    print_grid(height)


def get_size():
    while True:
        try:
            height = int(input("Enter a Height between 1 and 8: "))
            if 1 <= height <= 8:
                return height
            else:
                print("Invalid input. Please enter a number between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a number.")


def print_grid(size):
    for height in range(size):
        for space in range(height, size - 1):
            print(" ", end="")
        for row in range(height + 1):
            print("#", end="")
        print()


if __name__ == "__main__":
    main()
