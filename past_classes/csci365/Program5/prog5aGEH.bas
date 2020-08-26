1 GOTO 10
Name: Grant Haataja
Program: 5a
Email: grant.haataja@und.edu

10 PRINT "Please enter the cost of a product."
15 INPUT cost
20 PRINT "Please enter the amount of cash paid for the product."
25 INPUT amountPaid
30 IF amountPaid < cost THEN GOTO 40
35 IF amountPaid >= cost THEN GOTO 50
40 PRINT "Insufficient amount paid."
42 SYSTEM
50 change = amountPaid - cost
55 PRINT USING "&$$###.##";"The amount of change is" ,change
56 dollars = 0
57 quarters = 0
58 dimes = 0
59 nickels = 0
60 pennies = 0
61 change = change + 0.00005

65 IF change >= 1 THEN GOTO 70
66 IF change < 1 THEN GOTO 75

70 change = change - 1.00
71 dollars = dollars + 1 
74 GOTO 65

75 IF change >= 0.25 THEN GOTO 80
76 IF change >= 0.1 THEN GOTO 85
77 IF change >= 0.05 THEN GOTO 90
78 IF change >= 0.01 THEN GOTO 95
79 GOTO 100

80 change = change - 0.25
81 quarters = quarters + 1
82 GOTO 75

85 change = change - 0.10
86 dimes = dimes + 1
GOTO 76

90 change = change - 0.05
91 nickels = nickels + 1
92 GOTO 77

95 change = change - 0.01
96 pennies = pennies + 1
97 GOTO 78

100 PRINT USING "&###";"Whole Dollars: ";dollars
105 PRINT USING "&#";"Quarters: ";quarters
110 PRINT USING "&#";"Dimes: ";dimes
120 PRINT USING "&#";"Nickels: ";nickels
130 PRINT USING "&#";"Pennies: ";pennies


200 SYSTEM
