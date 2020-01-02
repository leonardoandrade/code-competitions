

if __name__=='__main__':
    nlines=raw_input()
    for i in range(int(nlines)):
        tok=raw_input().split(" ")
        print int(str(int(tok[0][::-1])+int(tok[1][::-1]))[::-1])
