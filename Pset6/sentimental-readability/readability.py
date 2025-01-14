from cs50 import get_string, get_float

def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters

def count_words(text):
    words = 1
    for char in text:
        if char == ' ':
            words += 1
    return words

def count_sentences(text):
    sentences = 0
    for char in text:
        if char in ['.', '?', '!']:
            sentences += 1
    return sentences

def grade_function(text):
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    index = 0.0588 * (letters * 100 / words) - 0.296 * (sentences * 100 / words) - 15.8
    grade = round(index)

    if index < 1:
        print("Before Grade 1")
        return 0
    elif index >= 16:
        print("Grade 16+")
        return 0
    else:
        print(f"Grade {grade}")

    return index

def main():
    text = input("Text: ")
    grade = grade_function(text)

if __name__ == "__main__":
    main()

