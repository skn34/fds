from pprint import pprint

def main():
    string = input('Enter a word string: ')
    stringfreq = dict()

    for i in string:
        stringfreq[i] = stringfreq.get(i, 0) + 1
    stringfreqword = dict()

    for i in string.split():
        stringfreqword[i] = stringfreqword.get(i, 0) + 1

    print(f'\nWord with maximum length: {max(string.split(), key=len)}')
    print(f'\nFrequency of each character:')
    pprint(stringfreq)

    pali = input('\nEnter a string to check Palindrome: ')
    print(f"Given string is {'not ' if pali != pali[::-1] else ''}a palindrome.\n")

    search_substring = input('Enter substring to be searched: ')
    print(f"First occurrence of given substring is at index: {string.index(search_substring)}")

    print(f'\nFrequency of each word:')
    pprint(stringfreqword)

if __name__ == "__main__":
    main()
