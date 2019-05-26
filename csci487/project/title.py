from time import sleep
from replit import clear
import curses

# Don't fix to look correct in code, as it looks different in terminal
authors = '''
     David Wilson, Grant Haataja, and Misha Turnbull present:
'''

title = '''
         /^\\        ====++====  ||          ++========  ++========
        // \\\\           ||      ||          ||          ||        
       //   \\\\          ||      ||          ||          ||        
      //_____\\\\         ||      ||          ++========  ++========
     //=======\\\\        ||      ||          ||          ||        
    //         \\\\   ____||____  ||________  ||________  ||________
   //           \\\\  ====++====  ++========  ++========  ++========
'''

skip = '''
   [ ] Skip Dialog
'''

menu = '''
   [ ] New Game
   [ ] Exit
'''

def run():
  clear()
  # Start curses and activate color
  stdscr = curses.initscr()
  curses.start_color()
  curses.noecho()
  curses.curs_set(0)
  curses.init_pair(1, curses.COLOR_GREEN, curses.COLOR_BLACK)
  curses.init_pair(2, curses.COLOR_RED, curses.COLOR_BLACK)
  stdscr.bkgd(' ', curses.color_pair(1))
  stdscr.keypad(True)
  # Set authors, refresh screen, and wait
  stdscr.addstr(0, 0, authors, curses.A_BOLD)
  stdscr.move(0, 0) # Reset cursor position
  stdscr.refresh()
  sleep(3)
  # Set title, refresh screen, and wait
  stdscr.addstr(3, 0, title, curses.A_BOLD)
  stdscr.move(0, 0) # Reset cursor position
  stdscr.refresh()
  sleep(1)
  # Set menu options
  stdscr.addstr(14, 0, menu, curses.A_BOLD)
  menuSelection = 1
  counter = 0
  printOptions(stdscr, menuSelection)
  while True:
    char = stdscr.getch()
    # Do action of selection (0:skip_dialog/True, 1:start_game/False, 2:exit)
    if char == curses.KEY_ENTER or char == ord('\n'):
      stdscr.erase() # Erase Menu
      curses.endwin() # Reset terminal back to normal
      if menuSelection == 2:
        return None
      else:
        return menuSelection == 0
    # Move selection up
    elif char == curses.KEY_UP or char == ord('w'):
      if menuSelection == 2:
        menuSelection = 1
      elif menuSelection == 1:
        if counter < 5: # Counter for secret 
          counter += 1
        else:
          menuSelection = 0
    elif char == curses.KEY_DOWN or char == ord('s'):
      if menuSelection != 2:
        menuSelection += 1
    printOptions(stdscr, menuSelection)

def printOptions(stdscr, menuSelection):
  # reset options
  stdscr.addstr(14, 0, '                  ')
  stdscr.addch(15, 4, ' ', curses.A_BOLD)
  stdscr.addch(16, 4, ' ', curses.A_BOLD)
  # Print X
  if menuSelection == 0:
    stdscr.addstr(13, 0, skip, curses.A_BOLD)
    stdscr.addch(14, 4, 'X', curses.color_pair(2) | curses.A_BOLD)
  if menuSelection == 1:
    stdscr.addch(15, 4, 'X', curses.color_pair(2) | curses.A_BOLD)
  elif menuSelection == 2:
    stdscr.addch(16, 4, 'X', curses.color_pair(2) | curses.A_BOLD)
  stdscr.move(0, 0) # Reset cursor position
  stdscr.refresh()