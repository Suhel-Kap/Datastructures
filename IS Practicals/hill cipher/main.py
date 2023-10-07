mBlock = 3
key = "ZXCVBNMLK"

def generateEmptyKeyMatrix():
    mat = []
    k = 0
    for i in range(mBlock):
        subLst = []
        for j in range(mBlock):
            subLst.append(key[k])
            k += 1
        mat.append(subLst)
    return mat

def generateEmptyPlainVector():
    vec = [0] * mBlock
    return vec

def fillKeyMatrix(mat):
    for i in range(mBlock):
        for j in range(mBlock):
            mat[i][j] = ord(mat[i][j]) % 65
    return mat

def fillPlainTextVector(vec, data):
    for i in range(mBlock):
        vec[i] = ord(data[i]) % 65
    return vec

def encrypt(data):
    # Ensure the key and data lengths match
    if len(key) != mBlock * mBlock:
        print("Error: Key length is not equal to mBlock * mBlock.")
        return

    # Get the fixed 3x3 key matrix
    emptyKeyMatrix = generateEmptyKeyMatrix()
    keyMatrix = fillKeyMatrix(emptyKeyMatrix)

    # Convert data to uppercase and pad if needed
    data = data.upper()
    if len(data) % mBlock != 0:
        print("Error: Data length is not a multiple of mBlock.")
        return

    numBlocks = len(data) // mBlock
    encrypted = ""

    for block in range(numBlocks):
        blockData = data[block * mBlock: (block + 1) * mBlock]
        emptyPlainTextVector = generateEmptyPlainVector()
        plainTextVector = fillPlainTextVector(emptyPlainTextVector, blockData)

        # Perform encryption using keyMatrix and plainTextVector
        encryptedVector = [0] * mBlock

        for i in range(mBlock):
            for j in range(mBlock):
                encryptedVector[i] += keyMatrix[i][j] * plainTextVector[j]
            encryptedVector[i] %= 26  # Assuming modulo 26 for the alphabet

        # Convert the encrypted vector to characters and append to the result
        for value in encryptedVector:
            encrypted += chr(value + 65)  # Convert back to uppercase letters

    encytped_pt_file = open("cipher_encrypted.txt", "w+")
    encytped_pt_file.write(encrypted)
    encytped_pt_file.close()
    print("Encryption completed.")

def displayMenu():
    print("1. Encrypt file")
    print("2. Exit")
    choice = int(input("Please make a selection: "))
    return choice

if __name__ == "__main__":
    selection = displayMenu()
    while selection != 2:
        if selection == 1:
            plaintext = open("plain.txt", "r")
            plaintext = plaintext.read()
            encrypt(plaintext)
        else:
            print("Invalid selection")
        selection = displayMenu()
