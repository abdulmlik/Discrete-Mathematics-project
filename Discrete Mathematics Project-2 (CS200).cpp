#include <iostream>
#include <cstdlib>//system

using namespace std;

int row, col;

bool Reflaxive(int **Array)
{
    int array2[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            array2[i][j] = Array [i][j];
        }
    }
    for(int i = 0; i < row ;i++)
    {
        if(array2[i][i]!= 1)
        {
            return false;
        }
    }
    return true;
}
bool irReflaxive(int **Array)
{
    int array2[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            array2[i][j] = Array [i][j];
        }
    }
    for(int i = 0; i < row ;i++)
    {
        if(array2[i][i]!= 0)
        {
            return false;
        }
    }
    return true;
}

bool Symmatric(int **Array)
{
    int array2[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            array2[i][j] = Array [i][j];
        }
    }
    for(int i = 0; i < row ;i++)
    {
        for (int j =i+1 ; j<col; j++)
        {
            if(array2[i][j]!= array2[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
bool Transitive(int **Array)
{
    int array2[row][col],array3[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            array3[i][j] = 0;
            array2[i][j] = Array [i][j];
        }
    }
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            for (int c=0; c<col; c++)
            {
                array3 [i][j] = array3 [i][j] + array2 [i][c] * array2 [c][j];
            }
        }

    }// A x A
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (array2 [i][j] == 0 && array3 [i][j] > 0)
            {
                return false;
            }
        }
    }

    return true;
}

bool one_to_one(int *sumRow , int *sumCol)
{
    int array2[row],array3[col];
    for (int i=0; i<row; i++)
    {
        array2[i] = sumRow[i];
    }
    for (int i=0; i<col; i++)
    {
        array3[i] = sumCol[i];
    }

    bool R=true,C=true;
    for(int i=0 ;i<row;i++)
    {
        if(array2[i] != 1)
        {
            R = false;
            break;
        }
    }
    for(int i=0 ;i<col;i++)
    {
        if(array3[i] != 1)
        {
            C = false;
            break;
        }
    }
    return (R && C);
}

void c_transitive(int **Array)
{
    int mul_array[row][col], temp_array[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            mul_array[i][j] = Array[i][j];
            temp_array[i][j] = 0;
        }
    }
    bool flage = true;
    int AZero, Abefor, AI;
    while(flage)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int c = 0; c< col; c++)
                {
                    temp_array[i][j] += Array[i][c] * mul_array[c][j];
                }
            }
        }
        AZero   = 0;
        Abefor  = 0;
        AI      = 0;
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if(temp_array[i][j] == mul_array[i][j])
                {
                    Abefor += 1;
                }
                if( (i != j && temp_array[i][j] == 0) || (i == j && temp_array[i][j] == 1) )
                {
                    AI += 1;
                }
                if( temp_array[i][j] == 0)
                {
                    AZero += 1;
                }
            }
        }
        if( AZero == row*col || AI == row*col || Abefor == row*col)
        {
            for (int i=0; i<row; i++)
            {
                cout << endl << "|";
                for (int j=0; j<col; j++)
                {
                    cout <<" " << temp_array[i][j];
                }
                cout << " |";
            }
            flage = false;
        }
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                mul_array[i][j] = temp_array[i][j];
                temp_array[i][j] = 0;
            }
        }
    }
}

