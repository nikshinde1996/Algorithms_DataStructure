def BubbleSort(a):
    for i in range(len(a)):
        for j in range(0,len(a)-1):
            if a[j]>a[j+1]:
                temp = a[j];
                a[j] = a[j+1]
                a[j+1] = temp
    return a


def main():
    a = [32,45,1,6,3,23]
    a = BubbleSort(a)
    print(a)

if __name__=='__main__':
    main()