#CSCI370 - Programming Exercise II
#Grant Haataja
.data
startMessage: .asciiz "\n\nStart playing a dastardly game of Tic-Tac-Toe."
pieceMessage: .asciiz "\nYou start the game. Pick a piece (X|O): "
pieceError: .asciiz "\nInvalid piece!  "
continueMessage: .asciiz "\nContinue? (y/n) "
continueError: .asciiz "\nInvalid character!   "
newGameMessage: .asciiz "\nNew game? (y/n) "
nextMove: .asciiz "\nEnter your next move (1-9): "
moveError: .asciiz "\nInvalid move!  "
spaceErrorMessage: .asciiz "\nInvalid key!"
systemO: .asciiz "\nThe Computer starts the game and chooses O."
systemX: .asciiz "\nThe Computer starts the game and chooses X."
spacebar: .asciiz "\nPress the spacebar to start the Computer's next move."
computerMove: .asciiz "\nThe computer's move is "
computerWin: .asciiz "\nThe computer "
userWin: .asciiz "\nThe user "
finishWin: .asciiz " wins!\n"
drawMessage: .asciiz "\nThe game ends in a draw."
X: .asciiz "X"
O: .asciiz "O"
board:
.ascii   "\n\n        | |        1|2|3\n       -----       -----"
.ascii     "\n        | |        4|5|6\n       -----       -----"
.asciiz    "\n        | |        7|8|9\n"
ogboard:
.ascii   "\n\n        | |        1|2|3\n       -----       -----"
.ascii     "\n        | |        4|5|6\n       -----       -----"
.asciiz    "\n        | |        7|8|9\n"

#throw some lines in for testing
segFault: .asciiz "\nSegmentation fault (core dumped)\n"
returnn: .asciiz "\nAbout to return from subroutine."
register: .asciiz "\nThe contents of this register are:"



###########    program begins executing here: this is where the game starts    ##########
.text
main:
	li $v0, 4
	la $a0, startMessage		#print welcome message
	syscall
	xor $a0, $a0, $a0		#set seed for random number generation
	li $a1, 2			#specify random number between 0 and 1 inclusive
	li $v0, 42			#system call for random number generation
	syscall
	beq $a0, 0, randPick		#system starts the game
	beq $a0, 1, userPick		#user starts the game
	

###   routine for when the user starts the game   ###
userPick:
	li $t0, 'X'			#save X and O to temp registers
	li $t1, 'O'
	li $t2, 'x'
	li $t3, 'o'
	li $v0, 4
	la $a0, pieceMessage		#tell the user to pick a piece to start
	syscall
	li $v0, 12			#get the user's choice from input
	syscall
	beq $v0, $t0, userPickX		#if the user chooses 'X'
	beq $v0, $t1, userPickO		#if the user chooses 'O'
	beq $v0, $t2, userPickX		#if the user chooses 'x'
	beq $v0, $t3, userPickO		#if the user chooses 'o'
	li $v0, 4
	la $a0, pieceError		#if user's choice is wrong print the appropriate error
	syscall
	j userPick			#loop again

userPickO:
	li $s1, 'O'			# $s1 is the user's piece
	li $s0, 'X'			# $s0 is the system's piece
	j userPreGame			# jump ahead to do pregame things before entering gameLoop
	
userPickX:
	li $s1, 'X'			# $s1 is the user's piece
	li $s0, 'O'			# $s0 is the system's piece


###   routine for the pregame tasks when the user starts the game   ###
userPreGame:
	jal printBoard			#display empty board
	j gameLoop			#jump to the main game loop
	
		
###   routine for when the system starts the game   ###
randPick:
	xor $a0, $a0, $a0		#set seed for random number generation
	li $a1, 2			#specify random number between 0 and 1 inclusive
	li $v0, 42			#system call for random number generation
	syscall	
	beq $a0, 0, chooseO		#system chooses 'O'
	beq $a0, 1, chooseX		#system chooses 'X'

		
###   subroutine for the user to press space for the system to make their move   ###
pressSpacebar:
	subu $sp, $sp, 4		#decrement $sp to make room for the return address
	sw $ra, ($sp)			#push the return address

