# -*- coding: utf-8 -*-

from termcolor import colored
import funfunctions

import time
import traceback
import sys
import random

import executables
import events
from MainMenuException import MainMenuException

DEFAULT_PROMPT = colored("AILEE@{COMP}: {CWD}$ ", 'green')

CMD_NOT_FOUND_STRS = [
    "command not found",
    "Nope, don't know that one",
    "This isn't Google",
    "NOOB!"
    "Segmentation fault (core dumped)",

]


class Shell(object):
    """
    Like a seashell.
    """

    def __init__(self, computer, user, agent=None, cwd=None, game=None):
        """
        Create a shell.
        """

        self.computer = computer
        self.user = user
        self.agent = agent
        self.cwd = cwd or computer.fs
        self.prompt = DEFAULT_PROMPT
        self.running = False
        self._command_dictionary = {}
        self.variables = {}
        self.game = game
        self.history = []

        self._setup()

    def _setup(self):
        funfunctions.clear()
        s = "Loading new shell"

        print(s, end='\r')
        i = 0

        # load command dictionary
        for module in executables.__all__:
            self._command_dictionary.update({module: getattr(executables, module).run})
            print(s + '.'*i, end='\r')
            i += 1
            time.sleep(0.1)
        time.sleep(0.3)
        funfunctions.clear()
        # print(constants.title)

    def _get_command_from_str(self, command_str):
        """
        Takes a command name, returns the executable object.
        """

        if command_str == '':
            return False
        if command_str not in self.game.allowed_commands:
            return None
        cmd = self._command_dictionary[command_str]
        return cmd

    def run_command(self, command, args, **kwargs):
        """
        Runs a command.

        Input must be a runnable command that accepts **kwargs.
        """

        command(
            *args,
            computer=self.computer,
            cwd=self.cwd,
            user=self.user,
            agent=self.agent,
            shell=self,
            game=self.game,
            **kwargs
        )

    def take_input(self):
        user_input = input(self.prompt.format(
            COMP=str(self.computer.name),
            CWD=str(self.cwd),
            USER=self.user),
        )

        parts = [p.strip() for p in user_input.split(' ')]
        command = parts[0]
        args = parts[1:]

        return command, args

    def one_command(self):
        command, args = self.take_input()
        cmd = self._get_command_from_str(command)
        if cmd is None:
            self.cmd_not_found()
            return
        elif cmd is False:
            return  # nothing on empty commands
        cname = cmd.__module__.split('.')[-1]
        if not cname == 'doStory':
            self.game.history.append([cname, args])
            self.history.append([cname, args])

        if not (command or args):
            return  # skip empty input
        self.run_command(cmd, args)

    def halt(self):
        self.running = False

    def cmd_not_found(self):
        self.history.append([None, []])
        self.game.history.append([None, []])
        print("Command not found")
        # print(random.choice(CMD_NOT_FOUND_STRS))

    def start_shell_loop(self):
        self.running = True
        while self.running:
            try:
                self.run_command(events.doStory.run, [])
                self.one_command()
            except KeyboardInterrupt:
                print()
            #except KeyError as e:
            #    self.cmd_not_found()
            except AssertionError as e:
                print(str(e))
            except MainMenuException:
                raise MainMenuException
            except Exception as e:
                #print(colored(
                #    "Something went wrong.  I'm not quite sure what.  "
                #    "Maybe try again?", 'red'))
                # Uncomment VV for full tracebacks
                einfo = sys.exc_info()
                traceback.print_exception(*einfo)
