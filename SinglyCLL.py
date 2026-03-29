# Final code of Singly Circular Linked List 

class Node:
    def __init__(self,value):
        self.data = value
        self.next = None

class SinglyCll:
    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    def InsertFirst(self, no):
        newn = Node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn

            self.last.next = self.first
        else:
            newn.next = self.first
            self.first = newn

            self.last.next = self.first

        self.iCount = self.iCount + 1

    def InsertLast(self,no):
        newn = Node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn

            self.last.next = self.first
        else:
            self.last.next = newn

            self.last = newn

            self.last.next = self.first

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
            temp.next = newn

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

        self.iCount = self.iCount - 1
        

    def DeleteLast(self):
        if(self.first == None and self.last == None):
            return

        if(self.first == self.last):
            del self.first 
            self.first = None
            self.last = None

        else:
            temp = self.first

            while(temp.next != self.last):
                temp = temp.next

            del self.last
            self.last = temp

            self.last.next = self.first

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
    sobj1 = SinglyCll()

    sobj1.InsertFirst(51)
    sobj1.InsertFirst(21)
    sobj1.InsertFirst(11)

    print("Elements of List are: ")
    sobj1.Display()

    print("Number of elements in linkedlist are : ",sobj1.Count())

    sobj1.InsertLast(101)
    sobj1.InsertLast(111)
    print("Elements of List are: ")
    sobj1.Display()

    print("Number of elements in linkedlist are : ",sobj1.Count())

    sobj1.InsertAtPos(71,4)
    print("Elements of List are: ")
    sobj1.Display()

    print("Number of elements in linkedlist are : ",sobj1.Count())

    sobj1.DeleteFirst()
    print("Elements of List are: ")
    sobj1.Display()

    print("Number of elements in linkedlist are : ",sobj1.Count())

    sobj1.DeleteLast()
    print("Elements of List are: ")
    sobj1.Display()

    print("Number of elements in linkedlist are : ",sobj1.Count())

    sobj1.DeleteAtPos(3)
    print("Elements of List are: ")
    sobj1.Display()

    print("Number of elements in linkedlist are : ",sobj1.Count())
    
    



if __name__ == "__main__":
    main()
