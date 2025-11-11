
def f(x,y,z=10,w=20):

    print("x=",x,"y=",y,"z=",z,"w=",w)

f(1,2)
f(1,2,-10)
f(1,2,z=-10) # Morálne správne takto
f(1,2,w=-20)
f(x=2,y=1)

def g(x,y,*args):

    print("x=",x,"y=",y,"args=",args)

g(1,2)
g(1,2,-3,-4)


def sucin(*nums):

    ret=1
    for arg in nums:
        ret=ret*arg
    return ret

print(sucin(3,7,2))
print(sucin(*[3,7,2]))
print(sucin(1,2,3,4))
print(*range(1,5))
print(sucin(*range(1,5)))

def generic(*args,**kwargs):
    print("args=",args,"kwargs=",kwargs)


generic(1,17,slon=4,had=0,slimak=1)
