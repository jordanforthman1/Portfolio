# Tic-Tac-Toe Game

import random
import time

board = ["-", "-", "-", "-", "-", "-", "-", "-", "-"]

currentPlayer = "X"
gameRunning = True
Winner = None


def display_board(board):
    print(board[0], " | ", board[1], " | ", board[2])
    print("--------------")
    print(board[3], " | ", board[4], " | ", board[5])
    print("--------------")
    print(board[6], " | ", board[7], " | ", board[8])


def user_input(board):
    inp = int(input("Enter a move 1-9: "))
    if board[inp-1] == "-":
        board[inp-1] = currentPlayer
    else:
        print("Oops try again.")


def checkColumn(board):
    global Winner
    if board[0] == board[3] == board[6] and board[0] != "-":
        Winner = board[0]
        return True
    elif board[1] == board[4] == board[7] and board[1] != "-":
        Winner = board[1]
        return True
    elif board[2] == board[5] == board[8] and board[2] != "-":
        Winner = board[2]
        return True


def checkRow(board):
    global Winner
    if board[0] == board[1] == board[2] and board[0] != "-":
        Winner = board[0]
        return True
    elif board[3] == board[4] == board[5] and board[3] != "-":
        Winner = board[3]
        return True
    elif board[6] == board[7] == board[8] and board[6] != "-":
        Winner = board[6]
        return True


def checkDiagonal(board):
    global Winner
    if board[0] == board[4] == board[8] and board[0] != "-":
        Winner = board[0]
        return True
    elif board[2] == board[4] == board[6] and board[4] != "-":
        Winner = board[2]
        return True


def checkWin(board):

    global gameRunning

    if checkColumn(board):
        display_board(board)
        print(f"The winner is {Winner}!")
        gameRunning = False
    elif checkDiagonal(board):
        display_board(board)
        print(f"The winner is {Winner}!")
        gameRunning = False
    elif checkRow(board):
        display_board(board)
        print(f"The winner is {Winner}!")
        gameRunning = False


def checkTie(board):

    global gameRunning

    if "-" not in board:
        display_board(board)
        print("It is a tie!")
        gameRunning = False


def switchPlayer():

    global currentPlayer

    if currentPlayer == "X":
        currentPlayer = "O"
    else:
        currentPlayer = "X"


def comp_move(board):

    while currentPlayer == "O":
        position = random.randint(0, 8)
        if board[position] == "-":
            board[position] = "O"
            switchPlayer()

def trashTalk():

    print('')

    trash_talk = ["You're screwed now!", "Brush your teeth!.", "I never lose.", "Your face makes onions cry.",
   "You look like something I would draw with my left hand.", "I'd give you a nasty look but you already got one.",
   "May both sides of your pillow be uncomfortably warm.", "You have your whole life to be an idiot. Take today off.",
   "You are the reason they put instructions on shampoo.","You're the reason gene pools need life guards.",
   "If you we're drowning I'd give you a high five."]

    print(trash_talk[random.randint(0,10)])

    print('')

while gameRunning:
    display_board(board)
    user_input(board)
    display_board(board)
    checkWin(board)
    checkTie(board)
    switchPlayer()
    trashTalk()
    time.sleep(2)
    comp_move(board)
    checkWin(board)
    checkTie(board)

input("Hit 'Enter' to exit.")
