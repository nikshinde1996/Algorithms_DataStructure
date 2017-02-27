def SelectionSort(a):
    for i in range(len(a)):
        pom = i
        for j in range(i,len(a)):
            if a[j] < a[pom]:
                pom = j
        temp = a[pom]
        a[pom] = a[i]
        a[i] = temp
    return a

def main():
    a = [32,45,1,6.3,3.5,23]
    b = SelectionSort(a)
    print(b)

if __name__ == '__main__':
    main()