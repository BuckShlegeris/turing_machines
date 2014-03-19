left_tape = [0]
right_tape = []

def view_current(left_tape):
  return left_tape[-1]

def change_current(left_tape,value):
  left_tape[-1] = value

def move_left(left_tape, right_tape):

  if len(left_tape) == 1:
    right_tape.append(left_tape.pop())
    left_tape.append(0)
  else:
    right_tape.append(left_tape.pop())
  return (left_tape, right_tape)

def move_right(left_tape, right_tape):
  if len(right_tape) == 0:
    left_tape.append(0)
  else:
    left_tape.append(right_tape.pop())
  return (left_tape, right_tape)

def print_tapes(left_tape, right_tape):
  print [left_tape, right_tape]

def run():
  l,r = left_tape, right_tape
  thing = "l"
  step = 0
  while thing != "x":
    step += 1
    thing = raw_input()
    change_current(left_tape, step)
    if thing=="l":
      move_left(l,r)
    if thing=="r":
      move_right(l,r)
    print_tapes(l,r)
run()