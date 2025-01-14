def main():
    jar = Jar()
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(2)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))

class Jar:
    def __init__(self, capacity=12):
        if not isinstance(capacity,int) or capacity < 0:
           raise ValueError("Capacity must be a non-negative integer.")
        self.capacity = capacity
        self.cookies = 0

    def __str__(self):
        return "There are {} cookies in the jar".format(self.cookies * '\U0001F36A')

    def deposit(self, n):
       self.cookies += n
       if self.cookies > self.capacity:
            raise ValueError("Capacity met. No more Cookies.")

    def withdraw(self, n):
        if self.cookies >= n:
            self.cookies -= n
        else:
            raise ValueError("Not enough cookies in the jar")

@property
def capacity(self):
    return self._capacity

@capacity.setter
def capacity(self, value):
    # Add your validation logic here
    self._capacity = value

    @property
    def size(self):
        return self.cookies

if __name__ == "__main__":
    main()
