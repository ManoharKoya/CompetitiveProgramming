def merge(l1,l2):
    p1,p2 = (0,0)
    res = []
    while(p1<len(l1) and p2<len(l2)):
        if(l1[p1]<l2[p2]):
            res.append(l1[p1])
            p1+=1
        else :
            res.append(l2[p2])
            p2+=1
    if(p2<len(l2)):
        while(p2<len(l2)):
            res.append(l2[p2])
            p2+=1
    if(p1<len(l1)):
        while(p1<len(l1)):
            res.append(l1[p1])
            p1+=1
    return res
        
if __name__=="__main__":
	l1 = [1,2,3,100,250]
	l2 = [3,110,200,249]
	print(merge(l1,l2))
