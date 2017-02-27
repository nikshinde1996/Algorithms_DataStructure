def partition(a,start,end):
	pivot = a[start]
	left = start+1
	right = end
	done = False
	
	while not done:
		while left<=right and a[left] <= pivot:
			left = left + 1
		while left <= right and a[right] >= pivot:
			right = right-1
		
		if right<left:
			done = True
		else:
			temp = a[left]
			a[left] = a[right]
			a[right] = temp
	
	temp = a[start]
	a[start] = a[right]
	a[right] = temp
	return right 

def QuickSort(a,start,end):
	if(start<end):
		pivot = partition(a,start,end)
		QuickSort(a,start,pivot-1)
		QuickSort(a,pivot+1,end)
		return a

def main():
    a = [32,45,1,6,3,23,-2]
    a = QuickSort(a,0,len(a)-1)
    print(a)

if __name__=='__main__':
    main()