spacebarLoop:
	li $v0, 4
	la $a0, spacebar		#tell the user to press spacebar
	syscall
	li $v0, 12			#read character input
	syscall
	beq $v0, ' ', spaceReturn	#if the user presses spacebar return from subroutine
	li $v0, 4
	la $a0, spaceErrorMessage	#print the error message
	syscall
	j spacebarLoop			#continue loop until user presses spacebar

spaceReturn:
	lw $ra, ($sp)			#pop the return address
	addu $sp, $sp, 4		#increment $sp
	jr $ra				#return to subroutine call


###   subroutine to generate random move for system   ###
randomMove:
	subu $sp, $sp, 4		#decrement $sp to make room for $ra
	sw $ra, ($sp)			#push the return address
	subu $sp, $sp, 4		#decrement $sp to make room for $s2
	sw $s2, ($sp)			#push $s2
	subu $sp, $sp, 4		#decrement $sp to make room for $s3
	sw $s3, ($sp)			#push $s3
	
randomLoop: 
	xor $a0, $a0, $a0		#set a seed number
	li $a1, 9			#specify random number between 0 and 8 inclusive
	li $v0, 42			#system call for random number generation
	syscall
	add $s3, $a0, '1'		#convert integer move to char
	add $a2, $a0, '1'		#convert integer move to char
	jal offset
	lb $t0, board($v1)		#load byte at the calculated offset for comparison
	beq $t0, 'X', randomLoop	#go back to start if cell is taken
	beq $t0, 'O', randomLoop	#go back to start if cell is taken
	
	move $v0, $s3			#store the char move to $v0
	lw $s3, ($sp)			#pop $s3
	addu $sp, $sp, 4		#increment $sp
	lw $s2, ($sp)			#pop $s2
	addu $sp, $sp, 4		#increment $sp
	lw $ra, ($sp)			#pop the return address
	addu $sp, $sp, 4		#increment $sp
	jr $ra				#return to where subroutine was called


###   subroutine to find offset and modify board string   ###
offset:
	subu $sp, $sp, 4		#decrement $sp to make room for return address
	sw $ra, ($sp)			#push the return address
	subu $sp, $sp, 4		#decrement $sp to make room for $s3
	sw $s4, ($sp)			#push $s4
	
	subi $s4, $a2, 48		#correct for using char data types
	subi $t0, $s4, 1		
	div $t1, $t0, 3
	mul $t2, $t1, 44
	addi $t3, $t2, 7
	mul $t4, $s4, 2
	add $v1, $t3, $t4		#calculate offset to determine where to save move and store in $v1
	
	lw $s4, ($sp)			#pop $s4
	addu $sp, $sp, 4		#increment $sp
	lw $ra, ($sp)			#pop $ra from the runtime stack
	addu $sp, $sp, 4		#increment $sp
	jr $ra				#return


###   subroutine for user to make their move   ###
userMove:
	subu $sp, $sp, 4		#decrement $sp to make room for the return address
	sw $ra, ($sp)			#push the return address
	
userMoveLoop:
	li $t0, '1'			#save moves 1-9 in temporary registers for comparison
	li $t1, '2'
	li $t2, '3'
	li $t3, '4'
	li $t4, '5'
	li $t5, '6'
	li $t6, '7'
	li $t7, '8'
	li $t8, '9'
	li $v0, 4
	la $a0, nextMove		#prompt the user to choose a move
	syscall
	li $v0, 12			#get user's move
	syscall
	move $s6, $v0			#save user's move for later
	beq $v0, $t0, userMoveWork	#check if user entered a valid move
	beq $v0, $t1, userMoveWork
	beq $v0, $t2, userMoveWork
	beq $v0, $t3, userMoveWork
	beq $v0, $t4, userMoveWork
	beq $v0, $t5, userMoveWork
	beq $v0, $t6, userMoveWork
	beq $v0, $t7, userMoveWork
	beq $v0, $t8, userMoveWork
	li $v0, 4
	la $a0, moveError		#if user's choice is wrong, print error and loop again
	syscall
	j userMoveLoop

