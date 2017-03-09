template<typename AnyDataType>
class MyDynamicArray
{
    private:
    	AnyDataType outOfBounds;
        int elementsInArray;
        int arrayLength;
        AnyDataType* defaultArray;

    public:
        MyDynamicArray();
        MyDynamicArray(int);
        ~MyDynamicArray();
        AnyDataType& operator[](int i);
        void add(AnyDataType);
        void del();
        int length();
        void clear();
};

template<typename AnyDataType>
MyDynamicArray<AnyDataType>::MyDynamicArray()
{
    defaultArray = new AnyDataType[2];
    elementsInArray = 0;
    arrayLength = 2;
}

template<typename AnyDataType>
MyDynamicArray<AnyDataType>::MyDynamicArray(int s)
{
    defaultArray = new AnyDataType[s];
    elementsInArray = s;
    arrayLength = s;
}

template<typename AnyDataType>
MyDynamicArray<AnyDataType>::~MyDynamicArray()
{
    delete[] defaultArray;
}

template<typename AnyDataType>
int MyDynamicArray<AnyDataType>::length()
{
    return elementsInArray;
}

template<typename AnyDataType>
void MyDynamicArray<AnyDataType>::add(AnyDataType value)
{
	if(elementsInArray < arrayLength)
	{
		defaultArray[elementsInArray] = value;
		elementsInArray++;
	}

	else
	{
		arrayLength = arrayLength * 2;

		AnyDataType* tempArray = new AnyDataType[arrayLength];
		for(int j = 0; j < elementsInArray; j++)
		{
			tempArray[j] = defaultArray[j];
		}

		delete[] defaultArray;
		defaultArray = tempArray;

		defaultArray[elementsInArray] = value;
		elementsInArray++;
	}
}

template<typename AnyDataType>
void MyDynamicArray<AnyDataType>::del()
{
	if(elementsInArray < (arrayLength/4))
	{
		arrayLength = arrayLength/2;

		AnyDataType* tempArray = new AnyDataType[arrayLength];

		for(int j = 0; j < elementsInArray; j++)
		{
			tempArray[j] = defaultArray[j];
		}

		delete[] defaultArray;
		defaultArray = tempArray;
	}

    defaultArray[elementsInArray] = '\0';
    elementsInArray--;
}

template<typename AnyDataType>
void MyDynamicArray<AnyDataType>::clear()
{
    delete[] defaultArray;
    defaultArray = new AnyDataType[2];
    elementsInArray = 0;
    arrayLength = 2;
}

template<typename AnyDataType>
AnyDataType& MyDynamicArray<AnyDataType>::operator[](int i)
{
	if(i >= elementsInArray || i < 0)
	{
		//cout << "Out of bound reference : " << i << endl;
		return outOfBounds;
	}

	else
	{
		return defaultArray[i];
	}
}
