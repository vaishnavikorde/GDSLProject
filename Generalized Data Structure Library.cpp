#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};


///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////


template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;
        T iLength;

    SinglyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOccurrence(T);
    int SearchLastOccurrence(T);
    int CalculateFrequency(T);
    int MaximumElement();
    int MinimumElement();
    int SummationAllElements();
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
    iLength = 0;
    
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
        if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{   
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {

        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

template <class T>
int SinglyLL<T>::SearchFirstOccurrence(T iSearch)
{
    NodeS<T> *temp = first;
    int iPos = -1;

    iLength = Count();
    for (int iCnt = 1; iCnt <= iLength; iCnt++)
    {
        if (temp->data == iSearch)
        {
            iPos = iCnt;
            break;
        }
        temp = temp->next;
    }
    return iPos;
    
}

template <class T>
int SinglyLL<T>::SearchLastOccurrence(T iSearch)
{
    NodeS<T> *temp = first;
    T iPos = -1;

    iLength = Count();
    for (int iCnt = 1; iCnt <= iLength; iCnt++)
    {
        if (temp->data == iSearch)
        {
            iPos = iCnt;
        }
        temp = temp->next;
    }
    return iPos;
    
}

template <class T>
int SinglyLL<T>::SummationAllElements()
{
    int iSum = 0;
    iLength = Count();
    for (int iCnt = 1; iCnt <= iLength; iCnt++)
    {
        iSum = iSum + first->data;
        first = first->next;
    }
    return iSum;
    
}

template <class T>
int SinglyLL<T>::CalculateFrequency(T iSearch)
{
    struct NodeS<T> *temp = first;
    int Counter = 0;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if (temp->data == iSearch)
        {
            Counter++;
        }
        temp = temp->next;
    }
    return Counter;
}

template<class T>
int SinglyLL<T>::MaximumElement()
{
    struct NodeS<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data > Max)
        {
            Max= temp->data;
        }
        temp= temp->next;
    }
    return Max;
}

template<class T>
int SinglyLL<T>::MinimumElement()
{
    struct NodeS<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;
    }
    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOccurrence(T);
    int SearchLastOccurrence(T);
    int CalculateFrequency(T);
    int MaximumElement();
    int MinimumElement();
    int SummationAllElements();
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    struct NodeS<T> * temp = first;

    do
    {
       cout<<"| "<<temp->data<<" | ->";
       temp = temp->next;
    } while (temp != last->next);
    cout<<"NULL"<<"\n";
   
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data =no;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;

    }
    else
    {
        newn->next = first;
        first = newn;
        
    }
    (last)->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data =no;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;

    }
    else
    {
        (last)->next = newn;
        last = last->next;
        
    }
    (last)->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    int iCount = Count();

    if ((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid position \n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iCount - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

    }
    iCount++;    
      
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        free(first); //free(*tail)
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first ->next;
        free(last -> next);
        last->next = first;

    }
    iCount--;  
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    NodeS<T> *temp = first;

    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        free(first); //free(*tail)
        first = NULL;
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }
        
        free(last);
        last = temp;
        last->next = first;

    }
    iCount--;
  
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if ((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid position \n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount + 1)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp2 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }
    
}

template <class T>
int SinglyLL<T>::SearchFirstOccurrence(T iSearch)
{
    NodeS<T> *temp = first;
    int iPos = -1;
    int iCnt = 1;

    do
    {
        if (temp->data == iSearch)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != last->next);

    return iPos;
    
}