userMoveWork:
	move $a2, $s6			#set $a2 to the user's move in char
	jal offset			#calculate offset to store user's move
	lb $t0, board($v1)		#load the byte for the move that the user selected
	beq $t0, 'X' userGoBack		#if space is taken, we need to print an error and prompt the user for a new move
	beq $t0, 'O' userGoBack		#if space is taken, we need to print an error and prompt the user for a new move
	
	sb $s1, board($v1)		#otherwise store the user's piece at the selected location
	lw $ra, ($sp)			#pop the return address
	addu $sp, $sp, 4		#increment the $sp
	jr $ra				#return
	
userGoBack:
	li $v0, 4
	la $a0, moveError		#print the error saying the space has been taken
	syscall
	j userMoveLoop			#jump back to the beginning of the loop to promt the user for a new move
	

###   subroutine to print board   ###
printBoard:
	li $v0, 4
	la $a0, board			#print the string to display the board, including any saved moves
	syscall
	jr $ra				#return
	

###   subroutine to print the system's move   ###
printMove:
	subu $sp, $sp, 4		#decrement $sp to make room for the return address
	sw $ra, ($sp)			#push the return address
	
	sub $t0, $v0, 48		#convert the char move to integer
	li $v0, 4
	la $a0, computerMove		#print the text
	syscall
	li $v0, 1
	la $a0, ($t0)			#print the integer
	syscall
	
	lw $ra, ($sp)			#pop the return address
	addu $sp, $sp, 4		#increment $sp
	jr $ra				#return to subroutine call
	

###   subroutine to check for draw condition   ###
checkForDraw:
	subu $sp, $sp, 4		#decrement $sp to make room for the return address
	sw $ra, ($sp)			#push the return address
	
	li $t0, 9
	lb $t1, board($t0)		#load the byte for position 1 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 11
	lb $t1, board($t0)		#load the byte for position 2 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 13
	lb $t1, board($t0)		#load the byte for position 3 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 59
	lb $t1, board($t0)		#load the byte for position 4 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 61
	lb $t1, board($t0)		#load the byte for position 5 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 63
	lb $t1, board($t0)		#load the byte for position 6 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 109
	lb $t1, board($t0)		#load the byte for position 7 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 111
	lb $t1, board($t0)		#load the byte for position 8 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $t0, 113
	lb $t1, board($t0)		#load the byte for position 9 of the board
	beq $t1, ' ', drawReturn	#if there is a space, return to main game loop	
	li $v0, 4
	la $a0, drawMessage		#if there are no spaces, announce a draw
	syscall
	j newGame			#jump to new game routine

drawReturn:	
	lw $ra, ($sp)			#pop the return address
	addu $sp, $sp, 4		#increment $sp
	jr $ra				#return to subroutine call	
	
	
###   subroutine to check win condition   ###
checkForWin:
	subu $sp, $sp, 4		#decrement $sp to make room for the return address
	sw $ra, ($sp)			#push the return address	

	li $t0, 9
	lb $t1, board($t0)		#load the byte for position 1 of the board
	beq $s7, $t1, b123		#branch to b123 if the byte is the same as the specific piece being checked	
	
b258:
	li $t0, 11
	lb $t1, board($t0)		#load the byte for position 2 of the board
	bne $s7, $t1, b369		#branch to b369 if the byte is not the same as the specific piece being checked	
	li $t0, 61
	lb $t1, board($t0)		#load position 5
	bne $s7, $t1, b369		#branch to b369 if the byte is not the same as the piece
	li $t0, 111
	lb $t1, board($t0)		#load position 8
	bne $s7, $t1, b369		#branch to b369 if the byte is not the same as the piece
	j win				#jump to win routine	

b369:	
	li $t0, 13
	lb $t1, board($t0)		#load the byte for position 3 of the board
	bne $s7, $t1, b357		#branch to b357 if the byte is not the same as the specific piece being checked	
	li $t0, 63
	lb $t1, board($t0)		#load position 6
	bne $s7, $t1, b357		#branch to b357 if the byte is not the same as the piece
	li $t0, 113
	lb $t1, board($t0)		#load position 9
	bne $s7, $t1, b357		#branch to b357 if the byte is not the same as the piece
	j win				#jump to win routine		
	
