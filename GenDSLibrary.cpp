////////////////////////////////////////////////////////////////////
//          Generalised Data Structure Library
///////////////////////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------------
Type                    Name of Class for node           Name of class for Functionality            
---------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                     SinglyLLL             Done
Sinlgy Circular         SinglyCLLnode                     SinglyCLL             Done
Doubly Linear           DoublyLLLnode                     DoublyLLL             Done
Doubly Circular         DoublyCLLnode                     DoublyCLL             Done
Stack                   Stacknode                         Stack                 Done
Queue                   Queuenode                         Queue                 Done
---------------------------------------------------------------------------------------------
*/


#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
//      Singly Linear LinkedList using Generic approach..
/////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode 
{
    public:
        T data;
        SinglyLLLnode<T>* next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:       
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);           
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);

};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)           
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;
    
    this->iCount++;   
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)                
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        
    }
    this->iCount++;             
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL) 
    {
    return;
    }
    else if(this->first->next == NULL)             
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
    }
    this->iCount--;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;
    
    if(this->first == NULL) 
    {
    return;
    }
    else if(this->first->next == NULL)         
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input :         Data of node
//  Output :        LinkedList
//  Description :   Used to Display nodes of LinkedList 
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;
    
    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)      
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input :         Data of node
//  Output :        count of nodes
//  Description :   Used to Display Count of nodes  
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{

    return this->iCount;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;
            
        this->iCount--;
    }
}



////////////////////////////////////////////////////////////////////////////////
//      Doubly Linear LinkedList using Generic approach..
////////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();    
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"LinkedList gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;        
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }

}


//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)     
    {
        delete this->first;
        this->first = NULL;    
    }
    else                                   
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;    
    }
    else                                   
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input :         Data of node
//  Output :        LinkedList
//  Description :   Used to Display nodes of LinkedList 
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<"\nNULL";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input :         Data of node
//  Output :        count of nodes
//  Description :   Used to Display Count of nodes  
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//      Singly Circular LinkedList using Generic approach..
/////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class SinglyCLLnode
{
    public:
        T data;
        struct SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int );
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)   
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)   
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete this->last->next;

        this->last->next = this->first;
    }
    this->iCount--;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp -> next != this->last)
        {
            temp = temp -> next;
        }

        delete this->last;
        this->last = temp;

        this->last->next = this->first;
    }
    this->iCount--;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input :         Data of node
//  Output :        LinkedList
//  Description :   Used to Display nodes of LinkedList 
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////


template <class T>
void SinglyCLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> * temp = NULL;

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input :         Data of node
//  Output :        count of nodes
//  Description :   Used to Display Count of nodes  
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}



///////////////////////////////////////////////////////////////////////////////
//      Doubly Circular LinkedList using Generic approach..
///////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> * next;
        DoublyCLLnode<T> * prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    this->iCount++;
    
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = this->first;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to delete node of first position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteFirst()
{

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->last->next = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of last position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last;

        this->iCount--;
    }
} 


//////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input :         Data of node
//  Output :        LinkedList
//  Description :   Used to Display nodes of LinkedList 
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>:: Display()
{
    DoublyCLLnode<T> * temp = NULL;

    temp = this->first;
    do
    {
        cout<<" | "<<temp->data<<" | <=> ";
        temp = temp->next;
    } while(temp != last->next);
    cout<<"\n";
    
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input :         Data of node
//  Output :        count of nodes
//  Description :   Used to Display Count of nodes  
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T>:: Count()
{

    return iCount;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Insert node at given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> * newn = NULL;
    DoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if( pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1;iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Delete node of given position
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}


//////////////////////////////////////////////////////////////////
//      Stack using Generic approach..
//////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();
        void push(T);    
        T pop();        
        T peep();
        void Display();
        int Count();        
};

template <class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created successfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : push()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to insert node data.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;

}

