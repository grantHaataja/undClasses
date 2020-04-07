1 GOTO 10
Name: Grant Haataja
Program: 5b
Email: grant.haataja@und.edu

10 count = 1

14 IF count > 100 THEN GOTO 40
15 IF count MOD 15 = 0 THEN GOTO 25
16 IF count MOD 3 = 0 THEN GOTO 30
17 IF count MOD 5 = 0 THEN GOTO 35
18 PRINT count
19 count = count + 1
20 GOTO 14

25 PRINT "FizzBuzz"
26 count = count + 1
27 GOTO 14

30 PRINT "Fizz"
31 count = count + 1
32 GOTO 14

35 PRINT "Buzz"
36 count = count + 1
37 GOTO 14

40 SYSTEM