b357:	
	li $t0, 13
	lb $t1, board($t0)		#load the byte for position 3 of the board
	bne $s7, $t1, b456		#branch to b456 if the byte is not the same as the specific piece being checked	
	li $t0, 61
	lb $t1, board($t0)		#load position 5
	bne $s7, $t1, b456		#branch to b456 if the byte is not the same as the piece
	li $t0, 109
	lb $t1, board($t0)		#load position 7
	bne $s7, $t1, b456		#branch to b456 if the byte is not the same as the piece
	j win				#jump to win routine	
	
b456:	
	li $t0, 59
	lb $t1, board($t0)		#load the byte for position 4 of the board
	bne $s7, $t1, b789		#branch to b789 if the byte is not the same as the specific piece being checked	
	li $t0, 61
	lb $t1, board($t0)		#load position 5
	bne $s7, $t1, b789		#branch to b789 if the byte is not the same as the piece
	li $t0, 63
	lb $t1, board($t0)		#load position 7
	bne $s7, $t1, b789		#branch to b789 if the byte is not the same as the piece
	j win				#jump to win routine	
		
b789:	
	li $t0, 109
	lb $t1, board($t0)		#load the byte for position 7 of the board
	bne $s7, $t1, winReturn		#return if the byte is not the same as the specific piece being checked	
	li $t0, 111
	lb $t1, board($t0)		#load position 8
	bne $s7, $t1, winReturn		#return if the byte is not the same as the piece
	li $t0, 113
	lb $t1, board($t0)		#load position 9
	bne $s7, $t1, winReturn		#return if the byte is not the same as the piece
	j win				#jump to win routine	

b123:
	li $t0, 11			#check for a 123 win
	lb $t1, board($t0)		#load position 2
	bne $s7, $t1, b147		#branch to b147 if the byte does not match
	li $t0, 13			
	lb $t1, board($t0)		#load position 3
	bne $s7, $t1, b147		#branch to b147 if the byte does not match
	j win				#jump to win routine	

b147:
	li $t0, 59			#check for a 147 win
	lb $t1, board($t0)		#load position 4
	bne $s7, $t1, b159		#branch to b159 if byte does not match
	li $t0, 109			
	lb $t1, board($t0)		#load position 7
	bne $s7, $t1, b159		#branch to b159 if byte does not match
	j win				#jump to win routine	
	
b159:
	li $t0, 61			#check for a 159 win
	lb $t1, board($t0)		#load position 5
	bne $s7, $t1, b258		#branch to b258 if byte does not match
	li $t0, 113			
	lb $t1, board($t0)		#load position 5
	bne $s7, $t1, b258		#branch to b258 if byte does not match
	j win				#jump to win routine	
			
winReturn:
	lw $ra, ($sp)			#pop the return address
	addu $sp, $sp, 4		#increment $sp
	jr $ra				#return to subroutine call
		
																																
###   routine for if the system chooses 'O'   ###
chooseO:
	li $v0, 4	
	la $a0, systemO			#system announces choice
	syscall
	li $s0, 'O'			# $s0 is the system's piece
	li $s1, 'X'			# $s1 is the user's piece
	j preGame	

		
###   routine for if the system chooses 'X'   ###
chooseX:
	li $v0, 4
	la $a0, systemX			#system announces choice
	syscall
	li $s0, 'X'			# $s0 is the system's piece
	li $s1, 'O'			# $s1 is the user's piece

		
###   routine for the first random move when the system starts   ###
preGame:
	jal pressSpacebar		#call subroutine to prompt the user to press spacebar
	jal randomMove			#call subroutine to generate a random move for the system
	jal printMove			#call subroutine to print the system's move
	sb $s0, board($v1)		#store the system's piece at the specified offset
	jal printBoard			#call subroutine to print the board
	

