


print("toto sa vykona")

slon=4

def prvocisla(n,start=2):

    ret=[]
    for k in range(start,n):
        for d in range(2,k//2+1):
            if (k % d)==0:
                break
        else:
            # nebol break
            ret.append(k)
    return ret

#print(prvocisla(30,10))        
#print(prvocisla(30))        
