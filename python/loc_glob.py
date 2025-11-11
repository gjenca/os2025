



def f(z):

    global y

    x=10
    print(x)
    print(z)
    print(y)
    y=-20

y=20

f(30)
print('global y',y)

