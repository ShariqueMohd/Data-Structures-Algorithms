#include<bits/stdc++.h>
using namespace std;
int getsum(int BitTr[],int ind)
{
	int sum=0;
	ind=ind+1;
	while(ind>0)
	{
		sum+=BitTr[ind];
		ind-=(ind & (-ind));
	}
	return sum;
}
void update(int BitTr[],int n,int ind,int v)
{
	ind=ind+1;
	while(ind<=n)
	{
		BitTr[ind]+=v;
		ind+=(ind & (-ind));
	}
}
int *construct(int arr1[],int n)
{
	int i;
	int *BitTr= new int[n+1];
	for(i=0;i<n+1;i++)
		BitTr[i]=0;
	for(i=0;i<n;i++)
		update(BitTr,n,i,arr1[i]);
	return BitTr;
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];	
	}
	int *BitTr=construct(arr,n);
	cout <<"sum of elem for arr[0..5]="<< getsum(BitTr,5)<< endl;
	//for(int i=0;i<n;i++)
	//{
	//	cout << arr[i]<< " "<< BitTr[i]<<endl;
	//}
	cout <<"update add 6  to arr[3]"<<endl;
	arr[3]+=6;
	update(BitTr,n,3,6);
	cout <<"sum of elem for arr[0..5]="<< getsum(BitTr,5)<< endl;

	return 0;
}