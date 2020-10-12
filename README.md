# Separate Chaining Hash Table
Implementing separate chaining hash table data structure in C

Compile C scripts
```bash
gcc hash.c -o hash
```

Run the sample program that demonstrate the data structure
```bash
./hash

table now is not empty:

key(0):
key(1):  91  11
key(2):  12  22
key(3):  13
key(4):  94
key(5):
key(6):
key(7):
key(8):
key(9):  19

try now to search for and delete some values: (0 means False while 1 is True)
search for value 13 --> 1
search for value 11 --> 1
search by index 1 --> value 91 found
remove value 13 --> 1
search again for value 13 --> 0
try again to remove value 13 --> 0

print the table after the deletion

key(0):
key(1):  91  11
key(2):  12  22
key(3):
key(4):  94
key(5):
key(6):
key(7):
key(8):
key(9):  19

insert value 4

key(0):
key(1):  91  11
key(2):  12  22
key(3):
key(4):  4  94
key(5):
key(6):
key(7):
key(8):
key(9):  19

search by index 4 --> value 4 is found

remove value 91 --> 1

table is now looking like:

key(0):
key(1):  11
key(2):  12  22
key(3):
key(4):  4  94
key(5):
key(6):
key(7):
key(8):
key(9):  19
```
