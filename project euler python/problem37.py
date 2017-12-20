from lib import EulerUtils as eu
import math
#Project Euler Problem 37 Solution


def truncateFromRight(n):
  '''Removes rightmost digit from number'''
  # Get rightmost digit
  remainder = n % 10 
  # Remove it from the number
  n -= remainder
  # Divide by 10 to shift number over
  n /= 10
  return int(n)

def truncateFromLeft(n):
  '''Removes leftmost digit from number'''
  #Get power of ten of number
  exp = int(math.log10(n)) 
  # Remove leftmost digit by moduloing by 10^exp
  n = n % math.pow(10, exp)
  return int(n)

def isTruncatablePrime(number):
  #Make sure it is actually prime first
  if not eu.isPrime(number):
    return False
  # Remove digits from right, and check primality
  n = number
  while True:
    n = truncateFromRight(n)
    if n == 0:
      break;
    if not eu.isPrime(n):
      return False

  #If we get to here, number was prime when truncated from right
  n = number
  while True:
    n = truncateFromLeft(n)
    if n == 0:
      break;
    if not eu.isPrime(n):
      return False

  # If we get here, number is prime when truncated from both left and right!
  return True


truncatablePrimeCount = 0
sum = 0
num = 11 #start above 1 digit numbers
while (truncatablePrimeCount < 11):
  if isTruncatablePrime(num):
    truncatablePrimeCount += 1
    sum += num
    print ("Found a truncatable prime: " + str(num))
    print ("Total found: " + str(truncatablePrimeCount))
  num += 2 #avoid even numbers... there's no point in even checking those

print ("Sum of primes: " + str(sum))