import numpy as np
from lib import EulerUtils as eu

# Problem 36 solution! 



def checkIfNumberIsPalindromeInBothBases(number):
  numberString = str(number)
  baseTwoString = "{0:b}".format(number)
  if (eu.isPalindrome(numberString) and eu.isPalindrome(baseTwoString)):
    return True
  else:
    return False

sum = sum(x for x in range(1000000) if checkIfNumberIsPalindromeInBothBases(x))
print (sum)

