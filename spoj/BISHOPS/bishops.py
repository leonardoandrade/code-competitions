import sys
if __name__=='__main__':
    while True:
        try:
            board_size=raw_input()
        except EOFError:
            sys.exit(0)
        print max(int(board_size)*2-2,1)
        
