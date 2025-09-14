from sys import argv
from pyfiglet import Figlet

figlet = Figlet()
figlet.getFonts()

if len(argv) == 1:
    # Choose a random font

    font = random.choice(figlet.getFonts())
    figlet.setFont(font=font)
    usertext = input("Input: ")
    print(figlet.renderText(usertext))
elif len(argv) == 3 and (argv[1] == '-f' or argv[1] == '--font'):
    # Set the font to argv[2]
    figlet.setFont(font=argv[2])
    usertext = input("Input: ")
    print("Output: ")
    print(figlet.renderText(usertext))
else:
    print("Invalid input - exmp: python figlet.py -f slant")
    sys.exit()
    # Handle invalid input
