FILENAME = "nums.txt"
MATRIX_SIZE = 20

def read_number(filename)
  File.open(filename, "r") {|file| file.read }
end

def create_matrix(numbers)
  matrix = []
  numbers.split("\n").each do |x|
    array = []
    ind_nums = x.split(' ')

    ind_nums.each do |n|
      array << n.to_i
    end

    matrix << array
  end

  matrix
end

def calc_right(a,b, matrix)
  matrix[a][b] *
    matrix[a][(b+1) % MATRIX_SIZE] *
    matrix[a][(b+2) % MATRIX_SIZE] *
    matrix[a][(b+3) % MATRIX_SIZE]
end

def calc_down(a,b, matrix)
  matrix[a][b] *
    matrix[(a+1) % MATRIX_SIZE][b] *
    matrix[(a+2) % MATRIX_SIZE][b] *
    matrix[(a+3) % MATRIX_SIZE][b]
end

def calc_down_left(a,b, matrix)
  matrix[a][b] *
    matrix[(a+1) % MATRIX_SIZE][(b-1) % MATRIX_SIZE] *
    matrix[(a+2) % MATRIX_SIZE][(b-2) % MATRIX_SIZE] *
    matrix[(a+3) % MATRIX_SIZE][(b-3) % MATRIX_SIZE]
end

def calc_down_right(a,b, matrix)
  matrix[a][b] *
    matrix[(a+1) % MATRIX_SIZE][(b+1) % MATRIX_SIZE] *
    matrix[(a+2) % MATRIX_SIZE][(b+2) % MATRIX_SIZE] *
    matrix[(a+3) % MATRIX_SIZE][(b+3) % MATRIX_SIZE]
end

# Since i'm calculating every combination for every number, it suffices to calculate right and down, as I'll be using the % operator.
# However, were going to need to account for both directions of the diagonal (down-left and down-right).
def calc_matrix_max(matrix)
  i = 0; j = 0
  best_res = 0

  while i < 20 do
    j = 0
    while j < 20 do
      num = []
      num << calc_right(i, j, matrix)
      num << calc_down(i, j, matrix)
      num << calc_down_left(i, j, matrix)
      num << calc_down_right(i, j, matrix)

      best_res = best_res > num.max ? best_res : num.max
      j += 1
    end
    i += 1
  end
  best_res
end

m = create_matrix(read_number(FILENAME))

print(calc_matrix_max(m))
