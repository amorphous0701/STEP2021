def read_number(line, index):
  total = 0
  now_operator=""
  while index < len(line) and line[index].isdigit():
    number=0
    while index < len(line) and line[index].isdigit():
      number = number * 10 + int(line[index])
      index += 1
    if index < len(line) and line[index] == '.':
      index += 1
      decimal = 0.1
      while index < len(line) and line[index].isdigit():
        number += int(line[index]) * decimal
        decimal /= 10
        index += 1
    if now_operator == "*":
      total = total * number
      number = total
    if now_operator == "/":
      total = total / number
      number = total
    if index < len(line) and line[index] == '*':
      index +=1
      now_operator ="*"
    if index < len(line) and line[index] == '/':
      index += 1
      now_operator = "/"
    total = number

  token = {'type': 'NUMBER', 'number': total}
  return token, index


def read_plus(line, index):
  token = {'type': 'PLUS'}
  return token, index + 1


def read_minus(line, index):
  token = {'type': 'MINUS'}
  return token, index + 1


def tokenize(line):
  tokens = []
  index = 0
  while index < len(line):
    if line[index].isdigit():
      (token, index) = read_number(line, index)
    elif line[index] == '+':
      (token, index) = read_plus(line, index)
    elif line[index] == '-':
      (token, index) = read_minus(line, index)
    else:
      print('Invalid character found: ' + line[index])
      exit(1)
    tokens.append(token)
  return tokens


def evaluate(tokens):
  answer = 0
  tokens.insert(0, {'type': 'PLUS'}) # Insert a dummy '+' token
  index = 1
  while index < len(tokens):
    if tokens[index]['type'] == 'NUMBER':
      if tokens[index - 1]['type'] == 'PLUS':
        answer += tokens[index]['number']
      elif tokens[index - 1]['type'] == 'MINUS':
        answer -= tokens[index]['number']
      else:
        print('Invalid syntax')
        exit(1)
    index += 1
  return answer


def test(line):
  tokens = tokenize(line)
  actual_answer = evaluate(tokens)
  expected_answer = eval(line)
  if abs(actual_answer - expected_answer) < 1e-8:
    print("PASS! (%s = %f)" % (line, expected_answer))
  else:
    print("FAIL! (%s should be %f but was %f)" % (line, expected_answer, actual_answer))


# Add more tests to this function :)
def run_test():
  print("==== Test started! ====")
  test("1+2")
  test("1.0+2.1-3")
  test("2*3")
  test("2*3+2/3")
  test("4+3/3")
  test("3*3/9+1-8")
  test("4*3/5+1.8")
  test("1.3+9-7/2")
  print("==== Test finished! ====\n")

run_test()
