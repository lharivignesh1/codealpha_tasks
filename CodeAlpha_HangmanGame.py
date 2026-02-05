import random

words = ["code","alpha","intern","hari","python","program"]
secret_word = random.choice(words)
guessed_letters = []
display = ["_"] * len(secret_word)
chances = 6

print("Welcome to Hangman Game")
while(chances > 0 and "_" in display):
    print("\nWord:", " ".join(display))
    print("Guessed letters:", guessed_letters)
    print("Remaining chances:", chances)

    letter = input("Enter a letter: ").lower()

    if (not letter.isalpha() or len(letter) != 1):
        print("Please enter a single alphabet.")
        continue

    if (letter in guessed_letters):
        print("You already guessed this letter.")
        continue

    guessed_letters.append(letter)

    if (letter in secret_word):
        for i in range(len(secret_word)):
            if (secret_word[i] == letter):
                display[i] = letter
        print("Good guess!")
    else:
        chances -= 1
        print("Wrong guess!")

if ("_" not in display):
    print("\nCongratulations! You guessed the word:", secret_word)
else:
    print("\nGame Over! The word was:", secret_word)

