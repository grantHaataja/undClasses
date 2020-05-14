#CSCI370 - Assignment 1
#Grant Haataja
.data
startMessage: .asciiz "\nStart a one-player tic-tac-toe game.\n"
pieceMessage: .asciiz "Pick a piece to start (X/O): "
pieceError: .asciiz "\nInvalid piece!  "
continueMessage: .asciiz "Continue? (y/n) "
continueError: .asciiz "\nInvalid character!   "
newGameMessage: .asciiz "\nNew game? (y/n) "
nextMove: .asciiz "\nEnter the next move (1-9): "
moveError: .asciiz "\nInvalid move!  "
X: .asciiz "X"
O: .asciiz "O"
x: .asciiz "x"
o: .asciiz "o"
board:
.ascii   "\n\n        | |        1|2|3\n       -----       -----"
.ascii     "\n        | |        4|5|6\n       -----       -----"
.asciiz    "\n        | |        7|8|9\n"
ogboard:
.ascii   "\n\n        | |        1|2|3\n       -----       -----"
.ascii     "\n        | |        4|5|6\n       -----       -----"
.asciiz    "\n        | |        7|8|9\n"

.text
#program begins executing here: this is where the game starts
main:
#print starting message
li $v0, 4
la $a0, startMessage
syscall
#save X and O to temp registers
li $t0, 'X'
li $t1, 'O'
li $t2, 'x'
li $t3, 'o'

userInput:
#tell the user to pick a piece to start
li $v0, 4
la $a0, pieceMessage
syscall
#get the user's choice from input
li $v0, 12
syscall
#save user's choice for reference later
move $s5, $v0
#check to see if the user's choice was valid
beq $v0, $t0, step1
beq $v0, $t1, step1
beq $v0, $t2, step1
beq $v0, $t3, step1
#if user's choice is wrong, no branching occurs and we print the appropriate error message
li $v0, 4
la $a0, pieceError
syscall
#jump back to the start of userInput routine to try again
j userInput

#subroutine to print board
printBoard:
li $v0, 4
la $a0, board
syscall
jr $ra

step1:
#jump and link to the printBoard subroutine to print out the unwritten board
jal printBoard

step2:
#save moves 1-9 in temp registers for comparison
li $t0, '1'
li $t1, '2'
li $t2, '3'
li $t3, '4'
li $t4, '5'
li $t5, '6'
li $t6, '7'
li $t7, '8'
li $t8, '9'
#prompt the user to choose a move
li $v0, 4
la $a0, nextMove
syscall
#get user's move
li $v0, 12
syscall
#check if user entered a valid move
beq $v0, $t0, offset
beq $v0, $t1, offset
beq $v0, $t2, offset
beq $v0, $t3, offset
beq $v0, $t4, offset
beq $v0, $t5, offset
beq $v0, $t6, offset
beq $v0, $t7, offset
beq $v0, $t8, offset
#if user's choice is wrong, no branching occurs and we print the appropriate error message
li $v0, 4
la $a0, moveError
syscall
#jump back to the start of step2 routine to try again
j step2

#subroutine to find offset and modify board string
offset:
#correct for using char data types
subi $s0, $v0, 48
#calculate offset to determine where to save user moves
subi $t0, $s0, 1
div $t1, $t0, 3
mul $t2, $t1, 44
addi $t3, $t2, 7
mul $t4, $s0, 2
add $s1, $t3, $t4
#now check if an X or O
beq $s5, 'X', writeX
beq $s5, 'x', writeX
beq $s5, 'O', writeO
beq $s5, 'o', writeO

#subroutine if the user enters a move that has already been taken
wrongChoice:
li $v0, 4
la $a0, moveError
syscall
#jump back to the start of step2 routine to try again
j step2

writeX:
lb $t0, board($s1)
li $t1, 'X'
li $t2, 'O'
beq $t0, $t2, wrongChoice
beq $t0, $t1, wrongChoice
#now commit the user's move to the board string
li $t1, 'X'
sb $t1, board($s1)
li $s5, 'O'
j step3

writeO:
lb $t0, board($s1)
li $t1, 'X'
li $t2, 'O'
beq $t0, $t2, wrongChoice
beq $t0, $t1, wrongChoice
#now commit the user's move to the board string
li $t1, 'O'
sb $t1, board($s1)
li $s5, 'X'

step3:
#jump and link to subroutine to print the modified board
jal printBoard

continue:
#ask the user if they wish to continue
li $v0, 4
la $a0, continueMessage
syscall
#get user's choice
li $v0, 12
syscall
beq $v0, 'n' newGame
beq $v0, 'N' newGame
beq $v0, 'y' step2
beq $v0, 'Y' step2
#if the user chooses anything else, no branching occurs and we print the error message
li $v0, 4
la $a0, continueError
syscall
j continue

newGame:
#ask the user if they wish to start a new game or exit
li $v0, 4
la $a0, newGameMessage
syscall
#get user's choice for starting a new game or not
li $v0, 12
syscall
beq $v0, 'n' exit
beq $v0, 'N' exit
beq $v0, 'y' cleanUp
beq $v0, 'Y' cleanUp
#if the user chooses anything else, no branching occurs and we print the error message
li $v0, 4
la $a0, continueError
syscall
j newGame

#reset the board and jump back to main to start a new game
cleanUp:
#load addresses of written and unwritten boards, as well as the length of board string
la $a0, board
la $a1, ogboard
la $a2, 128
#store address of written board in temp register
move $t0, $a0
#store address of unwritten board in temp register
move $t1, $a1
#store address of the byte just past the end of board string
add $t2, $a0, $a2

copy:
#stop if we reach the end of the board string
beq $t0, $t2, finish
#otherwise continue copying byte by byte
lbu $t3, 0($t1)
sb $t3, 0($t0)
addi $t0, $t0, 1
addi $t1, $t1, 1
#stop if we reach a null terminator
beq $t3, $zero, main
#otherwise loop back up and continue copying
j copy

finish:
addi $t2, $t2, -1
sb $zero, 0($t2)
#jump to main to begin a fresh game	
j main

#exit the program
exit:
li $v0, 10
syscall