//////////////////////////////////////////////////////////////////
//
//  Function Name : pop()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to delete node.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"stack is empty..\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : peep()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to display deleted node data.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: peep()
{
    T Value = 0;
    
    if(this->first == NULL)
    {
        cout<<"stack is empty..\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : Display()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Display stack.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(temp == NULL)
    {
        cout<<"Stack is empty..\n";
        return;
    }

    while(temp != NULL)
    {   
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
    
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : Count()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to count node of the stack.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}


//////////////////////////////////////////////////////////////////
//      Queue using Generic approach..
//////////////////////////////////////////////////////////////////


#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();
        void enqueue(T);    
        T dequeue();       
        void Display();
        int Count();        
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully...\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : enqueue()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to insert node int the queue.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : dequeue()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to delete node of the queue.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty..\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Display()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to Display the queue.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty..\n";
        return;
    }

    while(temp != NULL)
    {   
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";    
}


//////////////////////////////////////////////////////////////////
//
//  Function Name : Count()
//  Input :         Data of node
//  Output :        Nothing
//  Description :   Used to count the nodes of the queue.
//  Auther :        Digvijay Gokul Surywanshi
//  Date :          06/01/2026
//
//////////////////////////////////////////////////////////////////

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}


///////////////////////////////////////  End of Library  //////////////////////////////////////////////

int main()
{
    SinglyLLL<int> * obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj->DeleteFirst();
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";
    
    obj->DeleteLast();
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";
    
    obj->InsertAtPos(105, 4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj->DeleteAtPos(4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n\n";

    delete obj;

//////////////////////// Doubly Linear ////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Numbers of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Numbers of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Numbers of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Numbers of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$', 4);
    dobj->Display();
    cout<<"Numbers of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Numbers of elements are : "<<dobj->Count()<<"\n\n";

    delete dobj;

/////////////////////////////// Singly Circular ////////////////////////////////////////////////////////


    SinglyCLL<int> *sobj = new SinglyCLL<int>();

    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->InsertLast(101);
    sobj->InsertLast(111);
    sobj->InsertLast(121);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->DeleteFirst();
    sobj->Display(); 
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->DeleteLast();
    sobj->Display(); 
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->InsertAtPos(105,4);
    sobj->Display(); 
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->DeleteAtPos(4);
    sobj->Display();  
    cout<<"Number of elements are : "<<sobj->Count()<<"\n\n";

    delete sobj;

/////////////////////// Doubly Circular ////////////////////////////////////////////////////////////////// 


    DoublyCLL<int> *obj1 = new DoublyCLL<int>();

    obj1->InsertFirst(51);
    obj1->InsertFirst(21);
    obj1->InsertFirst(11);

    obj1->Display();
    cout<<"Number of nodes are: "<<obj1->Count()<<"\n";

    obj1->InsertLast(101);
    obj1->InsertLast(111);
    obj1->InsertLast(121);
    obj1->Display();
    cout<<"Number of nodes are: "<<obj1->Count()<<"\n";

    obj1->DeleteFirst();
    obj1->Display();
    cout<<"Number of nodes are: "<<obj1->Count()<<"\n";
    
    obj1->DeleteLast();
    obj1->Display();
    cout<<"Number of nodes are: "<<obj1->Count()<<"\n";
    
    obj1->InsertAtPos(105, 4);
    obj1->Display();
    cout<<"Number of nodes are: "<<obj1->Count()<<"\n";

    obj1->DeleteAtPos(4);
    obj1->Display();
    cout<<"Number of nodes are: "<<obj1->Count()<<"\n\n";

    delete obj1;


    ///////////////////////     Stack   ////////////////////////////////////////////////////////////////

    Stack<char> *sobj1 = new Stack<char>();
    sobj1->push('a');
    sobj1->push('b');
    sobj1->push('c');
    sobj1->push('d');

    sobj1->Display();
    cout<<"Number of elements in Stack are : "<<sobj1->Count()<<"\n";

    cout<<"Return value of peep is : "<<sobj1->peep()<<"\n";
    sobj1->Display();
    cout<<"Number of elements in Stack are : "<<sobj1->Count()<<"\n";

    cout<<"Poped element is : "<<sobj1->pop()<<"\n";
    sobj1->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj1->pop()<<"\n";
    sobj1->Display();
    cout<<"Number of elements in Stack are : "<<sobj1->Count()<<"\n";

    sobj1->push('e');
    sobj1->Display();
    cout<<"Number of elements in Stack are : "<<sobj1->Count()<<"\n";

    delete sobj1;

    //////////////////////      Queue   //////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();
    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}