#include <iostream>
using namespace std;

int main()
{
	int i,j,c=0,e=0,u=0,r=0,h=0,w=0,s=0,z=0,n,m,k;
	cout<<"Enter n :";  //
	cin>>n;
	cout<<"\n Enter m : "<<endl;
	cin>>m;
	int T[n][m],C[n][m],R[n][m],dept[n],dept2[m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<"T["<<i<<"]["<<j<<"]:";
			cin>>T[i][j];
		}
		cout<<endl;
	}
	if(n==m)               //
	{
		for(i=0;i<n;i++)
		{
			j=i;
			if(T[i][j]==1)     //
			{
				c=c+1;
			}
			if(T[i][j]==0)     //
			{
				e=e+1;
			}

		}
		if(c==n)
		{
			cout<<"T is reflexive"<<endl;
		}
		else
			cout<<"T is not reflexive"<<endl;
		if(e==n)
		{
			cout<<"T is irreflexive"<<endl;
		}
		else
			cout<<"T is not irreflexive"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<m;j++)
			{
				if(T[i][j]!=T[i][j])     //
				{
					u=1;
					i=n;
					j=m;
				}
			}
		}
		if(u==0)
			cout<<"T is symmetrical"<<endl;
		else
			cout<<"T is not symmetrical"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<m;j++)
			{
				if(T[i][j]==1&&T[i][j]==T[j][i])     //
				{
					r=1;
					i=n;
					j=m;
				}
			}
		}
		if(r==0)
			cout<<"T is antsymmetrical"<<endl;
		else
			cout<<"T is not antsymmetrical"<<endl;
		for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                C[i][j]==0;
            }
        }
		for(i=0;i<n;i++) //
		{
			for(j=0;j<m;j++)
			{
				for(k=0;k<m;k++)
				{
					C[i][j]=C[i][j]+T[i][k]*T[k][j];
				}
			}
		}
		for(i=0;i<n;i++) //
		{
			for(j=0;j<m;j++)
			{
				if(C[i][j]>0)
					C[i][j]=1;
			}
		}
		for(i=0;i<n;i++) //
		{
			for(j=0;j<m;j++)
			{
				if(C[i][j]<T[i][j])
					h=1;
					i=n;
					j=m;
			}
		}
		if(h==0)
			cout<<"T is transitve"<<endl;
		else
			cout<<"T is not transitve"<<endl;
	} //end if(n==m)
	for(i=0;i<n;i++)
	{
		dept[i]=0;
	}
	for(i=0;i<n;i++)    //
	{
		for(j=0;j<m;j++)
		{
			dept[i]=dept[i]+T[i][j];
		}
	}
	for(i=0;i<n;i++)  //
	{
		if(dept[i]==0)
			w=1;
			i=n;
	}
	for(j=0;j<n;j++)
    {
        dept2[j]=0;
    }
    for(j=0;j<n;j++)    //
    {
        for(i=0;i<m;i++)
        {
            dept2[j]=dept2[j]+T[i][j];
        }
    }
	if(w==0)
	{
		cout<<"T is Funchint"<<endl;   //
		for(j=0;j<m;j++)
		{
			if(dept2[j]==0)  // onto
			{
				s=1;
			}
			if(dept2[j]>1)   // one_to_one
			{
				z=1;
			}
		}
		if(s==0)
			cout<<"T is onto"<<endl;
		else
			cout<<"T is not onto"<<endl;
		if(z==0)
			cout<<"T is one_to_one"<<endl;
		else
			cout<<"T is not one_to_one"<<endl;
		if(s==0&&z==0)
		{
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    R[i][j]==0;
                }
            }
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					R[i][j]=T[j][i];
				}
			}
			for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    cout<<"R["<<i<<"]["<<j<<"]:"<<R[i][j]<<"    ";
                }
                cout<<endl;
            }
		}
	}   //if(w==0)
	else
		cout<<"T is not funchint"<<endl;
    if(n==m)
    {
        int p,E[n][m],v,Z[n][m],Z2[n];
        cout<<"\nEnter P : ";
        cin>>p;
        if(p>1)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    E[i][j]=0;
                    for(k=0;k<m;k++)
                    {
                        E[i][j]=E[i][j]+T[i][k]*T[k][j];
                    }
                }
            } //
            for(v=2;v<p;v++)
            {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<m;j++)
                    {
                        Z[i][j]=0;
                        for(k=0;k<m;k++)
                        {
						Z[i][j]=Z[i][j]+T[i][k]*E[k][j];
                        }
                    }
                } //
                for(i=0;i<n;i++)
                {
                    for(j=0;j<m;j++)
                    {
                        E[i][j]=Z[i][j];
                    }
                }
            }
        }
        if(p>1)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    cout<<E[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    cout<<T[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        for(i=0;i<n;i++)
        {
            Z2[i]=dept[i]+dept2[i];
        }
        cout<<"\nTotll ras : ";
        for(i=0;i<n;i++)
        {
            cout<<"Ras "<<i+1<<"= "<<Z2[i]<<"  ";
        }
    }//n==m
}
