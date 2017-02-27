def CountingSort(a):
	maxel = max(a)
	c = [0]*(maxel+1)
	alist = []
	for i in range(0,len(a)):
		c[a[i]] += 1
	index = 0
	print(c)
	for i in range(0,len(c)):
		while c[i]>0:
			alist.append(i)
			c[i] -= 1
	return alist
	
if __name__ == '__main__':
	a = [23,0,4,45,3,2,19]
	a = CountingSort(a)
	print(a)
