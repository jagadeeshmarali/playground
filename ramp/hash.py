import hashlib
with open('word-list-7-letters.txt') as f:
    lines = [line.rstrip('\n') for line in f]
    # print(lines)
    salt = "020d5efe9f41"
    hash = "6f462ccfb53c5e460015ae124cdb23a2"
    for l in lines:
      result = hashlib.md5((l+salt).encode()).hexdigest()
      # print(result)
      if result == hash:
        print(l)
        