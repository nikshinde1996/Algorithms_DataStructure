def Merge(a,b):
    c = []
    while len(a)!=0 and len(b)!=0:
        if a[0] < b[0]:
            c.append(a[0])
            a.remove(a[0])
        else:
            c.append(b[0])
            b.remove(b[0])
    if len(a)==0:
        c += b
    else:
        c += a
    return c

def MergeSort(a):
    if len(a)<=1:
        return a
    else:
        middle = len(a)//2
        b = MergeSort(list(a[:middle]))
        c = MergeSort(list(a[middle:]))
    return Merge(b,c)

def main():
    a = [32,45,1,6,3,23,-2]
    a = MergeSort(a)
    print(a)

if __name__=='__main__':
    main()