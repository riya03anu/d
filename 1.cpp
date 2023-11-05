#include <bits/stdc++.h>
using namespace std ;

struct Item 
{
	double profit ;
	double weight ;
	int index ;
};

bool comparator(Item A, Item B)
{
	double ratio1 = (double)A.profit/(double)A.weight ;
	double ratio2 = (double)B.profit/(double)B.weight ;
	return ratio1 > ratio2 ; // returns true if R1 > R2 
};

int knapSack(Item data[], int size, int maxWeight)
{

    Item sortedData[size];
    for (int i = 0; i < size; i++)
    {
        sortedData[i] = data[i];
    }

    sort(sortedData, sortedData + size, comparator); //Sorting using custom comparator

	double maxValue = 0.0 ;

	cout << "Selected Items" << endl ;

	for(int i = 0 ; i < size ; i++)
	{
		if (data[i].weight <= maxWeight) {
			maxWeight -= data[i].weight;
			maxValue += data[i].profit;
			cout << "Item index: " << data[i].index << ", profit: " << data[i].profit << ", Quantity: 1" << endl;
		} else {
			double fractionalQuantity = (double)maxWeight / (double)data[i].weight;
			double fractionalProfitValue = ((double)data[i].profit) * ((double)fractionalQuantity);

			maxValue += fractionalProfitValue;

			cout << "Item index: " << data[i].index << ", profit: " << fractionalProfitValue << ", Quantity: " << fractionalQuantity << endl;

			// Break the loop as the knapsack is full
			break;
		}

	}

	cout << "Max profit: " << maxValue ;
}

int main()
{
	int size ;

	cout << "Enter No. of Items: "  ;
	cin >> size ;

	Item data[size] ;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the " << i << "th item profit Value: " ;
		cin >> data[i].profit ;

		cout << "Enter the " << i << "th item weight Value: " ;
		cin >> data[i].weight ;

		data[i].index = i ;
	}

	int maxWeight = 0 ;

	cout << "Enter the max weight: " ;
	cin >> maxWeight ;
	
	knapSack(data,size,maxWeight) ;

	return 0 ;
}
