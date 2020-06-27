require 'prime'

AMOUNT = 2000000

# Gotta love ruby. It enumerates the first 2000000 primes and all you have to do is sum them.

sum = 0

Prime.instance.each(AMOUNT) { |p| sum += p }

print(sum)
