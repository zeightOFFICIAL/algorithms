#include <iostream>
using std::cout, std::cin;

unsigned long long int UnaryEnveloper(unsigned long long int(*func)(unsigned long long int))
{
    unsigned long long int X = -1, N;
    clock_t t;
    while (1)  {
            cout << "Enter the number of terms: ";
            cin >> N;
            if (N<0 || N>10000000)
                cout<<"Warning: Enveloper: Wrong number of terms!";
            else
                break;
        }

    t = clock();
    X=func(N);
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    cout<< N <<"-x element: "<< X << "\n";
    return X;
}

unsigned long long int BinaryEnveloper(unsigned long long int(*func)(unsigned long long int, unsigned long long int))
{
    unsigned long long int y,x,R;
    clock_t t;
    while (1) {
            cout << "Enter X: ";
            cin >> x;
            cout << "Enter Y: ";
            cin >> y;
            if (x<=0 || y<0)
                cout<<"Warning: Enveloper: Wrong number!";
            else
                break;
        }
    
    t = clock();
    R=func(x,y);
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    cout<<"GCD is: " << R << "\n";
    return R;
}

unsigned long long int UnaryEnveloperForTailRecursion(unsigned long long int(*func)(unsigned long long int, unsigned long long int, unsigned long long int))
{
    unsigned long long int X = -1, N;
    clock_t t;
    while (1)  {
            cout << "Enter the number of terms: ";
            cin >> N;
            if (N<0 || N>10000000)
                cout<<"Warning: Enveloper: Wrong number of terms!";
            else
                break;
        }
    t = clock();
    X=func(N,0,1);
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    cout<< N <<"-x element: "<< X << "\n";
    return X;
}