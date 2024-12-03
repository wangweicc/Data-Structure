void mergeList1(SeqList LA,SeqList LB,SeqList &LC)
{
	int i,j,k;
	i = 0;
	j = 0;
	k = 0;
	while(i<=LA.length-1 && j<=LB.length-1)
	{
		if(LA.data[i]<=LB.data[j])
		{
			LC.data[k]=LA.data[i];
			k++;
			i++;
		}
		else
		{
			LC.data[k]=LB.data[j];
			j++;
			k++;
		}
	}
	while(i<=LA.length-1)
	{
		LC.data[k]=LA.data[i];
		i++;
		k++;
	}
	while(j<=LB.length-1)
	{
		LC.data[k]=LB.data[j];
		j++;
		k++;
	}
	LC.length=LA.length+LB.length;
}