template <class T>
int SinglyLL<T>::SearchLastOccurrence(T iSearch)
{
    NodeS<T> *temp = first;
    int iPos = -1;
    int iCnt = 1;

    do
    {
        if (temp->data == iSearch)
        {
            iPos = iCnt;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != last->next);

    return iPos;
    
}

template <class T>
int SinglyLL<T>::SummationAllElements()
{
    struct NodeS<T> *temp= first;
    int iSum= 0;

    do
    {
        iSum= iSum + temp->data;
        temp= temp->next;
    } while(temp != last->next);

    return iSum; 
    
}

template <class T>
int SinglyLL<T>::CalculateFrequency(T iSearch)
{
    struct NodeS<T> *temp = first;
    int Counter = 0;

    do
    {
        if (temp->data == iSearch)
        {
            Counter++;
        }
        temp = temp->next;
    }while(temp != last->next);

    return Counter;
}

template<class T>
int SinglyLL<T>::MaximumElement()
{
    struct NodeS<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    do
    {
        if(temp->data > Max)
        {
            Max= temp->data;
        }
        temp= temp->next;

    }while(temp != last->next);

    return Max;

}

template<class T>
int SinglyLL<T>::MinimumElement()
{
   struct NodeS<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    do
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;

    }while(temp != last->next);

    return Min;

}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int); 

    int SearchFirstOccurrence(T);
    int SearchLastOccurrence(T);
    int CalculateFrequency(T);
    int MaximumElement();
    int MinimumElement();
    int SummationAllElements();
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"Element of linked list : \n";
    cout<<"NULL";

    NodeD<T> * temp = first;

    while (temp != NULL)
    {
        cout<<" | "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
     iCount++;
    
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> * temp = first;
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
        newn->prev = temp;

    }
    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
       
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    NodeD<T> * temp = first;

    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
    
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    int iCount = Count();
    NodeD<T> * temp = first;

    if ((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position \n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
       
    }
     iCount++;
    

}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();
    NodeD<T> * temp = first;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position \n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
    }
    iCount--;
}


template<class T>
int DoublyLL<T>::SearchFirstOccurrence(T no)
{
    struct NodeD<T> *temp= first;
    int iPos= -1;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
            break;
        }
        temp= temp->next;
    }
    return iPos;
}

template<class T>
int DoublyLL<T>::SearchLastOccurrence(T no)
{
    struct NodeD<T> *temp = first;
    int iPos= -1;
    int Length= Count();

    for(int iCnt= 1; iCnt <= Length; iCnt++)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
        }
        temp= temp->next;
    }
    return iPos;

}

template<class T>
int DoublyLL<T>::CalculateFrequency(T no)
{
    struct NodeD<T> *temp= first;
    int Counter= 0;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            Counter++;
        }
        temp= temp->next;
    }
    return Counter;
}

template<class T>
int DoublyLL<T>::MaximumElement()
{
    struct NodeD<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data > Max)
        {
            Max= temp->data;
        }
        temp= temp->next;
    }
    return Max;
}
template<class T>
int DoublyLL<T>::MinimumElement()
{
    struct NodeD<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;
    }
    return Min;
}

template<class T>
int DoublyLL<T>::SummationAllElements()
{
    struct NodeD<T> *temp= first;
    int iSum= 0;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        iSum= iSum + temp->data;
        temp= temp->next;
    }
    return iSum; 
}


///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOccurrence(T);
    int SearchLastOccurrence(T);
    int CalculateFrequency(T);
    int MaximumElement();
    int MinimumElement();
    int SummationAllElements();
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;

}

template <class T>
void DoublyCL<T>::Display()
{
    cout<<"Element of linked list are : \n";

    NodeD<T> *temp = first;
    do
    {
      cout<< " | "<<temp->data<<" |->";
      temp = temp->next;
    }while(temp != last->next);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no; 
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
      newn->next = first;
      first->prev = newn;
      first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;

}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    NodeD<T> * temp = first;

    newn->data = no; 
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
       last->next = newn;
       newn->prev = last;
       last = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;

    }
    else 
    {
        first = first->next;
        delete last->next;

        last->next = first;
        first->prev = last;

    }
    iCount--;  
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;

    }
    else 
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;

    }
    iCount--;
}


template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    int iCount = Count();

    NodeD<T> *temp = first;

    if ((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"invalid position \n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;


        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
        
    }
    iCount++;
    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    NodeD<T> *temp = first;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout<<"invalid position \n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
       
        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
    }
    iCount--;
    
}

template<class T>
int DoublyCL<T>::SearchFirstOccurrence(T no)
{
    struct NodeD<T> *temp= first;
    int iPos= -1;
    int iCnt= 0;

    do
    {
        if(temp->data == no)
        {
            iPos= iCnt;
            break;
        }
        iCnt++;
        temp= temp->next;
    } while(temp != last->next);

    return iPos+1;
}

