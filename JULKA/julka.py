while True:
    try:
        total, difference  = int(raw_input()), int(raw_input())
        print str((total/2 + difference/2) + total%2)+'\n'+str(total/2 - difference/2)
    except EOFError:
        break
