# This program accepts chess board placements and determines if they constitute a valid chess board

import operator

def checkBpawn(board):
    count = operator.countOf(board.values(), 'bpawn')
    if count > 8 or count < 0:
        return False
    else: 
        return True

def checkWpawn(board):
    count = operator.countOf(board.values(), 'wpawn')
    if count > 8 or count < 0:
        return False
    else: 
        return True

def checkBrook(board):
    count = operator.countOf(board.values(), 'brook')
    if count > 2 or count < 0:
        return False
    else: 
        return True

def checkWrook(board):
    count = operator.countOf(board.values(), 'wrook')
    if count > 2 or count < 0:
        return False
    else: 
        return True

def checkWrook(board):
    count = operator.countOf(board.values(), 'wrook')
    if count > 2 or count < 0:
        return False
    else: 
        return True

def checkBknight(board):
    count = operator.countOf(board.values(), 'bknight')
    if count > 2 or count < 0:
        return False
    else: 
        return True

def checkWknight(board):
    count = operator.countOf(board.values(), 'wknight')
    if count > 2 or count < 0:
        return False
    else: 
        return True

def checkBbishop(board):
    count = operator.countOf(board.values(), 'bbishop')
    if count > 2 or count < 0:
        return False
    else: 
        return True

def checkWbishop(board):
    count = operator.countOf(board.values(), 'wbishop')
    if count > 2 or count < 0:
        return False
    else: 
        return True

def checkBqueen(board):
    count = operator.countOf(board.values(), 'bqueen')
    if count > 1 or count < 0:
        return False
    else: 
        return True

def checkWqueen(board):
    count = operator.countOf(board.values(), 'wqueen')
    if count > 1 or count < 0:
        return False
    else: 
        return True

def checkBking(board):
    count = operator.countOf(board.values(), 'bking')
    if count > 1 or count < 0:
        return False
    else: 
        return True

def checkWking(board):
    count = operator.countOf(board.values(), 'wking')
    if count > 1 or count < 0:
        return False
    else: 
        return True

def checkIfValid(board):

    is_valid = True

    is_valid = is_valid and checkBbishop(board)
    is_valid = is_valid and checkBknight(board)
    is_valid = is_valid and checkBpawn(board)
    is_valid = is_valid and checkBqueen(board)
    is_valid = is_valid and checkBrook(board)
    is_valid = is_valid and checkWbishop(board)
    is_valid = is_valid and checkWking(board)
    is_valid = is_valid and checkWpawn(board)
    is_valid = is_valid and checkWqueen(board)
    is_valid = is_valid and checkWrook(board)
    is_valid = is_valid and checkWknight(board)
    is_valid = is_valid and checkBking(board)


    if not is_valid:
        print('Board is invalid.')
    else: print('Board is valid')

board = {
    '1a':None,'2a':None,'3a':None,'4a':None,'5a':None,'6a':None,'7a':None,'8a':None,'9a':None,
    '1b':None,'2b':None,'3b':None,'4b':None,'5b':None,'6b':None,'7b':None,'8b':None,'9b':None,
    '1c':None,'2c':None,'3c':None,'4c':None,'5c':None,'6c':None,'7c':None,'8c':None,'9c':None,
    '1d':None,'2d':None,'3d':None,'4d':None,'5d':None,'6d':None,'7d':None,'8d':None,'9d':None,
    '1e':None,'2e':None,'3e':None,'4e':None,'5e':None,'6e':None,'7e':None,'8e':None,'9e':None,
    '1f':None,'2f':None,'3f':None,'4f':None,'5f':None,'6f':None,'7f':None,'8f':None,'9f':None,
    '1g':None,'2g':None,'3g':None,'4g':None,'5g':None,'6g':None,'7g':None,'8g':None,'9g':None,
    '1h':None,'2h':None,'3h':None,'4h':None,'5h':None,'6h':None,'7h':None,'8h':None,'9h':None}

user_board = {'1a' : 'bking', '2a' : 'brook', '4h': 'wqueen', '7d' : 'wknight', '6c' : 'wking'}

for key, value in user_board.items():
    board[key] = value

checkIfValid(board)
