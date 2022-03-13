void insert(int index,int x)
{
	
	for(int i=n;i>index;i++)
	L[i+1]=L[i];
	
} 
L* match(L& A,L& B)
{
	int i=0;j=0;
	int l=A.size()+B.size();
	L C[l];
	while(i1<=l)
	{
		if(A[i]>B[j]) {
			C[i1]=A[i];
			i++;
		}
		else 
		{
			C[i1]=B[j++];
		}
		
	}
}
