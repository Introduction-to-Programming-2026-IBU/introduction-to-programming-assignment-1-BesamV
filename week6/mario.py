# Ask for height
while True:
    try:
        height = int(input("Height: "))
        if 1 <= height <= 8:
            break
    except:
        pass

# Print pyramid
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)
# Ask for height
while True:
    try:
        height = int(input("Height: "))
        if 1 <= height <= 8:
            break
    except:
        pass

# Print double pyramid
for i in range(1, height + 1):
    spaces = " " * (height - i)
    blocks = "#" * i
    print(spaces + blocks + "  " + blocks)
