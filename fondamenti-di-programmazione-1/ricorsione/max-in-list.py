from random import randint

def main():
  LENGTH = 10
  seq = []

  for _ in range(LENGTH):
    seq.append(randint(0, 1000))

  print(seq)
  print(recursiveMax(seq))
  print(macs(seq))

# Compact version
def macs(seq):
  """Find the max in a list recursively."""
  first = seq[0]
  if len(seq) == 1:
    return first

  bigger = macs(seq[1:])
  return first if first > bigger else bigger

# Commented out version
c = 0
def recursiveMax(sequence):
  global c
  c += 1
  first = sequence[0]

  # Each time macs() is called at first is assigned each value in sequence.
  print("(%d) ENTERING, first: %d" % (c, first))

  if len(sequence) == 1:
    print("(%d) TERMINATING, returning %d" % (c, first))
    # When the base case is reached return the last element in the sequence,
    # which is also the only.
    # So in the call before this macz will be the first in this call and
    # the first in the call before will be the element preceding the current
    # first int the list.
    # It is a matter of previous and next.
    return first

  macz = recursiveMax(sequence[1:]) # THIS IS AN INT

  if macz > first:
    c -= 1
    print("(%d) IF %d > %d: return %d" % (c, macz, first, macz))
    return macz
  else:
    c -= 1
    print("(%d) ELSE: return %d" % (c, first))
    return first

main()
