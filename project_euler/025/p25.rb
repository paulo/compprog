def fibonacci_n(limit)
  fn1 = 1
  fn2 = 1
  index = 3

  # Typical fibonacci algorithm, not even looking to optimize. Ruby has a pretty awesome way of dealing with big numbers.
  loop do
    aux = fn1
    fn1 = fn1 + fn2
    fn2 = aux
    break if fn1.to_s.length >= limit
    index += 1
  end

  print(index)
end

fibonacci_n(ARGV[0].to_i)
