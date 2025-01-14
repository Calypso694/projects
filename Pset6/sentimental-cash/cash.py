from cs50 import get_string, get_int, get_float


def get_cents():
    pass
def get_cents(void):
    pass
def calculate_quarters(cents):
    pass
def calculate_dimes(cents):
    pass
def calculate_nickels(cents):
    pass
def calculate_pennies(cents):
    pass

def main():
    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(f"{coins}")
#end of main

# ask user for Change Owed, done with a do/while loop to keep prompting User for POS Ints
def get_cents():
    while True:
        cents = get_float("Change Owed: ")
        if cents >= 0:
            break
    return int(cents * 100)  # convert dollars to cents


def calculate_quarters(cents):
    quarters = cents // 25
    return quarters


def calculate_dimes(cents):
    dimes = cents // 10
    return dimes


def calculate_nickels(cents):
    nickels = cents // 5
    return nickels


def calculate_pennies(cents):
    pennies = cents // 1
    return pennies


if __name__ == "__main__":
    main()
