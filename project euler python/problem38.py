# Project Euler Problem 38
import itertools
from lib import EulerUtils as eu




'''
Background on how I chose the limits:
We know that the number must start with 9, since an example is shown where 9 is the first digit in the product
We are looking for a number (i) that has d digits. We take the concatenated product of i and (1, ..., n), and this must have a length of 9
Given the constraints n>1: 
 Choose d = 2: if n = 3: 1*i = 2 digits, 2*i = 3 digits, 3*i = 3 digits. 8 digits total. Nope
               if n = 4: ..., ..., ..., 4*i = 3 digits, 11 digits total. Nope
        d = 3: if n = 2: 1*i = 3 digits, 2*i = 4 digits, 7 digits total. Nope
               if n = 3: ..., ..., 3*i = 4 digits, 11 digits total. Nope
        d = 4: if n = 2: 1*i = 4 digits, 2*i = 9 digits total! WINNER

d = 4, n = 2
The largest possible value of i is 9876, so this is out upper bound.
The smallest is 9123, so this is the lower bound.
Iterate and check!

'''

largestPan = 0
for i in range(9123, 9876):
  str1 = str(i)
  str2 = str(2 * i)
  strConcat = str1 + str2
  concatNum = int(strConcat)
  if eu.isPandigitalNumberOnetoNine(concatNum):
    if concatNum > largestPan:
      largestPan = concatNum
print ("Larget Pandigital Product is: " + str(largestPan))

