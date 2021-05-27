def read_number(line, index):
  now_operator=""
  total = 0
  top_minus = 1
  if line[index] == '-':
    top_minus = -1
    index += 1
  while index < len(line) and line[index].isdigit():
    number = 0
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
      if line[index]== '-':
        number *= -1
        index +=1
    if index < len(line) and line[index] == '/':
      index += 1
      now_operator = "/"
      if line[index]== '-':
        number *= -1
        index +=1
    total = number * top_minus
    top_minus = 1

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
      if index == 0:
        (token, index) = read_number(line, index)
      else:
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

def new_line(line,max_p,check):
  if max_p==0 and check==len(line)-1:
    return line[max_p+1:check]
  elif max_p==0:
    return str(evaluate(tokenize(line[max_p+1:check])))+line[check+1:]
  elif check==len(line)-1:
    return line[:max_p]+str(evaluate(tokenize(line[max_p+1:check])))
  else:
    return line[:max_p]+str(evaluate(tokenize(line[max_p+1:check])))+line[check+1:]

def out_parenthesis(line):
  max_p=0
  if line.count("(") != line.count(")"):
    print('Parenthesis Error')
    exit(1)
  while '(' in line :
    for check in range(len(line)):
      if line[check]=="(":
        max_p = check
      if line[check]==")":
        line=new_line(line,max_p,check)
        break
  return line

def test(line):
  new_line = out_parenthesis(line)
  tokens = tokenize(new_line)
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
  test("1.3+9.8-7/2*3.2")
  test("(1+2)/3")
  test("(1/3+1*4)")
  test("(9+8)*(1-2)/(2+3)")
  test("(+1-3)*(-3)/(-1.4)")
  test("((1-2)/(2.1+3.2))*(-3)/(9.9)")
  test("((1-2)/3/(2.1+3.2))*(-3)/(9.9)")
  test("((((1+2))*9))")
  print("==== Test finished! ====\n")

run_test()
