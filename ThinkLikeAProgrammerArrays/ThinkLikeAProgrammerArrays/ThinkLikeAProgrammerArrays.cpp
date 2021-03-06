﻿// ThinkLikeAProgrammerArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int compareFunc(const void * voidA, const void * voidB)
{
	int * intA = (int *)(voidA);
	int * intB = (int *)(voidB);
	return *intA - *intB;
}

int main()
{
	//Initialize an array
	int tenIntegerArray[10] = { 4,5,6,7,8,9,0,1,2,3 };

	//Copy an Array
	int secondArray[10];
	for (int i = 0; i < 10; i++)
	{
		secondArray[i] = tenIntegerArray[i];
	}

	//Searh for a particular value
	const int ARRAY_SIZE = 10;
	int intArray[ARRAY_SIZE] = { 4, 56, 109, 23, -490, -789, 99, 890, -211, 234 };
	int targetValue = -490;
	int targetPos = 0;

	while (intArray[targetPos] != targetValue && targetPos != ARRAY_SIZE)
	{
		targetPos++;
	}
	cout << "The number " << intArray[targetPos] << " lies at index value " << targetPos << " within the array" << endl;

	//Criterion based search
	//Highest Value
	int highestValue = intArray[0];

	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if (intArray[i] > highestValue)
			highestValue = intArray[i];
	}
	cout << "The highest value in the array is " << highestValue << endl;

	//Sorting
	//The easy way: qsort
	qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);
	for (int j = 0; j < ARRAY_SIZE; j++)
	{
		cout << intArray[j] << " ";
	}


	//Insertion Sort - One number is selected at a time, and if in the correct order placed on top if not placed back into
	//the stack
	int intArraySort[ARRAY_SIZE] = { 4, 56, 109, 23, -490, -789, 99, 890, -211, 234 };
	int start = 0;
	int end = ARRAY_SIZE - 1;
	for (int i = start + 1; i < end; i++)
	{
		for (int j = i; j > start && intArraySort[j - 1] > intArraySort[j]; j--) 
		{
			int temp = intArraySort[j - 1];
			intArraySort[j - 1] = intArraySort[j];
			intArraySort[j] = temp;
			cout << "j = " << intArraySort[j];
			cout << "temp = " << temp;
		}
		cout << "i = " << intArraySort[i];
	}
	cin.get();
}	
