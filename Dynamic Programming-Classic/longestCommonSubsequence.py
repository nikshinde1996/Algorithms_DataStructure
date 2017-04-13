def lcs(X,Y,M,N):
	if(M==0 or N==0):
		return 0
	elif(X[M-1] == Y[N-1]):
		return 1 + lcs(X,Y,M-1,N-1)
	else:
		return max(lcs(X,Y,M-1,N),lcs(X,Y,M,N-1))

if __name__ == '__main__':
	x = "Nikhil"
	y = "Nihilism"
	print(lcs(X,Y,len(X),len(Y)))

