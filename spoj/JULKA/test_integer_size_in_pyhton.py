# divide string by two
def divide_by_two(big_number):
    return str(int(big_number)/2)

#unit test stuff
if __name__ == "__main__":
    assert divide_by_two("100000") == "50000"
    assert divide_by_two("1"+"".join(['0'*100])) == "5"+"".join(['0'*99])
    assert divide_by_two("1"+"".join(['0'*1000])) == "5"+"".join(['0'*999])
    assert divide_by_two("1"+"".join(['0'*10000])) == "5"+"".join(['0'*9999])
    assert divide_by_two("1"+"".join(['0'*100000])) == "5"+"".join(['0'*99999])
    assert divide_by_two("1"+"".join(['0'*1000000])) == "5"+"".join(['0'*999999])

    #this one takes more than one minute in my laptop:
    assert divide_by_two("1"+"".join(['0'*10000000])) == "5"+"".join(['0'*9999999])