template<class T>
int DoublyCL<T>::SearchLastOccurrence(T no)
{
    struct NodeD<T> *temp= first;
    int iPos= -1;
    int iCnt= 1;

    do
    {
        if(temp->data == no)
        {
            iPos= iCnt;
        }
        temp= temp->next;
        iCnt++;
    } while(temp != last->next);

    return iPos;

}

template<class T>
int DoublyCL<T>::CalculateFrequency(T no)
{
    NodeD<T> *temp= first;
    int Counter= 0;

    do
    {
        if(temp->data == no)
        {
            Counter++;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Counter;
}

template<class T>
int DoublyCL<T>::MaximumElement()
{
    NodeD<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    do
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Max;
}
template<class T>
int DoublyCL<T>::MinimumElement()
{
    struct NodeD<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    do
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Min;
}

template<class T>
int DoublyCL<T>::SummationAllElements()
{
    struct NodeD<T> *temp = first;
    int iSum= 0;

    do
    {
        iSum= iSum + temp->data;
        temp= temp->next;
    } while(temp != last->next);

    return iSum; 
}
/////////////////////////////////////////////////////////////////////////

// Class of Queue 

///////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    public:
       struct NodeS<T> *first;
       int iCount;

    Queue();

    void Display();
    int Count();
    void Enqueue(T);
    void Dequeue();

};

template <class T>
Queue<T>::Queue()
{
   first = NULL;
   iCount = 0;
}

template <class T>
void Queue<T>::Enqueue(T no)        // InsertLast
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
} 

template <class T>
void Queue<T>::Dequeue()        // DeleteFirst
{

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;
        first = first -> next;
        delete temp;
    }

    iCount--;
}              

template <class T>
void Queue<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    
    cout<<"Elements of Queue are : \n";

    NodeS<T> *temp = first;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{ 
   public:
      struct NodeS<T> *first;
      int iCount;

    Stack();
    void Push(T);
    void Pop();
    void Display();
    int Count();

};

template <class T>
Stack<T>::Stack()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Push(T no)
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void Stack<T>::Pop()
{
    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;

}

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are : \n";

    NodeS<T> *temp = first;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////

// class of Searching and Sorting algorithm

/////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BidirectinalSearch(T);
        bool BinarySearch(T);
        bool CheckSorted();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool ArrayX<T> :: LinearSearch(T No)
{
    bool flag  = false;

    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BidirectinalSearch(T No)
{
    bool flag  = false;
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BinarySearch(T No)
{
    bool flag = false;

    int iStart = 0, iEnd = 0, iMid = 0;
    
    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if( (Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt+1])
        {
            continue;
        }
        else 
        {
            flag = false;
            break;
        }
    }
    return flag;
}


template <class T>
void ArrayX<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void ArrayX <T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void ArrayX <T>::InsertionSort()
{
    int i =0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    int iValue = 0;
    bool bRet = false;

    cout<<"Enter the size of array : \n";
    cin>>iValue;

    ArrayX <int>*obj = new ArrayX<int>(iValue);

    obj->Accept();
    obj->Display();

    obj->BubbleSortEfficient();
    cout<<"Data after sorting is : \n";
    obj->Display();

    delete obj;

    SinglyLL <int>obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(21);

    obj1.Display();
    cout<<"Element of linked list are : "<<obj1.Count()<<"\n";

    cout<<"SearchfirstOccurrence of linked list are : "<<obj1.SearchFirstOccurrence(21)<<"\n";
    cout<<"SearchfirstOccurrence of linked list are : "<<obj1.SearchLastOccurrence(21)<<"\n";
    cout<<"SearchfirstOccurrence of linked list are : "<<obj1.CalculateFrequency(21)<<"\n";


    SinglyCL <int>obj2;

    DoublyLL <int>obj3;

    Queue <char>obj5;
    
    Stack <char>obj4;

    DoublyCL <int>obj8;

    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////