int main()
{
    int sum=0, path;

    cout << "Enter Size of Array ( Row X Column ) : ";
    cin >> row >> col ;
    cout << "Enter The Path Length : " ;
    cin >> path;
    int **Array = new int*[row];
    for(int i=0 ;i<row;i++)
    {
        Array[i] = new int[col];
    }
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            cout << "Enter Array[" << i <<"]["<<j<<"] ? ";
            cin >> Array [i][j];
            sum += Array [i][j];
        }
    }
    cout <<endl <<"Element in Array is : ";
    for (int i=0; i<row; i++)
    {
        cout << endl << "|";
        for (int j=0; j<col; j++)
        {
            cout << " " << Array[i][j];
        }
        cout << " |";
    }
    cout << endl;
    if(row == col)
    {
        bool R, IR, S, T;
        R  = Reflaxive(Array);
        IR = irReflaxive(Array);
        S  = Symmatric(Array);
        T  = Transitive(Array);
        if( R )///////////////////
        {
            cout <<endl<< "A Relation is Reflaxive" << endl;
        }
        else
        {
            cout <<endl<< "A Relation is Not Reflaxive" << endl << "complement Reflaxive is :";
            for (int i=0; i<row; i++)
            {
                cout << endl << "|";
                for (int j=0; j<col; j++)
                {
                    if(i!=j) cout << " " << Array[i][j];
                    else cout << " 1";
                }
                cout << " |";
            }
            cout << endl;
        }// end reflaxive
        if( IR )/////////////////// start irReflaxive
        {
            cout <<endl<< "A Relation is irReflaxive" << endl;
        }
        else
        {
            cout <<endl<< "A Relation is Not irReflaxive" << endl << "complement irReflaxive is :";
            for (int i=0; i<row; i++)
            {
                cout << endl << "|";
                for (int j=0; j<col; j++)
                {
                    if(i!=j) cout << " " << Array[i][j];
                    else cout << " 0";
                }
                cout << " |";
            }
            cout << endl;
        }// end irReflaxive
        if( S )/////////////////// start Symmatric
        {
            cout <<endl<< "A Relation is Symmatric" << endl;
        }
        else
        {
            cout <<endl<< "A Relation is Not Symmatric" << endl << "complement Symmatric is :";
            for (int i=0; i<row; i++)
            {
                cout << endl << "|";
                for (int j=0; j<col; j++)
                {
                    if(i < j)cout << " " << Array[i][j];
                    else cout << " " << Array[j][i];
                }
                cout << " |";
            }
            cout << endl;

        }// end Symmatric'
        if( T )/////////////////// start Transitive
        {
            cout <<endl<< "A Relation is Transitive" << endl;
        }
        else
        {
            cout <<endl<< "A Relation is Not Transitive" << endl << "complement Transitive (R+) is :";
            c_transitive(Array);
            cout << endl;
        }// end Transitive'
        if(R && S && T)
        {
            cout <<endl<< "A Relation is Parity" << endl;
        }
        else
        {
            cout <<endl<< "A Relation is Not Parity" << endl ;

        }// end Equisvjence'
        if(R && !S && T)
        {
            cout <<endl<< "A Relation is Order of Partial" << endl;
        }
        else
        {
            cout <<endl<< "A Relation is Not Order of Partial" << endl ;

        }// end Equisvjence'
    }// col == row

    int *sumRow =new int[row] ,*sumCol = new int[col];
    bool Fun = true;
    for (int i=0; i<row; i++)
    {
        sumRow[i] = 0;
        for (int j=0; j<col; j++)
        {
            sumRow[i] += Array [i][j];
        }
    }
    for (int i=0; i<col; i++)
    {
        sumCol[i] = 0;
        for (int j=0; j<row; j++)
        {
            sumCol[i] += Array [j][i];
        }
    }
    for (int i=0; i<row; i++)
    {
        if (sumRow[i] != 1)
        {
            Fun = false;
            break;
        }
    }
    if(Fun)
    {
        bool o_to_o,onto=true,into=true;
        o_to_o = one_to_one(sumRow,sumCol);
        cout <<endl<< "A Relation is Function" <<endl;
        if(o_to_o){
            cout << "A Relation is one to one" <<endl;
        }
        else{
            cout << "A Relation is Not one to one" <<endl;
        }
        for(int i;i<col;i++)
        {
            if(sumCol[i]==0)
            {
                onto = false;
                break;
            }
        }
        if(onto){
            cout << "A Relation is onto" <<endl;
        }
        else{
            cout << "A Relation is Not onto" <<endl;
        }
        if(onto && o_to_o){
            cout << "A Relation is Bijective" <<endl;
        }
        else{
            cout << "A Relation is Not Bijective " <<endl;
        }
        for(int i;i<col;i++)
        {
            if(sumCol[i]!=0)
            {
                into = false;
                break;
            }
        }
        if(into){
            cout << "A Relation is into" <<endl;
        }
        else{
            cout << "A Relation is Not into" <<endl;
        }
    }
    else{
        cout <<endl << "A Relation is Not Function" <<endl;
    }//end function
    if(row == col)
    {
        cout << endl << "The Number of Vertices : " << row <<endl;
        cout << "The Number of edge : " << sum <<endl;
        int sumKter = 0;
        bool graph = true;
        for(int i = 0;i<row ;i++)
        {
            sumKter += Array[i][i];
        }
        for(int i = 0;i<row ;i++)
        {
            for(int j=0;j<col ;j++)
            {
                if( Array[i][j] > 1)
                {
                    graph = false;
                    break;
                }
            }
        }
        if(graph && sumKter == 0)
        {
            cout <<endl<< "Graph is Simple" <<endl;
        }
        else if( !graph )
        {
            cout <<endl << "Graph is Multigraph" << sum <<endl;
        }
        cout <<endl<< "the degree of Heads : " <<endl;
        for(int i=0 ;i < row; i++)
        {
            cout <<"head "<< i << " : " <<sumCol[i]+sumRow[i]<<endl;
        }
        int mul_array[row][col], temp_array[row][col];
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                mul_array[i][j] = Array[i][j];
                temp_array[i][j] = 0;
            }
        }
        for (int p = 1; p < path; p++)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    for (int c = 0; c< col; c++)
                    {
                        temp_array[i][j] += Array[i][c] * mul_array[c][j];
                    }
                }
            }

           for (int i=0; i<row; i++)
           {
                for (int j=0; j<col; j++)
                {
                    mul_array[i][j] = temp_array[i][j];
                    temp_array[i][j] = 0;
                }
           }
        }//path
        cout << endl << "The Path Length is : " << path << endl;
        for (int i=0; i<row; i++)
        {
            cout << endl << "|";
            for (int j=0; j<col; j++)
            {
                cout << " " << mul_array[i][j] ;
            }
            cout <<" |";
        }
        cout <<endl;
        system("PAUSE");
    }//end row == col
    return 0;
}
