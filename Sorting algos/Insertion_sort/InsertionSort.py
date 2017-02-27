def InsertionSort(a):
    for i in range(len(a)):
        value = a[i]
        hole = i
        while value<a[hole-1] and hole>0:
            a[hole] = a[hole-1]
            hole = hole-1
        a[hole] = value
    return a

def main():
    a = [32,45,1,6,3,23,-2]
    a = InsertionSort(a)
    print(a)

if __name__=='__main__':
    main()