###   routine to check if the user wants to continue playing   ###		
continue:
	li $v0, 4
	la $a0, continueMessage		#ask the user if they wish to continue
	syscall
	li $v0, 12			#get user's choice
	syscall
	beq $v0, 'n' newGame		#go to new game routine if user selects no
	beq $v0, 'N' newGame
	beq $v0, 'y' gameLoop		#go to main gameplay loop if user selects yes
	beq $v0, 'Y' gameLoop
	li $v0, 4
	la $a0, continueError		#otherwise print error message and loop again
	syscall
	j continue
			
				
###   routine for main gameplay loop   ###
gameLoop:
	jal userMove			#call subroutine for the user to make their move
	jal printBoard			#call subroutine to print the board	
	move $s7, $s1			#set $s7 to the contents of $s1, the user's piece
	jal checkForWin			#call subroutine to check if user won	
	jal checkForDraw		#call subroutine to check for a draw		
	jal pressSpacebar		#call subroutine to prompt the user to press spacebar					
	jal randomMove			#call subroutine to generate a random move for the system
	jal printMove			#call subroutine to print the system's move
	sb $s0, board($v1)		#store the system's piece at the specified offset
	jal printBoard			#call subroutine to print the board
	move $s7, $s0			#set $s7 to the contents of $s0, the system's piece
	jal checkForWin			#call subroutine to check if user won
	jal checkForDraw		#call subroutine to check for a draw	
	j continue			#ask user if they want to continue game flow									
																		

###   routine for a game win   ###
win:
	beq $s0, $s7, systemWin		#the system wins
	beq $s7, 'X' userX		#the user wins with X
	li $v0, 4
	la $a0, userWin
	syscall
	li $v0, 4
	la $a0, O			#otherwise the user wins with O
	syscall
	li $v0, 4
	la $a0, finishWin
	syscall
	j newGame
	
userX:
	li $v0, 4
	la $a0, userWin
	syscall
	li $v0, 4
	la $a0, X
	syscall
	li $v0, 4
	la $a0, finishWin
	syscall
	j newGame
	
systemWin:
	beq $s7, 'X' systemWinX		#the system wins with X
	li $v0, 4
	la $a0, computerWin
	syscall
	li $v0, 4
	la $a0, O			#otherwise the system wins with O
	syscall
	li $v0, 4
	la $a0, finishWin
	syscall
	j newGame

systemWinX:
	li $v0, 4
	la $a0, computerWin
	syscall
	li $v0, 4
	la $a0, X
	syscall
	li $v0, 4
	la $a0, finishWin
	syscall
	j newGame


###   routine to handle starting a new game or quitting   ###
newGame:
	li $v0, 4
	la $a0, newGameMessage		#ask the user if they wish to start a new game or exit
	syscall
	li $v0, 12			#get user's choice for starting a new game or not
	syscall
	beq $v0, 'n' exit
	beq $v0, 'N' exit
	beq $v0, 'y' cleanUp
	beq $v0, 'Y' cleanUp
	li $v0, 4
	la $a0, continueError		#otherwise print the error message and loop again
	syscall
	j newGame

###   routine to reset the board and jump back to main to start a new game   ###
cleanUp:
	la $a0, board			#load address of written board
	la $a1, ogboard			#load address of unwritten board
	la $a2, 128			#load length of board string
	move $t0, $a0			#store address of written board in temp register
	move $t1, $a1			#store address of unwritten board in temp register
	add $t2, $a0, $a2		#store address of the byte just past the end of board string

copy:
	beq $t0, $t2, finish		#stop if we reach the end of the board string
	lbu $t3, 0($t1)			#otherwise continue copying byte by byte
	sb $t3, 0($t0)
	addi $t0, $t0, 1		#increment counters
	addi $t1, $t1, 1
	beq $t3, $zero, main		#stop if we reach a null terminator
	j copy				#otherwise loop back up and continue copying

finish:
	addi $t2, $t2, -1
	sb $zero, 0($t2)
	j main				#jump to main to begin a fresh game

																								
###   routine to exit the program   ###
exit:
	li $v0, 10
	syscall