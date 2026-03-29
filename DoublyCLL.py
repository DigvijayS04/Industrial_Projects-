# Final code of Doubly Circular Linked List 

class Node:
    def __init__(self,value):
        self.data = value
        self.next = None
        self.prev = None

class DoublyCLL:
    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    def InsertFirst(self, no):
        newn = Node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = self.first

        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

        self.last.next = self.first
        self.first.prev = self.last

        self.iCount = self.iCount + 1

    def InsertLast(self,no):
        newn = Node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = self.first
        else:
            self.last.next = newn
            newn.prev = self.last
            self.last = newn
            
        self.last.next = self.first
        self.first.prev = self.last

        self.iCount = self.iCount + 1

    def InsertAtPos(self, no, pos):
        
        if(pos < 1 or pos > (self.iCount + 1)):
            print("Invalid position")
            return
        
        if(pos == 1):
            self.InsertFirst(no)
            return
        
        elif(pos == (self.iCount + 1)):
            self.InsertLast(no)
            return

        else:
            newn = Node(no)
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next
            
            newn.next = temp.next
            newn.next.prev = newn

            temp.next = newn
            newn.prev = temp

            self.iCount = self.iCount + 1               

    def DeleteFirst(self):
        if(self.first == None and self.last == None):
            return

        if(self.first == self.last):
            del self.first 
            self.first = None
            self.last = None

        else:
            temp = self.first
            self.first = self.first.next

            del temp

            self.last.next = self.first
            self.first.prev = self.last

        self.iCount = self.iCount - 1
        

    def DeleteLast(self):
        if(self.first == None and self.last == None):
            return

        if(self.first == self.last):
            del self.first 
            self.first = None
            self.last = None

        else:

            self.last = self.last.prev
            del self.last.next

            self.last.next = self.first
            self.first.prev = self.last

        self.iCount = self.iCount - 1

    def DeleteAtPos(self, pos):
        if(pos < 1 or pos > self.iCount):
            print("Invalid position")
            return
        
        if(pos == 1):
            self.DeleteFirst(no)
            return
        
        elif(pos == self.iCount):
            self.DeleteLast(no)
            return

        else:
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next

            temp.next = temp.next.next
            temp.next.prev = temp
        
            self.iCount = self.iCount - 1


    def Display(self):
        temp = self.first

        while True:
            print("|",temp.data,"|->",end = " ")
            temp = temp.next
            if temp == self.last.next:
                break

        print("")

    def Count(self):
        return self.iCount

def main():
    dobj1 = DoublyCLL()

    dobj1.InsertFirst(51)
    dobj1.InsertFirst(21)
    dobj1.InsertFirst(11)

    print("Elements of List are: ")
    dobj1.Display()

    print("Number of elements in linkedlist are : ",dobj1.Count())

    dobj1.InsertLast(101)
    dobj1.InsertLast(111)
    print("Elements of List are: ")
    dobj1.Display()

    print("Number of elements in linkedlist are : ",dobj1.Count())

    dobj1.InsertAtPos(71,4)
    print("Elements of List are: ")
    dobj1.Display()

    print("Number of elements in linkedlist are : ",dobj1.Count())

    dobj1.DeleteFirst()
    print("Elements of List are: ")
    dobj1.Display()

    print("Number of elements in linkedlist are : ",dobj1.Count())

    dobj1.DeleteLast()
    print("Elements of List are: ")
    dobj1.Display()

    print("Number of elements in linkedlist are : ",dobj1.Count())

    dobj1.DeleteAtPos(3)
    print("Elements of List are: ")
    dobj1.Display()

    print("Number of elements in linkedlist are : ",dobj1.Count())
    
    



if __name__ == "__main__":
    main()
