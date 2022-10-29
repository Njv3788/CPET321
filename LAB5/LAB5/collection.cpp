/**********************************************************/
/*** Title: collection.cpp         						***/
/*** Description: Collection Class via template         ***/
/***              Class declarations & definitions      ***/
/**********************************************************/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
	class Collection {
		private:
			vector<T> myStuff;

		public:
			//
			// constructor
			//
			Collection(vector<T> x);

			//
			// member function to set the Collection
			//
			void setCollection(vector<T> x);

			//
			// member function to display the Collection
			//
			void displayCollection();

			//
			// member function to determine if the Collection
			// is in "Ascending" order, "Descending" order, 
			// or is "No" order.
			//
			string CollectionOrder();
	};
	
// Your Code Goes Here !!!
template <class T>
	Collection<T>::Collection(vector<T> x)
	{
		myStuff = x;
	}

template <class T>
	void Collection<T>::setCollection(vector<T> x)
	{
		myStuff = x;
	}

template <class T>
	void Collection<T>::displayCollection()
	{
		for (auto element : myStuff)
		{
			cout << element << ", ";
		}
		cout << endl;
	}

template <class T>
	string Collection<T>::CollectionOrder()
	{
		string order;
		bool rising = false;
		bool falling = false;
		for (auto it = myStuff.begin(); it != (myStuff.end()-1); it++)
		{
			if (*it < *(it + 1))
					rising = true;
			else if (*it > *(it + 1))
				    falling = true;
		}
		
		if (rising)
		{
			if (falling)
				order = "NO";
			else
				order = "Ascending";
		}
		else
		{
			if (falling)
				order = "Descending";
			else
				order = "NO";
		}

		return (order);
	} 
/*********************************************************/