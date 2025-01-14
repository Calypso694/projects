greeting = input("Greeting: ")
greeting = greeting.lstrip()

if greeting.lower().startswith("hello"):
        print("$0")
elif greeting.lower().startswith("h"):
    print("$20")
elif not greeting.lower().startswith("hello"):
     print("$100")
elif not greeting.lower().startswith("h"):
    print("$100")







