# coding: utf-8
FILENAME = "number.txt"

def read_number(filename)
  File.open(filename, "r") {|file| file.read }
end


def mult_ints(int_list)
  res = 1

  # Sum each digit from the given number, accounting for their ascci value
  int_list.to_s.each_char do |c| #OPTIMIZE
    res *= c.ord - 48
  end

  res
end


# This could be greatly optimized. We could account for the presence of 0 and avoid unnecessary calculus, or for each iteration only calculating the division of the previous first element and the multiplication of the next, aswell as some minor improvements.
def iterate_number(block_size)
  number_s = read_number(FILENAME)

  i_index = 0
  best_index = i_index
  e_index = block_size - 1

  last_res = 0
  best_res = last_res

  while e_index < number_s.length do
    last_res = mult_ints(number_s[i_index..e_index])

    if last_res > best_res
      best_res = last_res
      best_index = i_index
    end

    e_index += 1
    i_index += 1
  end

  print("Best result: #{best_res}\n")
  print("Best combo: #{number_s[best_index..best_index + block_size - 1]}")
end


iterate_number(ARGV[0].to_i)
