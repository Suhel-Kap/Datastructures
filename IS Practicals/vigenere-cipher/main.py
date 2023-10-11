from math import ceil

def alphabetToInt(char):  # convert alphabet to 0 based index ( 0 to 25 for a to z)
    return ord(char) - ord("a")

def intToAlphabet(char):  # convert int of 0 based index to alphabet ( a to z for 0 to 25 )
    return chr(char + ord("a"))

def processKey(key, data, autokey):
    if len(key) < len(data):
        if autokey:
            key = key + data
        else:
            lenDiff = len(data) - len(key)
            repeatTimes = ceil(lenDiff / len(key)) + 1
            key = key * repeatTimes
    return key


def keyDataArithmeticWithMod(key, data, operator="+"):
    if operator != "+" and operator != "-":
        print("Invalid operator " + operator)
        return (False, None)
    if len(key) < len(data):
        print("Length of key is smaller than length of input")
        return (False, None)
    res = ""
    for i in range(len(data)):
        ki = alphabetToInt(key[i])
        if operator == "+":
            pi = alphabetToInt(data[i])
            res += intToAlphabet((pi + ki) % 26)
        else:
            ci = alphabetToInt(data[i])
            res += intToAlphabet((ci - ki) % 26)
    return (True, res)


def encrypt(key, data, autokey):
    data = data.lower()
    key = processKey(key, data, autokey)
    (success, result) = keyDataArithmeticWithMod(key, data, "+")
    print(result)
    encytped_pt_file = open("cipher_encrypted.txt", "w+", encoding="utf-8")
    encytped_pt_file.write(result)
    encytped_pt_file.close()
    print("Encrypted successfully")


def decrypt(key, data, autokey):
    data = data.lower()
    result = ""
    if autokey:
        if len(key) < len(data):
            lenDiff = len(data) - len(key)
            repeatTimes = ceil(lenDiff / len(key)) + 1
            res = ""
            data1 = data[0: len(key)]
            key1 = key
            for i in range(repeatTimes):
                (success, res1) = keyDataArithmeticWithMod(key1, data1, "-")
                data1 = data[(i + 1) * len(key)                             :((i + 1) * len(key)) + len(key)]
                key1 = res1
                res += res1
            result = res
        else:
            (success, result) = keyDataArithmeticWithMod(key, data, "-")
    else:
        key = processKey(key, data, autokey)
        (success, result) = keyDataArithmeticWithMod(key, data, "-")
    print(result)
    decrypted_pt_file = open("cipher_decrypted.txt", "w+", encoding="utf-8")
    decrypted_pt_file.write(result)
    decrypted_pt_file.close()
    print("Decrypted successfully")

def displayMenu():
    print("1. Encrypt file")
    print("2. Decrypt file")
    print("3. Exit")
    choice = int(input("Please make a selection: "))
    return choice


if __name__ == "__main__":
    selection = displayMenu()
    while selection != 3:
        if selection == 1:
            plaintext = open("plain.txt", "r", encoding="utf-8")
            plaintext = plaintext.read()
            cipherType = input("Enter 'vigenere' or 'autokey': ")
            key = input("Enter key to encrypt: ")
            encrypt(key, plaintext, cipherType)
        elif selection == 2:
            ciphertext = open("cipher_encrypted.txt", "r", encoding="utf-8")
            ciphertext = ciphertext.read()
            cipherType = input("Enter 'vigenere' or 'autokey': ")
            key = input("Enter key to decrypt: ")
            decrypt(key, ciphertext, cipherType)
        else:
            print("Invalid selection")
        selection = displayMenu()
