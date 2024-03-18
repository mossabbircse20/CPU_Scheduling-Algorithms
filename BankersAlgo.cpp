#include<bits/stdc++.h>
using namespace std;

int main()
{
    int Max[20][20],need[20][20],alloc[20][20],avl[20],comp[20],safeSeq[20];
    int p=0,r=0,pros=0,cnt=0;

    cout << "Enter the number of processes : ";
    cin >> p;

    cout << "Enter the number of resources: ";
    cin >> r;

    cout << "Enter the Max allocation for each process : " << endl;
    for(int i=0 ; i<p ; i++)
    {
        cout << "P" << i+1 << ": ";
        for(int j=0 ; j<r ; j++)
        {
            cin >> Max[i][j];
        }
    }

    cout << "Enter the allocation for each process : " << endl;
    for(int i=0 ; i<p ; i++)
    {
        cout << "P" << i+1 << " : ";
        for(int j=0 ; j<r ; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the Available Resources : " << endl;
    for(int i=0 ; i<r ; i++)
    {
        cin >> avl[i];
    }

    for(int i=0 ; i<p ; i++)
    {
        comp[i]=0;
    }

    for(int i=0 ; i<p ; i++)
    {
        for(int j=0 ; j<r ; j++)
        {
            need[i][j] = Max[i][j] - alloc[i][j];
        }
    }
    cout << endl;
    do{
        cout << "Max Allocation\tAllocations" << endl;
        cout << "--------------\t-------------"<<endl;
        for(int i=0 ; i<p ; i++)
        {
            for(int j=0 ; j<r ; j++)
            {
                cout << Max[i][j] << " ";
            }
            cout << "\t\t\t";
            for(int j=0 ; j<r ; j++)
            {
                cout << alloc[i][j] << " ";
            }
            cout << endl;

        }

        pros = -1; // not completed ;

        /*This for loop is checking the process are completed or not */
        for(int i=0 ; i<p ; i++)
        {
            if(comp[i]==0)
            {
                pros = i;
                for(int j=0 ; j<r ; j++)
                {
                    if(avl[j]<need[i][j])
                    {
                        pros = -1;
                        break;
                    }
                }
            }
            if(pros != -1)
            {
                break;
            }
        }

        if(pros != -1)
        {
            cout << endl;
            cout << "P" << pros + 1 << " is runs to completion!" << endl;
            safeSeq[cnt] = pros + 1;
            cnt++;
            for(int j=0 ; j<r ; j++)
            {
                avl[j] += alloc[pros][j];
                alloc[pros][j] = 0;
                Max[pros][j] = 0;
                comp[pros] = 1;
            }
        }


    }while(cnt != p && pros != -1);

    if(cnt == p)
    {
        cout << endl;
        cout << "The system is in a safe state !!"<<endl ;
        cout << "Safe Sequence is : { " ;
        for(int i=0 ; i<p ; i++)
        {
            cout <<"P" <<safeSeq[i] << " ";
        }
        cout << "}" << endl;
    }
    else
    {
        cout << "The system is in an unsafe state !!" ;
    }

}
