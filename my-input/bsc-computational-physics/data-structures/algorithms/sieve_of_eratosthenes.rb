# Algoritmo Crivo de Eratóstenes - para encontrar números primos até um certo valor limite #

def generate_range(first, last)
  range=*(first..last)
end

def min_number(range)
  range.min
end

def max_number(range)
  Math.sqrt(range.max).floor
end

def remove_multiple(range, x)
  range.each do |n|
    range.delete(n) if n % x == 0 && n != x
  end
end

def prime_number(range)
  min_number = min_number(range)
  max_number = max_number(range)

  (min_number..max_number).each do |i|
    range = remove_multiple(range, i) if range.include? i
  end
  range
end

range = generate_range(2, 30)

puts prime_number(range)
