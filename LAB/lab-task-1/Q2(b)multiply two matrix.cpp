#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int arr1[2][2], arr2[2][2], result[2][2];
	int i,j;
	cout<<"Enter the elements of array-1: "<<endl;
	for(i=0;i<=4;i++){
		for(j=0;j<=4;j++){
			cin>>arr1[4][4];
		}
	}
	cout<<endl;
	cout<<"Enter the elements of array-2: "<<endl;
	for(i=0;i<=4;i++){
		for(j=0;j<=4;j++){
			cin>>arr2[4][4];
		}
		
	}	
	for(i=0;i<=4;i++){
		for(j=0;j<=4;j++){
			result[i][j] = result[i][j] + arr1[i][j] * arr2[i][j];
		}
	}	
	cout<<"Result :"<<endl<<endl ;
	for(i=0;i<=4;i++){
	    for(j=0;j<=4;j++){
		cout<<result[i][j]<<endl;
		}
	}
	
	return 0;
}

//	Multiplying two matrix
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;
//
//    cout << "Enter rows and columns for first matrix: ";
//    cin >> r1 >> c1;
//    cout << "Enter rows and columns for second matrix: ";
//    cin >> r2 >> c2;
//
//    // If column of first matrix in not equal to row of second matrix,
//    // ask the user to enter the size of matrix again.
//    while (c1!=r2)
//    {
//        cout << "Error! column of first matrix not equal to row of second.";
//
//        cout << "Enter rows and columns for first matrix: ";
//        cin >> r1 >> c1;
//
//        cout << "Enter rows and columns for second matrix: ";
//        cin >> r2 >> c2;
//    }
//
//    // Storing elements of first matrix.
//    cout << endl << "Enter elements of matrix 1:" << endl;
//    for(i = 0; i < r1; ++i)
//        for(j = 0; j < c1; ++j)
//        {
//            cout << "Enter element a" << i + 1 << j + 1 << " : ";
//            cin >> a[i][j];
//        }
//
//    // Storing elements of second matrix.
//    cout << endl << "Enter elements of matrix 2:" << endl;
//    for(i = 0; i < r2; ++i)
//        for(j = 0; j < c2; ++j)
//        {
//            cout << "Enter element b" << i + 1 << j + 1 << " : ";
//            cin >> b[i][j];
//        }
//
//    // Initializing elements of matrix mult to 0.
//    for(i = 0; i < r1; ++i)
//        for(j = 0; j < c2; ++j)
//        {
//            mult[i][j]=0;
//        }
//
//    // Multiplying matrix a and b and storing in array mult.
//    for(i = 0; i < r1; ++i)
//        for(j = 0; j < c2; ++j)
//            for(k = 0; k < c1; ++k)
//            {
//                mult[i][j] += a[i][k] * b[k][j];
//            }
//
//    // Displaying the multiplication of two matrix.
//    cout << endl << "Output Matrix: " << endl;
//    for(i = 0; i < r1; ++i)
//    for(j = 0; j < c2; ++j)
//    {
//        cout << " " << mult[i][j];
//        if(j == c2-1)
//            cout << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int r, c, a[100][100], b[100][100], sum[100][100], i, j;
//
//    cout << "Enter number of rows (between 1 and 100): ";
//    cin >> r;
//
//    cout << "Enter number of columns (between 1 and 100): ";
//    cin >> c;
//
//    cout << endl << "Enter elements of 1st matrix: " << endl;
//
//    // Storing elements of first matrix entered by user.
//    for(i = 0; i < r; ++i)
//       for(j = 0; j < c; ++j)
//       {
//           cout << "Enter element a" << i + 1 << j + 1 << " : ";
//           cin >> a[i][j];
//       }
//
//    // Storing elements of second matrix entered by user.
//    cout << endl << "Enter elements of 2nd matrix: " << endl;
//    for(i = 0; i < r; ++i)
//       for(j = 0; j < c; ++j)
//       {
//           cout << "Enter element b" << i + 1 << j + 1 << " : ";
//           cin >> b[i][j];
//       }
//
//    // Adding Two matrices
//    for(i = 0; i < r; ++i)
//        for(j = 0; j < c; ++j)
//            sum[i][j] = a[i][j] + b[i][j];
//
//    // Displaying the resultant sum matrix.
//    cout << endl << "Sum of two matrix is: " << endl;
//    for(i = 0; i < r; ++i)
//        for(j = 0; j < c; ++j)
//        {
//            cout << sum[i][j] << "  ";
//            if(j == c - 1)
//                cout << endl;
//        }
//
//    return 0;
//}
