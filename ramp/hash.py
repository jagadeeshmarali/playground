import hashlib
with open('word-list-7-letters.txt') as f:
    lines = [line.rstrip('\n') for line in f]
    # print(lines)
    salt = "993e196002db"
    hash = "7edbb232ab7b484f1939c6e93403eb71"
    for l in lines:
      result = hashlib.md5((l+salt).encode()).hexdigest()
      # print(result)
      if result == hash:
        print(l)
        