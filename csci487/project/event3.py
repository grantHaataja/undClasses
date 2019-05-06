#Third dialogue of the game
#triggers after port scanning has been done
import time
from funfunctions import typewriter
from termcolor import colored

def check_run(*args, **kwargs):
  # check for 'pscan' in history, most recently run, and exactly once
  if len(kwargs['game'].history) == 0:
    return False
  if not 'event2' in kwargs['game'].events_run:
    return False

  command = ['pscan', ['120.45.30.6']]

  a = kwargs['game'].history[-1] == command
  return a

def run(*args, **kwargs):
  # using kwargs we can get access to the shell, and from within the event
  # have the user run commands

  color = 'cyan'
  game = kwargs['game']

  text = [
    '\nGood job, Ailee. I see you have successfully found which open ports are running\non our target.\n\n',
    'Our next step is to run our vulnerability scanning software against the target\nto see if we can use any exploits against them.\n\n'
  ]
  filename = 'message03.txt'
  if filename not in game.eventLogDir:
    game.eventLogDir.addFile(filename, colored(''.join(text), color))

  if not game.skip_dialog:
    typewriter(colored(text[0],color))
    typewriter(colored(text[1],color))
  else:
    print(colored('Event3 text skipped', 'red'))

  # Create chat log in AILEE's directory
  