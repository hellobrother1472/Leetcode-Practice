#include <iostream>
#include <string>

using namespace std;

void pOne(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pTwo(int n, int ind)
{
    if (ind == n)
    {
        return;
    }
    for (int i = 0; i <= ind; i++)
    {
        cout << "*";
    }
    cout << endl;
    pTwo(n, ind + 1);
}

void pThree(int n)
{
    // int num = 0;
    // string s = "" ;
    // for (int i = 0; i < n; i++)
    // {
    //     num++;
    //     s.append(to_string(num));
    //     cout<<s<<endl;
    // }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j <= i; j++)
        {
            count++;
            cout << count;
        }
        cout << endl;
    }
}
void pFour(int n)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        for (int j = 0; j <= i; j++)
        {
            // count ++ ;
            cout << count;
        }
        cout << endl;
    }
}
void five(int n)
{

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= n / 2 - i && j <= n / 2 + i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void six(int n)
{

    for (int i = n / 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= n / 2 - i && j <= n / 2 + i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void seven(int n)
{

    for (int i = 0; i <= n; i++)
    {
        if (n / 2 - i > 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (j >= n / 2 - i && j <= n / 2 + i)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (j >= i - n / 2 - 1 && j <= n / 2 + n - i)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }

        cout << endl;
    }
}

void eight(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // for (int j = n-i; j > 0; j--)
        // {
        //     cout << "*";
        // }
        // cout<< endl;
        count++;
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // for (int j = n-i; j > 0; j--)
        // {
        //     cout << "*";
        // }
        // cout<< endl;
        count++;
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void nine(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            if ((n - 1 + i - j) % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }

        cout << endl;
    }
}

void ten(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j <= i)
            {
                cout << j + 1;
            }
            else if (j >= n && 2 * n - j <= i + 1)
            {

                cout << 2 * n - j;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void eleven(int n)
{
    int val = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << val << " ";
            val++;
        }
        cout << endl;
    }
}

void twelve(int n)
{
    for (int i = n; i >= 0; i--)
    {
        char val = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << val;
            val++;
        }
        cout << endl;
    }
}

void thirteen(int n)
{
    char val = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << val;
        }
        val++;
        cout << endl;
    }
}

void fourteen(int n)
{
    char val = 'A';
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= n / 2 - i && j <= n / 2 + i)
            {
                cout << char(val - abs(n / 2 - j) + i);
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void fifteen(int n)
{
    char val = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(val + (n - 1 + j - i));
        }
        cout << endl;
    }
}

void sixteen(int n)
{
    for (int i =0; i < 2*n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            if(i>=n){
                if(j >= n-(2*n-i-1) && j < n+(2*n-i-1)){
                    cout<< " ";
                }
                else{
                    cout<<"*";
                }
            }
                       
            else{
                if(j >= n-i && j <n+i){
                    cout<< " ";
                }
                else{
                    cout<<"*";
                }
            }
        }
        cout << endl;
    }
}

void seventeen(int n)
{
    for (int i =0; i < 2*n; i++)
    {
        if(i==n){
            continue;
        }
        for (int j = 0; j < 2*n; j++)
        {
            if(i>=n){
                if(j <= 2*n - i-1 || j >= i){
                    cout<< "*";
                }
                else{
                    cout<<" ";
                }
            }                       
            else{
                if(j<=i || j >= 2*n -1 - i){
                    cout << "*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout << endl;
    }
}

void eighteen(int n)
{
    for (int i =0; i <= n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if(i == 0 || i == n){
                cout<< "*";
            }
            else{
                if(j == 0 || j ==n-1 ){
                    cout<< "*";
                }
                else{
                    cout<< " ";
                }
            }
        }
        cout << endl;
    }
}

void nineteen(int n){
    int val = n;
    for (int i =0; i <= n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if(i == 0 || i == n){
                cout<< n;
            }
            else{
                if(j == 0 || j ==n-1 ){
                    cout<< "*";
                }
                else{
                    cout<< " ";
                }
            }
        }
        cout << endl;
    }
}

int main()
{

    // pOne(4);
    // pTwo(4,0);
    // pThree(4);
    // pFour(4);
    // cout << char('A'+4);
    // five(10);
    // six(10);
    // seven(11);
    // eight(6);
    // nine(6);
    // ten(4);
    // eleven(5);
    // twelve(5);
    // thirteen(5);
    // fourteen(10);
    // fifteen(5);
    // sixteen(5);
    // seventeen(5);
    eighteen(5);
    return 0;
}