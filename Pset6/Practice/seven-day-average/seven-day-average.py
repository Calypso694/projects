import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    states = []
empty_dictionary = {state: 0 for dictionary in states}
for row in reader:
    state = row['state']  # assuming 'state' is the field name for states
    if state not in empty_dictionary:
        empty_dictionary[state] = []


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    numerator = []
    denominator = []
    new_cases = 0
    states = new_cases 
    try:
    numerator / denominator
except ZeroDivisionError:
    ...


main()