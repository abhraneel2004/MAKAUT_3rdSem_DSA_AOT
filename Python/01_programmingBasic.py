
def is_digit(st):
    return st.isdigit()

def is_float(st):
    return st.count('.') == 1 and st[-1]!='.'
    

def is_negative(st):
    return st[0]=='-' and (st[1::].isdigit() or is_float(st[1::]))
        


if __name__ == '__main__':
    s = input("Enter a String:  ")
    if (is_digit(s)):
        print(s, "is a digit")
    if is_float(s):
        print(s, "is a floating point number")
    if is_negative(s):
        print(s, "is a negative number")
    else:
        print(s, "is a string")