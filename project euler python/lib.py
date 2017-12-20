#Project Euler Utility Class
import math

class EulerUtils():
  def __init__(self):
    print ("This class is intended to be used statically.")

  @staticmethod
  def isPalindrome(numberString):
    reverseNumberString = numberString[::-1]
    if (reverseNumberString == numberString):
      return True
    else:
      return False

  @staticmethod
  def isPrime(n):
    if n <= 1:
      return False
    elif n <= 3:
      return True
    elif n % 2 == 0 or n % 3 == 0:
      return False
    i = 5
    while i*i <= n:
      if n % i == 0 or n % (i + 2) == 0:
        return False
      i += 6
    return True

  @staticmethod    
  def isPandigitalNumberOnetoNine(n):
    if len(str(n)) != 9:
      return False
    else:
      characterSeen = [False]*9 # Use digits as index into array
      for c in str(n):
        characterSeen[int(c) - 1] = True
      return all(character == True for character in characterSeen)