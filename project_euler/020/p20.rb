def create_list()
  # Read argument from command line
  size = ARGV[0].to_i

  # Create list of 1 to read value
  list = [*1..size]
end


def sum_ints(int_list)
  res = 0

  # Sum each digit from the given number, accounting for their ascci value
  int_list.to_s.each_char do |c| #OPTIMIZE
    res += c.ord - 48
  end

  res
end


def calc_frac()
  res = 1
  numbers = create_list

  # Multiply numbers of given list (calculate factorial)
  # Ruby is able to convert a fixnum into a bignum if needed
  numbers.each do |n|
    res = res * n
  end

  print("Result for #{ARGV[0]}: #{sum_ints(res)}")
end

calc_frac
