class Node
  attr_accessor :value, :left, :right, :left_size, :right_size

  def initialize(v)
    @value = v
    @left_size = 0
    @right_size = 0
  end

  def insert(v)
    if value
      if v >= value
        self.right_size+=1
        insert_right(v)
      else
        self.left_size+=1
        insert_left(v)
      end
    else
      self.value = v
    end
  end

  def insert_left(v)
    if left
      left.insert(v)
    else
      self.left = Node.new(v)
    end
  end

  def insert_right(v)
    if right
      right.insert(v)
    else
      self.right = Node.new(v)
    end
  end
end

@dynbin = Hash.new { |hash, key| hash[key] = {} }

def binomial(n, k)
  return 1 if k==0 || k==n

  @dynbin[n-1][k-1] ||= binomial(n-1, k-1)
  @dynbin[n-1][k] ||= binomial(n-1, k)

  @dynbin[n-1][k-1] + @dynbin[n-1][k]
end

def count_binomial(root)
  return 1 if !root

  binomial(root.left_size + root.right_size, root.right_size) * count_binomial(root.left) * count_binomial(root.right)
end

n = 0
$stdin.each_line do |line|
  if n==0
    n = line.to_i
  else
    root = Node.new(nil)

    line.split(' ').each do |value|
      root.insert(value.to_i)
    end

    puts count_binomial(root)

    n=0
  end
end
