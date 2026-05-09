# Get card number
number = input("Number: ")

# Convert to list of digits
digits = [int(d) for d in number]

# Luhn’s Algorithm
sum1 = 0
sum2 = 0

# From second last digit
for i in range(len(digits) - 2, -1, -2):
    x = digits[i] * 2
    sum1 += x // 10 + x % 10

# Remaining digits
for i in range(len(digits) - 1, -1, -2):
    sum2 += digits[i]

total = sum1 + sum2

# Check validity
if total % 10 == 0:
    if number.startswith("4"):
        print("VISA")
    elif number.startswith(("34", "37")):
        print("AMEX")
    elif number.startswith(("51", "52", "53", "54", "55")):
        print("MASTERCARD")
    else:
        print("VALID")
else:
    print("INVALID")
