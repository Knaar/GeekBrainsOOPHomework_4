
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
// Hi there!

//  1 Task
//  Macing Container
class Container
{
public:
    int* Some_data;
    int Size_of_massive;
    Container() :Some_data(nullptr), Size_of_massive(0) {}
    Container(int Size) :Size_of_massive(Size) {
        assert(Size >= 0);
        if (Size > 0)
        {
            Some_data = new int[Size];
            for (size_t i = 0; i < Size; i++)
            {
                Some_data[i] = 0;

            }
        }
        else
        {
            Some_data = nullptr;
        }
    }
    ~Container() { delete[] Some_data; }

    void erase() {
        delete[] Some_data;
        Some_data = nullptr;
        Size_of_massive = 0;
    }
    int GetSize() { return Size_of_massive; }

    int operator[](int& a) {
        assert(a >= 0 && a <= Size_of_massive);
        return Some_data[a];
    }
    void Resize(int New_Size)
    {
        if (New_Size = Size_of_massive) {
            return;
        }

        if (New_Size <= 0)
        {
            erase();
            return;
        }
        int* data = new int[New_Size];
        if (New_Size > 0)
        {
            int CopyTemp = (New_Size > Size_of_massive) ? New_Size : Size_of_massive;

            for (int i = 0; i < CopyTemp; i++)
            {
                data[i] = Some_data[i];
            }
        }
        delete[] Some_data;
        Some_data = data;
        Size_of_massive = New_Size;
    }
    void insertBefore(int value, int index)
    {

    }
    void InsertBefore(int value/*значение*/, int index/*место*/)
    {
        assert(index >= 0 && index <= Size_of_massive);

        int* NewData = new int[Size_of_massive + 1];

        for (int beforeIndex = 0; beforeIndex < index; ++beforeIndex)
        {
            NewData[beforeIndex] = Some_data[beforeIndex];
        }
        NewData[index] = value;


        for (int afterIndex = index; afterIndex < Size_of_massive; ++afterIndex)
        {
            NewData[afterIndex + 1] = Some_data[afterIndex];
        }

        delete[] Some_data;

        Some_data = NewData;
        ++Size_of_massive;

    }
    void PushBack(int value)
    {
        InsertBefore(value, Size_of_massive);
    }
    //  Include Pop Back element

    void PopBack(int HowMuchDelete)
    {
        int New_size = Size_of_massive - HowMuchDelete;
        int* NewData = new int[New_size];

        for (int i = 0; i < New_size; i++)
        {
            NewData[i] = Some_data[i];
        }
        delete[] Some_data;
        Some_data = NewData;
        Size_of_massive = New_size;
    }

    //  Also Pop Front Element

    void PopFront(int HowMuchDelete)
    {
        int New_size = Size_of_massive - HowMuchDelete;
        int* NewData = new int[New_size];
        for (int i = 0; i < New_size; i++)
        {
            NewData[i] = Some_data[i + HowMuchDelete];
        }
        delete[] Some_data;
        Some_data = NewData;
        Size_of_massive = New_size;
    }

    // Include Sorting. I used Bubble sorting. It's long but Undertandable) 

    void BubblesSorting()
    {
        for (int i = 0; i < Size_of_massive; i++) {
            for (int j = 0; j < Size_of_massive - 1; j++) {
                if (Some_data[j] > Some_data[j + 1]) {
                    int b = Some_data[j]; 
                    Some_data[j] = Some_data[j + 1]; 
                    Some_data[j + 1] = b; 
                }
            }
        }

    }

    // Also "show" for console output

    void Show()
    {
        cout << "Data : ";
        for (size_t i = 0; i < Size_of_massive; i++)
        {
            cout << Some_data[i];
        }
        cout << endl;
    }
};





//  2 Task

//I have used element of the stamdart library:sort,unique,resize

void Vector() {

    vector<int> SomeNums= { 1, 11, 67, 1, 99, 11, 3, 3, 3, 10, 1, 999, 3, 123213, 3, 7, 7, 8 };

    vector<int>::iterator runner;
    int Size=SomeNums.size();
    // sorting so that all repeated numbers stand side by side
    sort(SomeNums.begin(), SomeNums.begin() +Size);
    // remove dublicates
    runner = unique(SomeNums.begin(), SomeNums.begin() +Size);
    //resize
    SomeNums.resize(distance(SomeNums.begin(), runner));
    //console output
    for ( runner = SomeNums.begin(); runner != SomeNums.end(); ++runner)
    {
        cout << *runner<<" ";
    }  
}


// 3 Task

//Added block of prevous Homework to test the functionality
enum ERank {
    Ace = 1,
    Two = 2,
    Tree = 3,
    Four = 4,
    Six = 6,
    Seven = 7,
    Eigh = 8,
    Nine = 9,
    Ten = 10,
    Jack = 10,
    Queen = 10,
    King = 10
};
enum ESuit { Hearts, Diamonds, Clubs, Spades };
class Card {
public:
    ERank Rank;
    ESuit Suit;
    bool FrontSide;

    Card(ERank r, ESuit s) :Rank(r), Suit(s) { FrontSide = true; }

    void Flip();
    int GetValue() const;
};
int Card::GetValue()const
{
    return Rank;
}
void Card::Flip() {
    FrontSide = !FrontSide;
}

//Now the Class Hand

class Hand
{
public:
    vector<Card*>CardVector;

    void Add(Card* someCard)
    {
        CardVector.push_back(someCard);
    }
    void Dell()
    {
        vector<Card*>::iterator runner = CardVector.begin();
        for (runner = CardVector.begin(); runner != CardVector.end(); ++runner)
        {
            *runner = 0;
        }
    }
    int Points;
    int GetValue()
    {

        vector<Card*>::const_iterator it = CardVector.begin();
        for (it = CardVector.begin(); it != CardVector.end(); ++it)
        {
            Points += (*it)->GetValue();
            cout << "Points :";

        }

        //I did not make a request to user about the Ace. I have established ihat if there are few points,then the ace is equeal to 1

        for (it = CardVector.begin(); it != CardVector.end(); ++it)
        {
            if ((*it)->GetValue() == Ace && Points <= 11)
            {
                Points += 10;
            }

        }
        return Points;
    }
};



int main()

{

    Vector();


    Card F(Ace, Diamonds);
    Hand hand;
    hand.Add(&F);
    cout << "Hand got :" << hand.GetValue() << endl;
    Container Mass(3);


    Mass.InsertBefore(7, 0);
    Mass.InsertBefore(6, 1);
    Mass.InsertBefore(2, 4);
    Mass.InsertBefore(7, 3);
    Mass.Show();

    Mass.BubblesSorting();
    Mass.Show();
    Mass.PopBack(1);
    Mass.Show();
    return 0;
}